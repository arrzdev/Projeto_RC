#include "networkServer.hpp"

NetworkServer::~NetworkServer() {
    if (socketfd != -1) {
        close(socketfd);
    }
}