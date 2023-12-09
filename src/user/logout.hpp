#ifndef USER_LOGOUT_H
#define USER_LOGOUT_H

#include "command.hpp"

#include <string>

#include "constants.hpp"

using namespace std;

// Derived class for Logout
class Logout : public Command {
    public:
        Logout() : Command(UDP, LOGIN) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif // LOGOUT_H
