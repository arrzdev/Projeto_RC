#include "login.hpp"
#include <iostream>

using namespace std;

Login::Login(std::string user, std::string password) {
    this->user = user;
    this->password = password;
}

void Login::send() {
    printf("Login command sent user: %s and password %s\n", user.c_str(), password.c_str());
}

string Login::getCommand() {
    return LOGIN_COMMAND;
}
