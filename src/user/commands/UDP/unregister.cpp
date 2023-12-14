#include "unregister.hpp"

void Unregister::send(){
    string dataToSend = this->formatData();

    this->networkClient->sendData(dataToSend);
}

void Unregister::receive(){
    string dataReceived = this->networkClient->receiveData();

    Parser parser = Parser(dataReceived);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != UDP_UNREGISTER_RESPONSE || args.size() != 1) {
        // TODO: handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        this->clientState->logoutUser();

        printf("%s\n", string(UNREGISTER_SUCCESS).c_str());
    }

    else if(status == STATUS_NOK) {
        printf("%s\n", string(UNREGISTER_FAILURE).c_str());
    }

    else if(status == STATUS_UNREGISTERD) {
        printf("%s\n", string(UNREGISTER_UNREGISTER).c_str());
    }
    
    else {
        //TODO handle error
    }
}

// returns UNR <username> <password>\n
string Unregister::formatData() {
    return string(UDP_UNREGISTER_COMMAND) + " " + this->clientState->getUser() + " " + this->clientState->getPassword() + "\n";
}