#include <iostream>

#include "Command.hpp"
#include "Client.hpp"
#include "NumericReplies.hpp"

PassCommand::PassCommand(Server *server) : ACommand(server)
{
}

PassCommand::~PassCommand()
{
}

bool PassCommand::execute(Client *client, std::vector<std::string> arguments)
{
	if (client->getRegistered() != ALL)
	{
		if (arguments.empty())
		{
			client->reply(_server->getServerName(), ERR_NEEDMOREPARAMS(client->getNickname(), "PASS"));
			_server->disconnectClient(client->getSocket());
			return false;
		}
		else if ((client->getRegistered() & PASS) == PASS)
		{
			client->reply(_server->getServerName(), ERR_ALREADYREGISTRED);
			return true;
		}
		else
		{
			std::string	tmp("");
			size_t		num = 0;
					
			while (1)
			{
				tmp += arguments[num];
				if (arguments.size() == 1 + num)
					break ;
				++num;
				tmp += std::string(" ");
			}
			if (_server->getPassword() != tmp)
			{
				_server->disconnectClient(client->getSocket());
				return false;
			}
			client->setRegistered(PASS);
		}
	}
	return true;
}
