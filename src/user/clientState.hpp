#ifndef USER_CLIENTSTATE_H
#define USER_CLIENTSTATE_H

#include <string>

using namespace std;

class ClientState {
    public:
        void loginUser(string user, string password);
        void logoutUser();

        string getUser();
        void setUser(string user);

        string getPassword();
        void setPassword(string password);

        bool canExit();
    private:
        string user;
        string password;
};

#endif