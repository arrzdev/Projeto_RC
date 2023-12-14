#include "commandFactory.hpp"

Command* CommandFactory::createCommand(string protocolMessage) {

  printf("Parsing Command %s\n", protocolMessage.c_str());
  Parser parser(protocolMessage);
  string command = parser.getCommand();
  vector<string> arguments = parser.getArgs();
  
  printf("Received command: %s\n", command.c_str());

  if (command == "LIN"){
    printf("Creating login command\n");
    return new Login(arguments);
  }
  else {
    printf("Invalid command\n");
  }

  if (arguments.size() > 0)
  {
  }

  return NULL;
}