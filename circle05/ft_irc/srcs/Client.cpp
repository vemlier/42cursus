#include "Client.hpp"
#include "Channel.hpp"
#include "NumericReplies.hpp"

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

#define CYN "\e[0;36m"
#define NC "\e[0m"

Client::Client() : _socket(0), _registered(0), _message(""), _nickname(""), _username(""), _hostname(""), _host(""), _realname(""), _buffer(""), _channel(NULL)
{
	std::cerr << "Invalid way to call constructor" << std::endl;
}

Client::Client(int socketNum) : _socket(socketNum), _registered(0), _message(""), _nickname(""), _username(""), _hostname(""), _host(""), _realname(""), _buffer(""), _channel(NULL)
{
}

Client::~Client()
{
}

/* getter && setter */

int Client::getSocket(void) const
{
	return (_socket);
}

void Client::setMessage(std::string msg)
{
	_message = msg;
}

const std::string &Client::getMessage() const
{
	return (_message);
}

void Client::setNickname(std::string msg)
{
	_nickname = msg;
}

const std::string &Client::getNickname() const
{
	return (_nickname);
}

void Client::setUsername(std::string msg)
{
	_username = msg;
}

const std::string &Client::getUsername() const
{
	return (_username);
}

void Client::setHostname(std::string msg)
{
	_hostname = msg;
}

const std::string &Client::getHostname() const
{
	return (_nickname);
}

void Client::setHost(std::string msg)
{
	_host = msg;
}

const std::string &Client::getHost() const
{
	return (_host);
}

void Client::setRealname(std::string msg)
{
	_realname = msg;
}

const std::string &Client::getRealname() const
{
	return (_realname);
}

void Client::setChannel(Channel *channel)
{
	_channel = channel;
}

Channel *Client::getChannel()
{
	return (_channel);
}

const std::string Client::getPrefix() const
{
	return (_nickname + "!" + _username + "@" + _host);
}

/* member function */

void Client::join(Channel *channel)
{
	channel->addClient(this);
	_channel = channel;

	std::string users;
	std::vector<std::string> nicknames = channel->getNicknames();
	for (std::vector<std::string>::iterator it = nicknames.begin(); it != nicknames.end(); it++)
		users.append(*it + " ");
	reply(RPL_NAMREPLY(_nickname, channel->getName(), users));
	reply(RPL_ENDOFNAMES(_nickname, channel->getName()));
	reply(RPL_JOIN(getPrefix(), channel->getName()));
	channel->broadcast(RPL_JOIN(getPrefix(), channel->getName()), this);
}

int Client::writeToSocket(const std::string msg) const
{
	if (write(_socket, msg.c_str(), msg.size()) == -1)
	{
		std::cerr << "client write error!" << std::endl;
		return (1);
	}
	return (0);
}

void Client::reply(const std::string &reply) const
{
	writeToSocket(reply);
	std::cout << CYN "<-" NC << reply << std::endl;
}

void Client::reply(const std::string &from, const std::string &reply) const
{
	writeToSocket(":" + from + " " + reply);
}

void	Client::setRegistered(int regFlag)
{
	this->_registered |= regFlag;
}

const int&	Client::getRegistered(void) const
{
	return (this->_registered);
}

void Client::setBuffer(std::string msg)
{
	_buffer = msg;
}
const std::string& Client::getBuffer() const
{
	return (_buffer);
}
void Client::addBuffer(std::string msg)
{
	_buffer += msg;
}

std::ostream &operator<<(std::ostream &o, const Client &rhs)
{
	o << "---Client profile---" << std::endl
	  << "socket : " << rhs.getSocket() << "\nMessage : " << rhs.getMessage() << "\nChannel : "
	  << "\n---Client---" << std::endl;

	return (o);
}

