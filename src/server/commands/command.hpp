#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <memory>
#include <vector>
#include "../protocol/socket.hpp"
#include "../protocol/udpSocket.hpp"

using namespace std;

// Command abstract class
/**
 * 0 is a pure virtual function
 * default tells the compiler to use the default implementation
 */
class Command {
protected:
  unique_ptr<Socket> socket;
  string socketType;

public:
  virtual void send() = 0;
  virtual int execute() = 0;
  void setupSocketConnection(int port, bool verbose, int socketfd, struct sockaddr_in serverInfo, struct sockaddr_in clientInfo);
};

#endif