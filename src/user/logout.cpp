#include "logout.hpp"
#include <iostream>

void Logout::send() {
}

void Logout::receive() {
}

string Logout::formatData() {
    return string(UDP_LOGOUT_COMMAND) + " " + this->clientState->getUser() + " " + this->clientState->getPassword() + "\n";
}