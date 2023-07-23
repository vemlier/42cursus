#include <iostream>
#include <unistd.h>
#include <string>

#include "Command.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

JoinCommand::JoinCommand(Server *server) : ACommand(server)
{
}

JoinCommand::~JoinCommand()
{
}

// channel msg = :<username>!<hostname>@<servername> PRIVMSG <channel> :<msg>\r\n

bool JoinCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() == ALL)
	{
		if (arguments.empty())
		{
			client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "JOIN"));
			return true;
		}
		if (arguments.at(0).at(0) != '#')
			return true;

		Channel *channel = client->getChannel();
		std::string name = arguments[0];
		std::string password = arguments.size() > 1 ? arguments[1] : "";

		if (channel)
		{
			client->reply(ERR_TOOMANYCHANNELS(client->getNickname(), name));
			return true;
		}
		channel = _server->getChannel(name);
		if (!channel)
		{
			channel = _server->createChannel(name, password, client);
		}
		if (channel->getPassword() != password)
		{
			client->reply(ERR_BADCHANNELKEY(client->getNickname(), name));

			return true;
		}
		client->join(channel);
	}
	return true;
}