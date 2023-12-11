#include "list.hpp"

void List::send() {
    string data = formatData();

    this->networkClient->sendData(data);
}

void List::receive() {
    string data = this->networkClient->receiveData();

    Parser parser = Parser(data);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != UDP_LIST_RESPONSE || args.size() < 1) {
        // TODO handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        vector<Auction> auctions = parser.parseAuctions();

        for (Auction auction : auctions) {
            printf("%s %s\n", auction.id.c_str(), auction.isOpen ? "open" : "closed");
        }
    }

    else if(status == STATUS_NOK) {
        printf("%s\n", string(LIST_FAILURE).c_str());
    }

    else {
        // TODO handle error
    }
}

string List::formatData() {
    return string(UDP_LIST_COMMAND) + "\n";
}