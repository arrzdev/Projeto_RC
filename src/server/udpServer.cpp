#include "udpServer.hpp"

UdpServer::UdpServer(int port, bool verbose) {
    this->port = port;
    this->verbose = verbose;
    this->socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->socketfd < 0) {
        // TODO error handling
    }
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;
    this->serverAddress.sin_port = htons(this->port);

    int err = bind(this->socketfd, (struct sockaddr *) &this->serverAddress, sizeof(this->serverAddress));

    if (err < 0) {
        // TODO error handling
    }
}

string UdpServer::receiveData() {
    char buffer[CHUNCKS];

    socklen_t len = sizeof(this->clientAddress);

    int n = recvfrom(this->socketfd, buffer, CHUNCKS, 0, (struct sockaddr*) &this->clientAddress, &len);
    if (n < 0) {
        // TODO error handling
    }

    string dataReceived = string(buffer);

    dataReceived[n-1] = '\0';

    if(this->verbose){
     printf("Received data: %s\n", dataReceived.c_str());
    }

    return dataReceived;
}

void UdpServer::sendData(string data) {
    int n = sendto(this->socketfd, data.c_str(), data.length(), 0, (struct sockaddr*) &this->clientAddress, sizeof(this->clientAddress));
    if (n < 0) {
        // TODO error handling
    }
}