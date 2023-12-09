#include "main.hpp"

#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    string serverIP = DEFAULT_IP;
    int serverPort = DEFAULT_PORT;

    for (int i = 0; i<argc; i++){
        string arg = argv[i];

        if (arg == IP_FLAG) {
            serverIP = argv[i+1];
        } else if (arg == PORT_FLAG) {
            serverPort = atoi(argv[i+1]);
        }
    }

    printf("Connecting to %s:%d\n", serverIP.c_str(), serverPort);

    ClientState clientState = ClientState();

    bool isExit = false;

    while(!isExit) {
        string input;

        getline(cin, input);

        Command* command = CommandParser::parseCommand(input);

        if(command == nullptr) {
            printf("Invalid command\n");
            continue;
        }

        printf("command: %s \n", command->getCommand().c_str());

        command->setNetworkClient(serverIP, serverPort);

        command->setClientState(&clientState);

        command->execute();

        printf("%s \n", command->getCommand().c_str());

        if(command->getCommand() == EXIT) {
            isExit = true;
        }

        delete command;
    }   

    return 0;
}