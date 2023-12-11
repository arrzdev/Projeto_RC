#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include "command.hpp"
#include <string>

#include "../common/common.hpp"

#include "constants.hpp"

using namespace std;

class Login : public Command {
    private:
        string user;
        string password;

    public:
        Login(string user, string password) 
            : Command(UDP, LOGIN), user(user), password(password) {};
        
        void send() override;
        void receive() override;

        string formatData() override;
};

#endif
