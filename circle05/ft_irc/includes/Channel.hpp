#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>

#include "Client.hpp"

class Client;

class Channel
{
	typedef std::vector<Client *>::iterator clients_iterator;

private:
	std::string _name;
	std::string _password;
	Client *_admin;
	std::vector<Client *> _clients;

public:
	Channel(const std::string &name, const std::string &password, Client *admin);
	~Channel();

	Client *getAdmin() const;
	const std::string getName() const;
	const std::string getPassword() const;
	std::vector<std::string> getNicknames();

	void		setPassword(std::string password) { this->_password = password; };
 

	void addClient(Client *client);
	void broadcast(std::string msg);
	void broadcast(const std::string &message, Client *exclude);
	int removeClient(Client *client);
	void kick(Client *client, Client *target, const std::string &reason);
};

#endif
