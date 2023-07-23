#ifndef BOT_HPP
#define BOT_HPP

#include <iostream>
#include <sys/event.h>
#include <arpa/inet.h>

class Bot
{
private:
	int _portNum;
	int _socket;
	std::string _host;
	std::string _password;
	struct sockaddr_in _address;

	std::string parse(std::string message);
	std::string getGreeting(const std::string& message) const;
	std::string getCountryList(void) const;

public:
	Bot(std::string host, int port, std::string password);
	~Bot();

	void start();
	void execute(const std::string& command) const;
	void exit_with_perror(const std::string &msg);

};

#endif