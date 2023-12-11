#ifndef USER_MYBIDS_HPP
#define USER_MYBIDS_HPP

#include "command.hpp"

#include <string>

#include "constants.hpp"

using namespace std;

class MyBids : public Command {
    public:
        MyBids() : Command(UDP, MY_BIDS) {};

        void send() override;
        void receive() override;

        string formatData() override;
};

#endif // USER_MYBIDS_HPP