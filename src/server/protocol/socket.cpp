#include "socket.hpp"

// deconstructor for Socket class
Socket::~Socket() {
  if (socketfd != -1) {
    close(socketfd);
  }
}

// getter for port
int Socket::getPort() {
  return port;
}

// setter for port
void Socket::setPort(int port) {
  this->port = port;
}

// getter for socketfd
int Socket::getSocketfd() {
  return socketfd;
}

// setter for socketfd
void Socket::setSocketfd(int socketfd) {
  this->socketfd = socketfd;
}

// getter for verbose
bool Socket::getVerbose() {
  return verbose;
}

// setter for verbose
void Socket::setVerbose(bool verbose) {
  this->verbose = verbose;
}

// getter for serverInfo
struct sockaddr_in Socket::getServerInfo() {
  return serverInfo;
}

// setter for serverInfo
void Socket::setServerInfo(struct sockaddr_in serverInfo) {
  this->serverInfo = serverInfo;
}

// getter for clientInfo
struct sockaddr_in Socket::getClientInfo() {
  return clientInfo;
}

// setter for clientInfo
void Socket::setClientInfo(struct sockaddr_in clientInfo) {
  this->clientInfo = clientInfo;
}

// constructor for Socket class
Socket::Socket() {
  // initialize serverInfo
  serverInfo.sin_family = AF_INET;
  serverInfo.sin_addr.s_addr = INADDR_ANY;
}