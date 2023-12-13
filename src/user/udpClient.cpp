#include "udpClient.hpp"

UdpClient::UdpClient(string ip, int port) {
    this->serverIP = ip;
    this->serverPort = port;

    /*
    domain – Specifies the communication 
        domain ( AF_INET for IPv4/ AF_INET6 for IPv6 ) 
    type – Type of socket to be created 
        ( SOCK_STREAM for TCP / SOCK_DGRAM for UDP ) 
    protocol – Protocol to be used by the socket. 
        0 means using the default protocol for the address family.  
    */
    this->sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    //TODO handle error
    if(this->sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_port = htons(this->serverPort);
    this->serverAddr.sin_addr.s_addr = inet_addr(this->serverIP.c_str());

    //TODO handle error
}

int UdpClient::sendData(const string& data) {
    if(this->verbose) printf("Sending data: %s", data.c_str());

    int n = sendto(this->sockfd, data.c_str(), data.length(), 0, (struct sockaddr*) &this->serverAddr, sizeof(this->serverAddr));

    //TODO handle error
    if(n < 0) {
        printf("Error sending data\n");
        return -1;
    }

    return n;
}

string UdpClient::receiveData() {
    struct timeval tv;
    tv.tv_sec = CONNECTION_TIMEOUT;

    if(setsockopt(this->sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        // TODO handle error
    }

    char buffer[CHUNCKS];
    socklen_t len = sizeof(this->serverAddr);
    int n = recvfrom(this->sockfd, buffer, CHUNCKS, 0, (struct sockaddr*) &this->serverAddr, &len);

    if(n < 0) {
        if(tv.tv_sec == CONNECTION_TIMEOUT) {
            throw ConnectionTimeoutError();
        }
        //TODO handle error
    }

    // Set to n-1 because of the \n
    buffer[n-1] = '\0'; // sugested by copilotint

    string dataReceived = string(buffer);

    if(this->verbose) printf("Received data: %s\n", dataReceived.c_str());

    return dataReceived;
}