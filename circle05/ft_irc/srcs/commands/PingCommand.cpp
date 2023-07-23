#include <iostream>

#include "Command.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

PingCommand::PingCommand(Server *server) : ACommand(server)
{
}

PingCommand::~PingCommand()
{
}

bool PingCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() == ALL)
	{
		if (arguments.empty())
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PING"));
			return true;
		}
		client->reply(RPL_PING(client->getPrefix(), arguments.at(0)));
	}
	return true;
}