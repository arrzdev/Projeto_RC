#include "commandParser.hpp"

using namespace std;

Command* CommandParser::parseCommand(const string &input) {
    Parser parser(input);

    string command = parser.getCommand();

    vector<string> arguments = parser.getArgs();

    if (command == LOGIN) {
        if(arguments.size() != 2) {
            printf("Usage: login <user> <password>\n");
            return nullptr;
        }

        string user = arguments[0];
        string password = arguments[1];
        return new Login(user, password);
    } 
    else if (command == LOGOUT) {
        return new Logout();
    } 
    else if (command == EXIT) {
        return new Exit();
    }
    else {
        return nullptr;
    }
} 