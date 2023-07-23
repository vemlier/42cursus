#include "bot.hpp"
#include "../../includes/Server.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

#define BUFSIZE 1024

Bot::Bot(std::string host, int port, std::string password) : _portNum(port), _host(host), _password(password)
{
	if ((_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		exit_with_perror("socket() error\n" + std::string(strerror(errno)));
	memset(&_address, 0, sizeof(_address));

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = inet_addr(_host.c_str());
	_address.sin_port = htons(_portNum);

	if (connect(_socket, (struct sockaddr *)&_address, sizeof(_address)) < 0)
		exit_with_perror("connect error\n" + std::string(strerror(errno)));
	else
		std::cout << "connected" << std::endl;

	std::string tmpPass("PASS " + _password + "\r\n");
	std::string tmpHost("USER bot bot " + _host + " :Bot" + "\r\n");
	write(_socket, tmpPass.c_str(), tmpPass.size());
	write(_socket, "NICK Bot\r\n", 10);
	write(_socket, tmpHost.c_str(), tmpHost.size());
}

Bot::~Bot()
{
}

void Bot::start()
{ 
	char message[BUFSIZE];
	int str_len;
	std::cout << "start!\n";
	write(_socket, "JOIN #helloBot\r\n", 16);
	while (1)
	{
		std::memset(message, 0, 1024);
		str_len = read(_socket, message, BUFSIZE - 1);
		if (str_len > 0)
		{
			std::string command = parse(message);
			execute(command);
		}
		else
			return ;
	}
	std::memset(message, 0, 1024);
}

std::string Bot::parse(std::string message)
{
	std::cout << "[Message from server]: " << message;
	message.erase(message.begin());
	message.erase(message.begin(), message.begin() + message.find(":") + 1);

	while (std::isspace(*(message.begin())))
		message.erase(message.begin());
	while (std::isspace(*(message.end() - 1)))
		message.erase(message.end() - 1);
	if (message.find(" ") != std::string::npos)
		return (std::string("TooManyArg"));
	return message;
}

void Bot::execute(const std::string& command) const
{
	std::string reply;

	if (command.compare("help") == 0) {
		reply = getCountryList();
	}
	else if (command.compare("ARE") == 0 || command.compare("Arab") == 0) {
		reply = getGreeting("أسلام عليكم");
	}
	else if (command.compare("BRA") == 0 || command.compare("Brazil") == 0) {
		reply = getGreeting("olá");
	}
	else if (command.compare("CHN") == 0 || command.compare("China") == 0) {
		reply = getGreeting("你好");
	}
	else if (command.compare("DEU") == 0 || command.compare("Germany") == 0) {
		reply = getGreeting("guten tag");
	}
	else if (command.compare("ESP") == 0 || command.compare("Spain") == 0) {
		reply = getGreeting("hola");
	}
	else if (command.compare("FRA") == 0 || command.compare("France") == 0) {
		reply = getGreeting("bonjour");
	}
	else if (command.compare("ITA") == 0 || command.compare("Italy") == 0) {
		reply = getGreeting("ciao");
	}
	else if (command.compare("JPN") == 0 || command.compare("Japan") == 0) {
		reply = getGreeting("こんにちは");
	}
	else if (command.compare("KOR") == 0 || command.compare("Korea") == 0) {
		reply = getGreeting("안녕하세요");
	}
	else if (command.compare("RUS") == 0 || command.compare("Russia") == 0) {
		reply = getGreeting("здравствуйте");
	}
	else {
		return ;
	}
	write(_socket, reply.c_str(), reply.size());
}

std::string Bot::getCountryList(void) const
{
	std::string list = "PRIVMSG #helloBot :<Supported Country List>\r\n";

	list.append("PRIVMSG #helloBot :ARE   Arab\r\n");
	list.append("PRIVMSG #helloBot :BRA   Brazil\r\n");
	list.append("PRIVMSG #helloBot :CHN   China\r\n");
	list.append("PRIVMSG #helloBot :DEU   Germany\r\n");
	list.append("PRIVMSG #helloBot :ESP   Spain\r\n");
	list.append("PRIVMSG #helloBot :FRA   France\r\n");
	list.append("PRIVMSG #helloBot :ITA   Italy\r\n");
	list.append("PRIVMSG #helloBot :JPN   Japan\r\n");
	list.append("PRIVMSG #helloBot :KOR   Korea\r\n");
	list.append("PRIVMSG #helloBot :RUS   Russia\r\n");

	return list;
}

std::string Bot::getGreeting(const std::string& message) const
{
	return ("PRIVMSG #helloBot :" + message + "\r\n");
}

void Bot::exit_with_perror(const std::string &msg)
{
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}
