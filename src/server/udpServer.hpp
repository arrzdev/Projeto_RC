#ifndef UDPServer_hpp
#define UDPServer_hpp

#include "networkServer.hpp"

class UdpServer : public NetworkServer {
public:
    UdpServer(int port, bool verbose);

    void sendData(string data) override;

    string receiveData() override;
};

#endif