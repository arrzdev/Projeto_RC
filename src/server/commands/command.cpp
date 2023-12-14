#include "command.hpp"

void Command::setupSocketConnection(int port, bool verbose, int socketfd, struct sockaddr_in serverInfo, struct sockaddr_in clientInfo)
{
  if (this->socketType == "UDP"){
    printf("Creating UDP socket\n");
    this->socket = make_unique<UdpSocket>(port, verbose, socketfd, serverInfo, clientInfo);
  }
}