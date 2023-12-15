#include "login.hpp"

Login::Login(vector<string> args) {
  //sets the socket type
  this->socketType = "UDP";

  //parses the arguments
  this->user = args[0];
  this->password = args[1];

  if (!Verify::isUID(this->user) || !Verify::isPassword(this->password)) {
    printf("Invalid user or password\n");
    throw exception();
  }
}

void Login::send(string response)
{
  this->socket->sendData(response + "\n");
  close(this->socket->getSocketfd());
}

int Login::execute() {
  printf("Executing login command\n");
  return 0;
}
