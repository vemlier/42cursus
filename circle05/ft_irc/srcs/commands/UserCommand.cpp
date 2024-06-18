#include <iostream>
#include <unistd.h>
#include <time.h>
#include <cstring>

#include "Command.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

void	setArgument(Client *client, std::vector<std::string> &arguments, Server *_server)
{
	std::string	tmp("");
	size_t		num = 0;
			
	client->setUsername(arguments[0]);
	client->setHostname(arguments[1]);
	client->setHost(arguments[2]);
	while (1)
	{
		tmp += arguments[3 + num];
		if (arguments.size() == 4 + num)
			break ;
		++num;
		tmp += std::string(" ");
	}
	if (tmp.find(':') != std::string::npos)
		tmp.erase(tmp.find(':'), 1);
	else
		_server->disconnectClient(client->getSocket());
	client->setRealname(tmp);
}

void	sendInfo(Client *client, Server *_server)
{
	std::string welcome;
	std::string yourhost;
	std::string created;
	std::string rpl_myinfo;
	time_t		timer = time(NULL);
	struct tm*	_time = localtime(&timer);
	char		buffer[25];

	memset(buffer, 0, 25);
	strftime(buffer, 24, "%X %b %d %Y", _time);
	welcome = std::string("001 " + client->getNickname() + " Welcome to the Internet Relay Network " \
					+ client->getNickname() + "!" + client->getUsername() \
					+ "@" + client->getHost() + "\r\n");
	yourhost = std::string("002 " + client->getNickname() + " Your host is " + _server->getServerName() + ", running version " + _server->getVersion() + "\r\n");
	created = std::string("003 " + client->getNickname() + " This server was created " + std::string(buffer) + "\r\n");
	rpl_myinfo = std::string("004 " + client->getNickname() + " " + _server->getServerName() + " " + _server->getVersion() + " o o\r\n");
	client->reply(welcome);
	client->reply(yourhost);
	client->reply(created);
	client->reply(rpl_myinfo);
}

UserCommand::UserCommand(Server *server) : ACommand(server)
{
}

UserCommand::~UserCommand()
{
}

bool UserCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (((client->getRegistered() & PASS) == PASS) && ((client->getRegistered() & NICK) == NICK) && client->getRegistered() != ALL)
	{
		if (arguments.size() < 4)
		{
			client->reply(_server->getServerName(), ERR_NEEDMOREPARAMS(client->getNickname(), "USER"));
			_server->disconnectClient(client->getSocket());
			return false;
		}
		else if ((client->getRegistered() & USER) == USER)
		{
			client->reply(_server->getServerName(), ERR_ALREADYREGISTRED);
			return true;
		}
		else
		{
			setArgument(client, arguments, _server);
			client->setRegistered(USER);
			sendInfo(client, _server);
		}
	}
	return true;
}
