#include <iostream>
#include <unistd.h>

#include "Client.hpp"
#include "Channel.hpp"
#include "Command.hpp"
#include "NumericReplies.hpp"

PartCommand::PartCommand(Server *server) : ACommand(server)
{
}

PartCommand::~PartCommand()
{
}

bool PartCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() == ALL)
	{
		if (arguments.empty())
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PART"));
			return true;
		}

		std::string name = arguments[0];
		Channel *channel = _server->getChannel(name);

		if (!channel)
		{
			client->reply(ERR_NOSUCHCHANNEL(client->getNickname(), name));
			return true;
		}

		if (!client->getChannel() || client->getChannel()->getName() != name)
		{
			client->reply(ERR_NOTONCHANNEL(client->getNickname(), name));
			return true;
		}
		channel->broadcast(RPL_PART(client->getPrefix(), channel->getName()), client);
		client->reply(RPL_PART(client->getPrefix(), channel->getName()));
		if (channel->removeClient(client) == 1)
			_server->removeChannel(channel);
	}
	return true;
}