#ifndef USER_MYAUCTIONS_H
#define USER_MYAUCTIONS_H

#include "command.hpp"

#include <string>

#include "constants.hpp"

using namespace std;

// Derived class for Unregister
class MyAuctions : public Command {
    public:
        MyAuctions() : Command(UDP, MY_AUCTIONS) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif // MYAUCTIONS_H
