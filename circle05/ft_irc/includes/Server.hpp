#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/event.h>
#include <arpa/inet.h>
#include <string>
#include <map>
#include <vector>

class Client;
class Channel;
class CommandHandler;

class Server
{
  typedef std::vector<Channel *>::iterator channels_iterator;

private:
  int _portNum;
  const std::string _password;
  int _socket;
  struct sockaddr_in _address;
  std::string _message;
  std::string _servername;
  std::string _version;

  struct kevent *_currEvent;
  std::map<int, Client *> _clients;       // map for client socket:data
  std::vector<struct kevent> _changeList; // kevent vector for changelist
  struct kevent _eventList[8];            // kevent array for eventlist

  CommandHandler *_commandHandler;
  std::vector<Channel *> _channels;

public:
  Server(int port, std::string password);
  ~Server();

  const std::string &getServerName(void) const;
  const std::string &getVersion(void) const;

  const std::string&	getPassword(void) const;
  
  void start();
  void exit_with_perror(const std::string &msg);
  void changeEvents(std::vector<struct kevent> &change_list, uintptr_t ident, int16_t filter,
                    uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
  void acceptNewClient();
  void readDataFromClient();
  void disconnectClient(int client_fd);
  void setServername(std::string servername);
  void setVersion(std::string version);

  Client *getClient(const std::string &nickname);
  Channel *createChannel(const std::string &name, const std::string &password, Client *client);
  Channel *getChannel(const std::string &name);
  void removeChannel(Channel *channel);
};

#endif
