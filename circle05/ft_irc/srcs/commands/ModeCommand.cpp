#include <iostream>
#include <unistd.h>
#include <string>

#include "Command.hpp"
#include "NumericReplies.hpp"

ModeCommand::ModeCommand(Server *server) : ACommand(server)
{
}

ModeCommand::~ModeCommand()
{
}

bool ModeCommand::execute(Client *client, std::vector<std::string> arguments)
{
  (void)arguments;
	if (client->getRegistered() == ALL)
	{
		client->reply(ERR_UMODEUNKNOWNFLAG(client->getNickname()));
	}
	return true;
}
