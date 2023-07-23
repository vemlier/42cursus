#include <iostream>

#include "bot.hpp"

static bool isValidInput(char **argv)
{
    for (size_t i = 0; i < strlen(argv[1]); i++)
    {
      if (std::isspace(argv[1][i]))
      {
        return false;
      }
    }
  for (size_t i = 0; i < strlen(argv[2]); i++)
  {
    if (!isdigit(argv[2][i]))
    {
      return false;
    }
  }
  if (atoi(argv[2]) > 65535)
  {
    return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  if (argc != 4 || !isValidInput(argv))
  {
    std::cerr << "usage: ./ircbot <host> <port> <password>" << std::endl;
    return EXIT_FAILURE;
  }

  Bot bot(argv[1], atoi(argv[2]), argv[3]);
  bot.start();

  return 0;
}