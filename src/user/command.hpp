#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include "../common/common.hpp"
#include "clientState.hpp"

#include "networkClient.hpp"
#include "udpClient.hpp"

#include "constants.hpp"

#include <memory>

using namespace std;

// Command abstract class
/**
 * 0 is a pure virtual function
 * default tells the compiler to use the default implementation
*/
class Command {
    protected:
        ClientState* clientState;
        unique_ptr<NetworkClient> networkClient;

        /** 
         *0: UDP
        *1: TCP
        */
        int networkType;

        string command;

    public:
        Command(string command) 
            : command(command) {}

        Command(int networkType, string command) 
            : networkType(networkType), command(command) {}

        virtual ~Command() = default;

        // sends data to Auction Server
        virtual void send() = 0;

        // receives data from Auction Server
        virtual void receive() = 0;

        // Executes command
        void execute();

        // returns local command used
        string getCommand();

        // returns formatted string of data to send to auction server
        virtual string formatData() = 0;

        void setClientState(ClientState* clientState);

        void setNetworkClient(string serverIp, int serverPort);
};

#endif