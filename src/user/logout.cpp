#include "logout.hpp"
#include <iostream>

void Logout::send() {
    printf("Logout command sent\n");
}

string Logout::getCommand() {
    return LOGOUT_COMMAND;
}