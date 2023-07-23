#include <iostream>
#include <unistd.h>

#include "Server.hpp"
#include "Command.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "NumericReplies.hpp"

PrivMsgCommand::PrivMsgCommand(Server *server) : ACommand(server)
{
}

PrivMsgCommand::~PrivMsgCommand()
{
}

bool PrivMsgCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() == ALL)
	{
		if (arguments.size() < 2 || arguments[0].empty() || arguments[1].empty())
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PRIVMSG"));
			return true;
		}

		std::string target = arguments.at(0);
		std::string message;

		for (std::vector<std::string>::iterator it = arguments.begin() + 1; ; it++)
		{
			message.append(*it);
			if (it + 1 == arguments.end())
				break ;
			message.append(" ");
		}

		if (message.at(0) != ':')
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PRIVMSG"));
			return true;
		}
		message = message.substr(1);
		if (target.at(0) == '#')
		{
			Channel *channel = client->getChannel();
			if (!channel) 
			{
				client->reply(ERR_NOSUCHCHANNEL(client->getNickname(), target));
				return true;
			}
			channel->broadcast(RPL_PRIVMSG(client->getPrefix(), target, message), client);
			return true;
		}
		Client *dest = _server->getClient(target);
		if (!dest) 
		{
			client->reply(ERR_NOSUCHNICK(client->getNickname(), target));
			return true;
		}
		dest->writeToSocket(RPL_PRIVMSG(client->getPrefix(), target, message));
	}
	return true;
}