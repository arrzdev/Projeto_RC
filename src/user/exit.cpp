#include "exit.hpp"

using namespace std;

int Exit::execute() {
    if(this->clientState->canExit()) {
        printf("Exiting...\n");
        return 1;
    }
    else {
        printf("You have to log out first\n");
        return 0;
    }
}

/**
All the commands have to implement these methods

However the Exit command does not need to send or receive data 
because it is only a local command
*/
void Exit::send() {}

void Exit::receive() {}

string Exit::formatData() {
    return "";
}