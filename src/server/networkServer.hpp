#ifndef NetworkServer_hpp
#define NetworkServer_hpp

#include "constants.hpp"

#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class NetworkServer {
public:
    ~NetworkServer();

    virtual void sendData(string data) = 0;

    virtual string receiveData() = 0;

protected:
    int port;
    int socketfd = -1;
    bool verbose;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
};

#endif