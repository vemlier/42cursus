#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "CommandHandler.hpp"

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <cerrno>
#include <cstdlib>
#include <algorithm>

#define GRN "\e[0;32m"
#define NC "\e[0m"

Server::Server(int port, std::string password) : _portNum(port), _password(password), _servername("ft_irc"), _version("1.0")
{
	if ((_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		exit_with_perror("socket() error\n" + std::string(strerror(errno)));
	std::memset(&_address, 0, sizeof(_address));

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = htonl(INADDR_ANY);
	_address.sin_port = htons(_portNum);

	_commandHandler = new CommandHandler(this);

	if (bind(_socket, (struct sockaddr *)&_address, sizeof(_address)) == -1)
		exit_with_perror("bind error\n" + std::string(strerror(errno)));

	if (listen(_socket, SOMAXCONN) == -1)
		exit_with_perror("listen error\n" + std::string(strerror(errno)));

	if (fcntl(_socket, F_SETFL, O_NONBLOCK) == -1)
		exit_with_perror("fcntl error\n");
}

Server::~Server()
{
	delete _commandHandler;
}

const std::string &Server::getServerName(void) const
{
	return _servername;
}

void Server::start()
{
	int kq;
	if ((kq = kqueue()) == -1)
		exit_with_perror("kqueue() error\n" + std::string(strerror(errno)));

	/* add event for server socket */
	changeEvents(_changeList, _socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	std::cout << "Server starts..." << std::endl;

	/* main loop */
	int new_events;
	while (1)
	{
		/*  apply changes and return new events(pending events) */
		new_events = kevent(kq, &_changeList[0], _changeList.size(), _eventList, 8, NULL);
		if (new_events == -1)
			exit_with_perror("kevent() error\n" + std::string(strerror(errno)));

		_changeList.clear(); // clear _changeList for new changes

		for (int i = 0; i < new_events; ++i)
		{
			_currEvent = &_eventList[i];

			/* check error event return */
			std::map<int, Client *>::iterator it = _clients.find(_currEvent->ident);
            if (it != _clients.end() || static_cast<int>(_currEvent->ident) == _socket)
			{
				if (_currEvent->flags & EV_ERROR)
				{
					if (static_cast<int>(_currEvent->ident) == _socket)
						exit_with_perror("server socket error");
					else
					{
						std::cerr << "client socket error" << std::endl;
						disconnectClient(_currEvent->ident);
					}
				}
				else if (_currEvent->filter == EVFILT_READ)
				{
					if (static_cast<int>(_currEvent->ident) == _socket)
					{
						acceptNewClient();
					}
					else
					{
						readDataFromClient();
					}
				}
				else if (_currEvent->filter == EVFILT_WRITE)
				{
					if (_clients[_currEvent->ident]->getMessage() != "")
						_commandHandler->invoke(_clients[_currEvent->ident]);
				
				}
			}
		}
	}
}

void Server::exit_with_perror(const std::string &msg)
{
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

void Server::changeEvents(std::vector<struct kevent> &_changeList, uintptr_t ident, int16_t filter,
						  uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
{
	struct kevent temp_event;

	EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
	_changeList.push_back(temp_event);
}

void Server::acceptNewClient()
{
	/* accept new client */
	int clientSocket;
	struct sockaddr_in clientAddress;
	socklen_t clientAddrLen = sizeof(clientAddress);

	if ((clientSocket = accept(_socket, (struct sockaddr *)&clientAddress, &clientAddrLen)) == -1)
		exit_with_perror("accept() error\n" + std::string(strerror(errno)));
	std::cout << "Client[" << inet_ntoa(clientAddress.sin_addr) << ": " << ntohs(clientAddress.sin_port) << "]: " << clientSocket << " has been connected" << std::endl << std::endl;
	if (fcntl(_socket, F_SETFL, O_NONBLOCK) == -1)
		exit_with_perror("fcntl error\n");

	/* add event for client socket - add read && write event */
	changeEvents(_changeList, clientSocket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	changeEvents(_changeList, clientSocket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	_clients[clientSocket] = new Client(clientSocket);
}

void Server::readDataFromClient()
{
	/* read data from client */
	char buf[1024];
	memset(buf, 0, 1024);
	int n = read(_currEvent->ident, buf, sizeof(buf));
	_clients[_currEvent->ident]->addBuffer(std::string(buf));

	if (_clients.find(_currEvent->ident) == _clients.end())
		return ;
	if (n <= 0)
	{
		if (n < 0)
			std::cerr << "client read error!" << std::endl;
		disconnectClient(_currEvent->ident);
	}
	else if ((_clients[_currEvent->ident]->getBuffer()).find("\r\n") == std::string::npos)
		return ;
	else
	{
		if (_clients[_currEvent->ident]->getBuffer() == "\r\n")
		{
			_clients[_currEvent->ident]->setBuffer("");
			return ;
		}
		_clients[_currEvent->ident]->setMessage(_clients[_currEvent->ident]->getBuffer());
		_clients[_currEvent->ident]->setBuffer("");
		std::cout << GRN "[" << _currEvent->ident << "]->" NC << _clients[_currEvent->ident]->getMessage() << "\n";
	}
}

void Server::disconnectClient(int client_fd)
{
	if (_clients.find(_currEvent->ident) == _clients.end())
		return ;
	Client* client = _clients[client_fd];
	Channel* channel = client->getChannel();
	if (channel != NULL)
	{
		if (channel->removeClient(client) == 1)
			removeChannel(channel);
	}
	std::cout << "client disconnected: " << client_fd << std::endl;
	delete _clients[client_fd];
	close(client_fd);
	_clients.erase(client_fd);
}

Client *Server::getClient(const std::string &nickname)
{
	for (std::map<int, Client *>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if (!nickname.compare(it->second->getNickname()))
			return it->second;
	}
	return NULL;
}

Channel *Server::createChannel(const std::string &name, const std::string &password, Client *client)
{
	Channel *channel = new Channel(name, password, client);
	_channels.push_back(channel);
	return (channel);
}

Channel *Server::getChannel(const std::string &name)
{
	for (channels_iterator it = _channels.begin(); it != _channels.end(); it++)
		if (it.operator*()->getName() == name)
			return (it.operator*());
	return (NULL);
}

void  Server::removeChannel(Channel *channel)
{
	_channels.erase(remove(_channels.begin(), _channels.end(), channel), _channels.end());
	delete channel;
}

const std::string&	Server::getVersion(void) const
{
	return this->_version;
}

void Server::setServername(std::string server)
{
	this->_servername = server;
}

void Server::setVersion(std::string version)
{
	this->_version = version;
}

const std::string&	Server::getPassword(void) const
{
	return this->_password;
}
