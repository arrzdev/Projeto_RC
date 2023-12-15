#ifndef __LOGIN_HPP__
#define __LOGIN_HPP__

#include "command.hpp"
#include <string>

using namespace std;

class Login : public Command {
private:
  string user;
  string password;

public:
  Login(vector<string> args);
  void send(string response) override;
  int execute() override;
};

#endif
