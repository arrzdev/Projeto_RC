#include "myauctions.hpp"

void MyAuctions::send(){
    string dataToSend = this->formatData();

    this->networkClient->sendData(dataToSend);
}

void MyAuctions::receive(){
    string dataReceived = this->networkClient->receiveData();

    Parser parser = Parser(dataReceived);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != UDP_MY_AUCTIONS_RESPONSE || args.size() != 1) {
        // TODO: handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        /*
        Info about the auctions is received in the following format:
        <auction_id> <0|1> <auction_id> <0|1> ...
        where 0 means the auction is closed and 1 means it is open
        */
        vector<Auction> auctions = parser.parseAuctions();

        for (Auction auction : auctions) {
            printf("%s %s\n", auction.id.c_str(), auction.isOpen ? "open" : "closed");
        }
    }
    else if(status == STATUS_NOK) {
        printf("No ongoing auctions\n");
    }
    else if(status == STATUS_NOT_LOGGED_IN) {
        printf("You are not logged in\n");
    }
    else {
        //TODO: handle error
    }
    
}

// returns LMA <username>\n
string MyAuctions::formatData() {
    return string(UDP_MY_AUCTIONS_COMMAND) + " " + this->clientState->getUser() + "\n";
}