#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <vector>
#include <iostream>
#include "Server.hpp"
#include "Client.hpp"

class Server;
class Client;

class ACommand
{
protected:
	Server *_server;
	bool _author;

public:
	ACommand(Server *server, bool author = true) : _server(server), _author(author){};
	virtual ~ACommand(){};

	bool authRequired() const { return _author; };
	virtual bool execute(Client *client, std::vector<std::string> arguments) = 0;
};

class JoinCommand : public ACommand
{
public:
	JoinCommand(Server *server);
	~JoinCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class NickCommand : public ACommand
{
private:
	bool isSpecial(char c) const;
	bool isNoNickname(const std::string& nick) const;
	bool isErroneus(const char* nick) const;
	bool isDuplicated(const std::string& nick) const;

public:
	NickCommand(Server *server);
	~NickCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class PartCommand : public ACommand
{

public:
	PartCommand(Server *server);
	~PartCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class PrivMsgCommand : public ACommand
{
public:
	PrivMsgCommand(Server *server);
	~PrivMsgCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class PongCommand : public ACommand
{
public:
	PongCommand(Server *server);
	~PongCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class PingCommand : public ACommand
{
public:
	PingCommand(Server *server);
	~PingCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class UserCommand : public ACommand
{
public:
	UserCommand(Server *server);
	~UserCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class ModeCommand : public ACommand
{
public:
	ModeCommand(Server *server);
	~ModeCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class KickCommand : public ACommand
{
public:
	KickCommand(Server *server);
	~KickCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class QuitCommand : public ACommand
{
public:
	QuitCommand(Server *server);
	~QuitCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class PassCommand : public ACommand
{
public:
	PassCommand(Server *server);
	~PassCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};

class NoticeCommand : public ACommand
{
public:
	NoticeCommand(Server *server);
	~NoticeCommand();

	bool execute(Client *client, std::vector<std::string> arguments);
};


#endif
