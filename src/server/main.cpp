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

    UdpServer udpServer = UdpServer(port, verbose);

    while (true) {
        string data = udpServer.receiveData();

        udpServer.sendData(data);
    }


    return 0;
}