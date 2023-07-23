#include <iostream>

#include "Command.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

PongCommand::PongCommand(Server *server) : ACommand(server)
{
}

PongCommand::~PongCommand()
{
}

bool PongCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() == ALL)
	{
		if (arguments.empty())
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PONG"));
			return true;
		}
		client->reply(RPL_PING(client->getPrefix(), arguments.at(0)));
	}
	return true;
}