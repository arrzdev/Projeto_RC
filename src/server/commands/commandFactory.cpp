#include "commandFactory.hpp"

Command* CommandFactory::createCommand(string protocolMessage) {
  Parser parser(protocolMessage.substr(0, protocolMessage.size() - 1));

  string command = parser.getCommand();
  vector<string> arguments = parser.getArgs();

  // catch exception throwed by the constructor, in that case the command is invalid and we return NULL 
  try {
    if (command == "LIN"){
      printf("Creating login command\n");
      return new Login(arguments);
    }
  } catch(const std::exception& e ) {
    return NULL;
  }


  return NULL; // if no command is found, return NULL
}