#include "mybids.hpp"

void MyBids::send() {
    string data = formatData();

    this->networkClient->sendData(data);
}

void MyBids::receive() {
    string data = this->networkClient->receiveData();

    Parser parser = Parser(data);

    string command = parser.getCommand();

    vector<string> args = parser.getArgs();

    if(command != UDP_MY_BIDS_RESPONSE || args.size() < 1) {
        //TODO handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        // Auctions has same format as Bids
        vector<Auction> bids = parser.parseAuctions();

        for (Auction bid : bids) {
            printf("%s %s\n", bid.id.c_str(), bid.isOpen ? "open" : "closed");
        }
    }
    else if(status == STATUS_NOK) {
        printf("%s\n", MY_BIDS_EMPTY);
    }
    else if(status == STATUS_NOT_LOGGED_IN) {
        printf("%s\n", MY_BIDS_FAILURE);
    }
    else {
        //TODO handle error
    }


}

// Returns LMB <username>\n
string MyBids::formatData() {
    return string(UDP_MY_BIDS_COMMAND) + " " + this->clientState->getUser() + "\n";
}