#include "main.hpp"

int main(int argc, char** argv) {
  int port = DEFAULT_PORT;
  bool verbose = DEFAULT_VERBOSE;

  for (int i = 0; i < argc; i++) {
    string arg = argv[i];

    if (arg == PORT_FLAG) {
      port = atoi(argv[i + 1]);
    } else if (arg == VERBOSE_FLAG) {
      verbose = true;
    }
  }

  printf("Starting server on port %d %s verbose mode\n", port, verbose ? "with" : "without");

  //class socket supports both udp and tcp
  UdpSocket udpMonitor = UdpSocket(port, verbose);

  while (true) {
    // at all times udpMonitor.clientAdress will have the adress of the last client that communicated
    string receivedData = udpMonitor.receiveData();

    if (receivedData == "") { //no data received
      continue;
    }

    Command *command = CommandFactory::createCommand(receivedData);
    if (command == NULL) {
      printf("Exception was throwed\n");
      udpMonitor.sendData(STATUS_ERR);
      continue;
    }

    udpMonitor.sendData(STATUS_ERR);

    //set up the socket connection for the command
    command->setupSocketConnection(
      port, 
      verbose, 
      udpMonitor.getSocketfd(),
      udpMonitor.getServerInfo(),
      udpMonitor.getClientInfo()
    );

    command->execute();
    command->send(STATUS_ERR);
  }

  return 0;
}