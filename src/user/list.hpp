#ifndef USER_LIST_H
#define USER_LIST_H

#include "command.hpp"

#include <string>

#include "constants.hpp"

using namespace std;

class List : public Command {
    public:
        List() : Command(UDP, LIST) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif // LOGOUT_H
