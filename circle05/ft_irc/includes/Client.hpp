#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

class Channel;

enum ERegistered
{
	PASS = 1 << 0,               // 0001
	NICK = 1 << 1,               // 0010
	USER = 1 << 2,               // 0100
  ALL  = PASS | NICK | USER    // 0111
};

class Client
{
private:
  const int   _socket;
  int         _registered;
  std::string _message;
  std::string _nickname;
  std::string _username;
  std::string _hostname;
  std::string _host;
  std::string _realname;
  std::string _buffer;
  Channel*    _channel;

public:
  Client();
  Client(int socketNum);
  ~Client();

  int getSocket(void) const;

  void setMessage(std::string msg);
  const std::string& getMessage() const;

  void  setRegistered(int type);
  const int&  getRegistered()  const;

  void setNickname(std::string msg);
  const std::string& getNickname() const;

  void setUsername(std::string msg);
  const std::string& getUsername() const;

  void setHostname(std::string msg);
  const std::string& getHostname() const;

  void setHost(std::string msg);
  const std::string& getHost() const;

  void setRealname(std::string msg);
  const std::string& getRealname() const;

  void setBuffer(std::string msg);
  void addBuffer(std::string msg);
  const std::string& getBuffer() const;

  const std::string getPrefix(void) const;

  void setChannel(Channel *channel);
  Channel* getChannel();

  void  join(Channel* channel);
  int   writeToSocket(const std::string msg) const;
  void  reply(const std::string& reply) const;
  void  reply(const std::string& from, const std::string& reply) const;
};

std::ostream& operator<<(std::ostream& o, const Client& rhs);

#endif
