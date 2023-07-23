#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <string>
#include <map>

class Server;
class Client;
class ACommand;

class CommandHandler
{

private:
	Server *_server;
	std::map<std::string, ACommand *> _commands;

public:
	CommandHandler(Server *server);
	~CommandHandler();
	void invoke(Client *client);
};

#endif
