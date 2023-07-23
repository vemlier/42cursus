#include "Command.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "NumericReplies.hpp"

QuitCommand::QuitCommand(Server *server) : ACommand(server)
{
}

QuitCommand::~QuitCommand()
{
}

bool QuitCommand::execute(Client *client, std::vector<std::string> arguments)
{
	std::string reason = arguments.empty() ? "Leaving..." : arguments.at(0);
	reason = reason.at(0) == ':' ? reason.substr(1) : reason;
	if (client->getChannel() != NULL)
	{
		Channel *channel = client->getChannel();
		channel->broadcast(RPL_QUIT(client->getPrefix(), reason), client);
		if (channel->removeClient(client) == 1)
			_server->removeChannel(channel);
	}
	client->reply(RPL_QUIT(client->getPrefix(), reason));
	_server->disconnectClient(client->getSocket());
	return false;
}