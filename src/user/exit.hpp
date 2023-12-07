#ifndef USER_EXIT_H
#define USER_EXIT_H

#include "command.hpp"
#include <string>

#define EXIT_COMMAND "exit"

using namespace std;

// Derived class for Login
class Exit : public Command {
public:
    void send() override;
    string getCommand() override;
};

#endif
