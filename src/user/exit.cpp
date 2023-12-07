#include "exit.hpp"
#include <iostream>

using namespace std;

void Exit::send() {
    printf("Exit command sent\n");
}

string Exit::getCommand() {
    return EXIT_COMMAND;
}
