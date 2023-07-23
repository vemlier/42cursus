#include "CommandHandler.hpp"
#include "Command.hpp"
#include "Server.hpp"
#include "Client.hpp"

#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <unistd.h>

CommandHandler::CommandHandler(Server *server) : _server(server)
{
	_commands["JOIN"] = new JoinCommand(_server);
	_commands["PART"] = new PartCommand(_server);
	_commands["PRIVMSG"] = new PrivMsgCommand(_server);
	_commands["PONG"] = new PongCommand(_server);
	_commands["PING"] = new PingCommand(_server);
	_commands["USER"] = new UserCommand(_server);
	_commands["NICK"] = new NickCommand(_server);
	_commands["MODE"] = new ModeCommand(_server);
	_commands["PASS"] = new PassCommand(_server);
	_commands["KICK"] = new KickCommand(_server);
	_commands["QUIT"] = new QuitCommand(_server);
	_commands["NOTICE"] = new NoticeCommand(_server);
}

CommandHandler::~CommandHandler()
{
	for (std::map<std::string, ACommand *>::iterator it = _commands.begin(); it != _commands.end(); it++)
		delete it->second;
}

void CommandHandler::invoke(Client *client)
{
	std::string str = client->getMessage();
	std::string cmd;
	std::string separator = " ";

	while (str.find("\r\n") != std::string::npos)
	{
		std::vector<std::string> arguments;
		std::string tmp(str.begin(), str.begin() + str.find("\r\n"));
		int cur_position = 0;
		size_t position;
		int cmd_flag = 0;

		//msg parsing
		str.erase(str.begin(), str.begin() + str.find("\r\n") + 2);
		while ((position = tmp.find(separator, cur_position)) != std::string::npos)
		{
			int len = position - cur_position;
			if (cmd_flag == 0)
			{
				cmd = tmp.substr(cur_position, len);
				cmd_flag = 1;
			}
			else
				arguments.push_back(tmp.substr(cur_position, len));
			cur_position = position + 1;
		}
		if (cmd_flag == 0)
		{
			cmd = tmp.substr(cur_position);
			cmd_flag = 1;
		}
		else
			arguments.push_back(tmp.substr(cur_position));
		// msg parsing

		// execute command
		if (_commands.find(cmd) != _commands.end())
			if (_commands[cmd]->execute(client, arguments) == false)
				break ;
		client->setMessage("");
	}
}
