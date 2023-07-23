#ifndef __NUMERIC_REPLIES_HPP__
#define __NUMERIC_REPLIES_HPP__

#define ERR_NOSUCHNICK(source, nickname) "401 " + source + " " + nickname + " :No such nick/channel\r\n"
#define ERR_NOSUCHCHANNEL(source, channel) "403 " + source + " " + channel + " :No such channel\r\n"
#define ERR_TOOMANYCHANNELS(source, channel) "405 " + source + " " + channel + " :You have joined too many channels\r\n"
#define ERR_NONICKNAMEGIVEN(client) "431 " + client + " :No nickname given\r\n"
#define ERR_ERRONEUSNICKNAME(client, nick) "432 " + client + " " + nick + " :Erroneus nickname\r\n"
#define ERR_NICKNAMEINUSE(client, nick) "433 " + client + " " + nick + " :Nickname is already in use\r\n"
#define ERR_NOTONCHANNEL(source, channel) "442 " + source + " " + channel + " :You're not on that channel\r\n"
#define ERR_NEEDMOREPARAMS(client, command) "461 " + client + " " + command + " :Not enough parameters\r\n"
#define ERR_ALREADYREGISTRED "462 :You may not reregister\r\n"
#define ERR_BADCHANNELKEY(source, channel) "475 " + source + " " + channel + " :Cannot join channel (+k)\r\n"
#define ERR_CHANOPRIVSNEEDED(source, channel) "482 " + source + " " + channel + " :You're not channel operator\r\n"
#define ERR_UMODEUNKNOWNFLAG(client) "501 " + client + " :Unknown MODE flag\r\n"
#define ERR_CANNOTSENDTOCHAN(source, channel) "404 " + source + " " + channel + " :Cannot send to channel\r\n"

#define RPL_NAMREPLY(source, channel, users) "353 " + source + " = " + channel + " :" + users + "\r\n"
#define RPL_ENDOFNAMES(source, channel) "366 " + source + " " + channel + " :End of /NAMES list." + "\r\n"

#define RPL_JOIN(source, channel) ":" + source + " JOIN :" + channel + "\r\n"
#define RPL_PART(source, channel) ":" + source + " PART :" + channel + "\r\n"
#define RPL_PRIVMSG(source, target, message) ":" + source + " PRIVMSG " + target + " :" + message + "\r\n"
#define RPL_PING(source, token) ":" + source + " PONG :" + token + "\r\n"
#define RPL_NICK(source, nick) ":" + source + " NICK :" + nick + "\r\n"
#define RPL_MODE(source, channel, modes, args) ":" + source + " MODE " + channel + " " + modes + " " + args + "\r\n"
#define RPL_KICK(source, channel, target, message) ":" + source + " KICK " + channel + " " + target + " " + message + "\r\n"
#define RPL_NOTICE(source, target, message) ":" + source + " NOTICE " + target + " :" + message + "\r\n"
#define RPL_QUIT(source, message) ":" + source + " QUIT :" + message + "\r\n"

#endif
