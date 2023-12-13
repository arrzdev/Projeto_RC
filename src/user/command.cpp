#include "command.hpp"

using namespace std;

void Command::setClientState(ClientState *clientState) {
    this->clientState = clientState;
}

void Command::setNetworkClient(string serverIp, int serverPort) {
    int networkType = this->networkType;

    if(networkType == UDP) {
        this->networkClient = make_unique<UdpClient>(serverIp, serverPort);
    }

    else if(networkType == TCP) {
        this->networkClient = make_unique<TcpClient>(serverIp, serverPort);
    }
}

// Only returns 1 if the command can exit
int Command::execute() {
    try {
        this->send();
        this->receive();
    }
    catch(CostumError& e) {
        printf("%s\n", e.what());
    } 
    //TODO check if here or in main to get more generic errors
    catch(exception& e) {
        printf("Unknown error: %s\n", e.what());
    }

    return 0;
}

string Command::getCommand() {
    return this->command;
}