#include "main.hpp"

#include <iostream>

using namespace std;


int main() {

    bool isExit = false;

    while(!isExit) {
        string input;

        getline(cin, input);

        Command* command = CommandParser::parseCommand(input);

        if (command != nullptr) {
            command->send();
            
            if (command->getCommand() == EXIT_COMMAND) {
                isExit = true;
            }

            delete command;
        } else {
            cout << "Invalid command" << endl;
        }
    }   

    return 0;
}