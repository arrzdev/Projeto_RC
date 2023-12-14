#include "open.hpp"
 
int Open::execute() {
    // check if user is logged in
    if(!this->clientState->isLoggedIn()) {
        printf("%s\n", string(NOT_LOGGED_IN).c_str());
        return 0;
    }
    
    return Command::execute();
}

void Open::send() {
    string data = this->formatData();

    this->networkClient->sendData(data);
}

void Open::receive() {
    string data = this->networkClient->receiveData();

    Parser parser = Parser(data);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != TCP_OPEN_RESPONSE || args.size() < 1) {
        //TODO handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        string auctionId = args[1];

        printf("Auction %s opened\n", auctionId.c_str());
    }
    else if(status == STATUS_NOK) {
        printf("%s\n", string(OPEN_FAILURE).c_str());
    }
    else if(status == STATUS_NOT_LOGGED_IN) {
        printf("%s\n", string(NOT_LOGGED_IN).c_str());
    }

}

string Open::formatData() {
    string userId = this->clientState->getUser();
    string password = this->clientState->getPassword();

    string fileSize = to_string(getFileSize());
    string fileData = getFileData();

    return string(TCP_OPEN_COMMAND) + " " + userId + " " + password + " " + this->name + " " + this->startValue + " " + this->timeActive + " " + this->fileName + " " + fileSize + " " + fileData + "\n";
}

int Open::getFileSize() {
    Fs fs = Fs(this->fileName);

    fs.open(READ);

    int size = fs.getSize();

    if(size == -1) {
        //TODO handle error
    }

    fs.close();

    return size;
}

string Open::getFileData() {
    Fs fs = Fs(this->fileName);

    // create pointer to string
    string data = "";

    fs.open(READ);

    bool ok = fs.read(&data);


    if(!ok) {
        //TODO handle error
    }

    fs.close();

    return data;
}