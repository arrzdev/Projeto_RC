#include "login.hpp"

Login::Login(vector<string> args) {
  this->socketType = "UDP";

  //parses the arguments
  this->user = args[0];
  this->password = args[1];

}

void Login::send() {
  this->socket->sendData("RLI NOK\n");
}


int Login::execute() {
  printf("Executing login command\n");
  return 0;
}

