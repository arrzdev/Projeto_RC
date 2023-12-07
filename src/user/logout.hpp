#ifndef USER_LOGOUT_H
#define USER_LOGOUT_H

#include "command.hpp"

#define LOGOUT_COMMAND "logout"

using namespace std;

// Derived class for Logout
class Logout : public Command {
public:
    void send() override;
    string getCommand() override;
};

#endif // LOGOUT_H
