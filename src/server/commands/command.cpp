#include "command.hpp"

void Command::setupSocketConnection(int port, bool verbose, int socketfd, struct sockaddr_in serverInfo, struct sockaddr_in clientInfo){
  if (this->socketType == "UDP"){
    printf("using udp socket\n");
    this->socket = make_unique<UdpSocket>(port, verbose, socketfd, serverInfo, clientInfo);
  }

  if (this->socketType == "TCP"){
    printf("using tcp socket\n");
    this->socket = make_unique<TcpSocket>(port, verbose, socketfd, serverInfo, clientInfo);
  }
}

void Command::send(string status){
  string response = string(this->returnCode) + " " + status + "\n";
  printf("[PROTOCOL] Sending response: %s", response.c_str());
  this->socket->sendData(response);

  if (this->socketType == "TCP"){ //tcp commands have a unique socket connection for communication
    close(this->socket->getCommandSocketfd());
  }
}