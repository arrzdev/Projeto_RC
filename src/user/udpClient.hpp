#ifndef USER_UDP_HPP
#define USER_UDP_HPP

#include <string>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <unistd.h>

using namespace std;

class UdpClient {
    public:
        UdpClient(string ip, int port);
        ~UdpClient();
        bool sendData(const string& data);
        string receiveData();

    private:
        int sockfd;
        string serverIP;
        int serverPort;

        struct sockaddr_in serverAddr;
    };

#endif