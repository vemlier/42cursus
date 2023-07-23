#include <iostream>
#include <unistd.h>

#include "Client.hpp"
#include "Channel.hpp"
#include "Command.hpp"
#include "NumericReplies.hpp"

NoticeCommand::NoticeCommand(Server *server) : ACommand(server)
{
}

NoticeCommand::~NoticeCommand()
{
}

bool NoticeCommand::execute(Client *client, std::vector<std::string> arguments)
{

	if (arguments.size() < 2 || arguments[0].empty() || arguments[1].empty())
	{
		client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "NOTICE"));
		return true;
	}

	std::string target = arguments.at(0);
	std::string message;

	for (std::vector<std::string>::iterator it = arguments.begin() + 1; it != arguments.end(); it++)
	{
		message.append(*it + " ");
	}

	message = message.at(0) == ':' ? message.substr(1) : message;

	Client *dest = _server->getClient(target);
	if (!dest)
	{
		client->reply(ERR_NOSUCHNICK(client->getNickname(), target));
		return true;
	}
	if (dest->getChannel() != NULL)
	{
		client->reply(ERR_NOSUCHNICK(client->getNickname(), target));
		return true;
	}

	dest->reply(RPL_NOTICE(client->getPrefix(), target, message));
	return true;
}