#include "commandFactory.hpp"

Command* CommandFactory::createCommand(string command, vector<string> arguments) {
    if (command == LOGIN) {
        return CommandFactory::createLogin(arguments);
    } 
    else if (command == LOGOUT) {
        return CommandFactory::createLogout(arguments);
    } 
    else if (command == EXIT) {
        return CommandFactory::createExit(arguments);
    }
    else if(command == UNREGISTER){
        return CommandFactory::createUnregister(arguments);
    }
    else if(command == MY_AUCTIONS || command == MY_AUCTIONS_SHORT){
        return CommandFactory::createMyAuctions(arguments);
    }
    else {
        return nullptr;
    }
}

Command* CommandFactory::createLogin(vector<string> arguments) {
    if(arguments.size() != 2) {
        printf("Usage: login <user> <password>\n");
        return nullptr;
    }

    string user = arguments[0];
    string password = arguments[1];
    return new Login(user, password);
}

Command* CommandFactory::createLogout(vector<string> arguments) {
    if(arguments.size() != 0) {
        printf("Usage: logout\n");
        return nullptr;
    }

    return new Logout();
}

Command* CommandFactory::createExit(vector<string> arguments) {
    if(arguments.size() != 0) {
        printf("Usage: exit\n");
        return nullptr;
    }

    return new Exit();
}

Command* CommandFactory::createUnregister(vector<string> arguments) {
    if(arguments.size() != 0) {
        printf("Usage: unregister\n");
        return nullptr;
    }

    return new Unregister();
}

Command* CommandFactory::createMyAuctions(vector<string> arguments) {
    if(arguments.size() != 0) {
        printf("Usage: myauctions\n");
        return nullptr;
    }

    return new MyAuctions();
}