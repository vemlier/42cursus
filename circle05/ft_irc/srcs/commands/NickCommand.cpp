#include <cstring>

#include "Command.hpp"
#include "Channel.hpp"
#include "NumericReplies.hpp"

NickCommand::NickCommand(Server* server) : ACommand(server) {}

NickCommand::~NickCommand() {}


bool NickCommand::execute(Client* client, std::vector<std::string> arguments) {
  std::string clientNick;
  if ((client->getRegistered() & NICK) != NICK) {
    clientNick = "*";
  }
  else {
    clientNick = client->getNickname();
  }
  if (arguments.empty()) {
    client->reply(
      _server->getServerName(),
      ERR_NEEDMOREPARAMS(clientNick, "NICK")
      );
    if ((client->getRegistered() & NICK) != NICK) {
      _server->disconnectClient(client->getSocket());
      return false;
    }
    return true;
  }
  if (isNoNickname(arguments[0])) {
    client->reply(
      _server->getServerName(),
      ERR_NONICKNAMEGIVEN(clientNick)
      );
    if ((client->getRegistered() & NICK) != NICK) {
      _server->disconnectClient(client->getSocket());
      return false;
    }
    return true;
  }
  if (isErroneus(arguments[0].c_str())) {
    client->reply(
      _server->getServerName(),
      ERR_ERRONEUSNICKNAME(clientNick, arguments[0])
      );
    if ((client->getRegistered() & NICK) != NICK) {
      _server->disconnectClient(client->getSocket());
      return false;
    }
    return true;
  }
  if (isDuplicated(arguments[0])) {
    client->reply(
      _server->getServerName(),
      ERR_NICKNAMEINUSE(clientNick, arguments[0])
      );
    if ((client->getRegistered() & NICK) != NICK) {
      _server->disconnectClient(client->getSocket());
      return false;
    }
    return true;
  }
  if ((client->getRegistered() & NICK) == NICK) {
    client->reply(RPL_NICK(client->getPrefix(), arguments[0]));
  }
  Channel* channel = client->getChannel();
  if (channel) {
    channel->broadcast(RPL_NICK(client->getPrefix(), arguments[0]), client);
  }
  if ((client->getRegistered() & NICK) != NICK) {
    client->setRegistered(NICK);
  }
  client->setNickname(arguments[0]);
  return true;
}


bool NickCommand::isNoNickname(const std::string& nick) const {
  if (nick.empty()) {
    return true;
  }
  return false;
}

bool NickCommand::isErroneus(const char* nick) const {
  if (strlen(nick) > 9) {
    return true;
  }
  if (!(std::isalpha(nick[0]) || isSpecial(nick[0]))) {
    return true;
  }
  for (unsigned long i = 1; i < strlen(nick); i++) {
    if (!(std::isalpha(nick[i]) || isSpecial(nick[i])
    || std::isdigit(nick[i]) || (nick[i] == '-'))) {
      return true;
    }
  }
  return false;
}

bool NickCommand::isDuplicated(const std::string& nick) const {
  if (_server->getClient(nick)) {
    return true;
  }
  return false;
}


bool NickCommand::isSpecial(char c) const {
  return (
    c == '-' || c == '[' || c == ']' || c == '\\'
    || c == '`' || c == '^' || c == '{' || c == '}'
    );
}
