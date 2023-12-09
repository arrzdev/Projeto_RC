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
    }
}

void Command::execute() {
    this->send();
    this->receive();
}

string Command::getCommand() {
    return this->command;
}