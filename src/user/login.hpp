#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include "command.hpp"
#include <string>

#define LOGIN_COMMAND "login"

using namespace std;

// Derived class for Login
class Login : public Command {
private:
    string user;
    string password;

public:
    Login(string user, string password);
    void send() override;
    string getCommand() override;
};

#endif
