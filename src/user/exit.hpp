#ifndef USER_EXIT_H
#define USER_EXIT_H

#include "command.hpp"
#include <string>

#include "constants.hpp"

using namespace std;

class Exit : public Command {
    public:
        Exit() : Command(EXIT) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif
