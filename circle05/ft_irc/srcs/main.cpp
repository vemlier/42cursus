#include "Server.hpp"

#include <iostream>

static bool isValidInput(char **argv)
{

  for (size_t i = 0; i < std::strlen(argv[1]); i++)
  {
    if (!std::isdigit(argv[1][i]))
    {
      return false;
    }
  }
  if (std::strlen(argv[1]) > 5 || std::atoi(argv[1]) > 65535)
  {
    return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  if (argc != 3 || !isValidInput(argv))
  {
    std::cerr << "usage: ./ircserv <port> <password>" << std::endl;
    return EXIT_FAILURE;
  }

  Server server(atoi(argv[1]), argv[2]);
  server.start();

  return 0;
}
