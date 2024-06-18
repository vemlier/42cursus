#include <iostream>
#include "Channel.hpp"
#include "Client.hpp"

#include <algorithm>

Channel::Channel(const std::string &name, const std::string &password, Client *admin) : _name(name), _password(password), _admin(admin)
{
}

Channel::~Channel()
{
}

Client *Channel::getAdmin() const
{
	return (_admin);
}

const std::string Channel::getName() const
{
	return (_name);
}

const std::string Channel::getPassword() const
{
	return (_password);
}

std::vector<std::string> Channel::getNicknames()
{
	std::vector<std::string> nicknames;

	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		Client *client = it.operator*();
		nicknames.push_back((_admin == client ? "@" : "") + (*it)->getNickname());
	}

	return nicknames;
}

void Channel::addClient(Client *client)
{
	_clients.push_back(client);
}

void Channel::broadcast(std::string msg)
{
	std::string str = "PRIVMSG " + _name + " " + msg + "\r\n";
	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++)
		(*it)->writeToSocket(str);
}

void Channel::broadcast(const std::string &message, Client *exclude)
{
	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++)
	{

		if (*it == exclude)
			continue;

		(*it)->writeToSocket(message);
	}
}

int Channel::removeClient(Client *client)
{

	_clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
	client->setChannel(NULL);
	if (_clients.empty())
	{	
		return (1);
	}
	if (_admin == client)
		_admin = NULL;
	return (0);
}

void Channel::kick(Client *client, Client *target, const std::string &reason)
{
	if (client == _admin)
	{
		removeClient(target);
		std::string msg = client->getNickname() + " kicked " + target->getNickname() + reason;
		broadcast(msg);
	}
}