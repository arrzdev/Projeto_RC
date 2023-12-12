#include "showrecord.hpp"

void ShowRecord::send() {
    string data = formatData();
    
    this->networkClient->sendData(data);
}

void ShowRecord::receive() {
    string data = this->networkClient->receiveData();
    
    Parser parser = Parser(data);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != UDP_SHOW_RECORD_RESPONSE || args.size() < 1) {
        //TODO handle error
    }

    string status = args[0];

    if(status == STATUS_OK){
        // check if all arguments arrived handle error
        for(size_t i = 1; i < args.size(); i++){
            cout << args[i] << endl;
        }
    }
    else if(status == STATUS_NOK){
        printf("Auction %s not found\n", this->auctionId.c_str());
    }
}

string ShowRecord::formatData() {
    return string(UDP_SHOW_RECORD_COMMAND) + " " + auctionId + "\n";
}