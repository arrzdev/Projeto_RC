#include "login.hpp"
#include <iostream>

using namespace std;

void Login::send() {
    string dataToSend = this->formatData();

    printf("Sent: %s\n", dataToSend.c_str());

    this->networkClient->sendData(dataToSend);
}

void Login::receive() {
    string dataReceived = this->networkClient->receiveData();

    printf("Received: %s\n", dataReceived.c_str());

    Parser parser = Parser(dataReceived);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != UDP_LOGIN_RESPONSE) {
        // TODO: handle error
    }

    string status = args[0];

    if(status == STATUS_OK) {
        this->clientState->setUser(this->user);
        this->clientState->setPassword(this->password);

        printf("%s\n", string(LOGIN_SUCCESS).c_str());
    }

    else if(status == STATUS_NOK) {
        printf("%s\n", string(LOGIN_FAILURE).c_str());
    }
    
    else if(status == STATUS_REGISTERD) {
        printf("%s\n", string(LOGIN_REGISTER).c_str());
    }
    
    else {
        //TODO handle error
    }
}

// returns LIN <user> <password>\n
string Login::formatData() {
    return string(UDP_LOGIN_COMMAND) + " " + this->user + " " + this->password + "\n";
};