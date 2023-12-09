#ifndef USER_CLIENTSTATE_H
#define USER_CLIENTSTATE_H

#include <string>

using namespace std;

class ClientState {
    public:
        string getUser();
        void setUser(string user);

        string getPassword();
        void setPassword(string password);
    private:
        string user;
        string password;
};

#endif