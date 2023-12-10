#ifndef USER_UNREGISTER_H
#define USER_UNREGISTER_H

#include "command.hpp"

#include <string>

#include "constants.hpp"

using namespace std;

// Derived class for Unregister
class Unregister : public Command {
    public:
        Unregister() : Command(UDP, UNREGISTER) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif // UNREGISTER_H
