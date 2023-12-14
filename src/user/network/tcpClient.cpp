#include "tcpClient.hpp"

TcpClient::TcpClient(string ip, int port) {
    this->serverIP = ip;
    this->serverPort = port;

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //TODO handle error
    if (this->sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }

    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_port = htons(this->serverPort);
    this->serverAddr.sin_addr.s_addr = inet_addr(this->serverIP.c_str());

    //TODO handle error
    if (connect(this->sockfd, (struct sockaddr *)&this->serverAddr, sizeof(this->serverAddr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }
}

int TcpClient::sendData(const string &data) {
    if(TCP_VERBOSE) printf("Sending data: %s", data.c_str());

    int n = write(this->sockfd, data.c_str(), data.length());

    //TODO handle error
    if (n < 0) {
        printf("Error sending data\n");
        return -1;
    }

    return n;
}

string TcpClient::receiveData() {
    string dataReceived = "";

    // n is the number of bytes read
    int n = 1;

    int totalBytes = 0;

    while(n != 0) {
        char buffer[CHUNCKS];
        n = read(this->sockfd, buffer, sizeof(buffer));

        //TODO handle error
        if(n < 0) {
            printf("Error receiving data\n");
            return "";
        }

        totalBytes += n;

        //TODO handle error
        if(totalBytes > MAX_TCP_REPLY_SIZE) {
            printf("Error receiving data\n");
            return "";
        }

        dataReceived.append(buffer, n);
    }

    dataReceived = dataReceived.substr(0, dataReceived.length() - 1);

    if(TCP_VERBOSE) printf("Received data: %s\n", dataReceived.c_str());

    return dataReceived;
}