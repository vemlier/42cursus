#include "Command.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

KickCommand::KickCommand(Server* server) : ACommand(server) {}

KickCommand::~KickCommand() {}

bool KickCommand::execute(Client *client, std::vector<std::string> arguments) {
  Channel* clientChannel = client->getChannel();
  Channel* targetChannel = _server->getChannel(arguments[0]);
  std::string	tmp("");
	size_t		num = 0;

  if (!targetChannel) {
    client->reply(
      _server->getServerName(),
      ERR_NOSUCHCHANNEL(client->getNickname(), arguments[0])
      );
    return true;
  }
  if (!clientChannel || (clientChannel != targetChannel)) {
    client->reply(
      _server->getServerName(),
      ERR_NOTONCHANNEL(client->getNickname(), arguments[0])
      );
    return true;
  }

  Client* targetClient = _server->getClient(arguments[1]);

  if (!targetClient || targetClient->getChannel() != targetChannel) {
    client->reply(
      _server->getServerName(),
      ERR_NOSUCHNICK(client->getNickname(), arguments[1])
      );
    return true;
  }
  if (client != targetChannel->getAdmin()) {
    client->reply(
      _server->getServerName(),
      ERR_CHANOPRIVSNEEDED(client->getNickname(), arguments[0])
      );
    return true;
  }
  if (arguments.size() < 3 || arguments[2].at(0) != ':') {
    client->reply(
      _server->getServerName(),
      ERR_NEEDMOREPARAMS(client->getNickname(), "KICK")
      );
    return true;
  }

	while (1)
	{
		tmp += arguments[2 + num];
		if (arguments.size() == 3 + num)
			break ;
		++num;
		tmp += std::string(" ");
	}

  targetChannel->broadcast(RPL_KICK(client->getPrefix(), targetChannel->getName(), targetClient->getNickname(), tmp), NULL);
  targetClient->setChannel(NULL);
  targetChannel->removeClient(targetClient);
  return true;
}
