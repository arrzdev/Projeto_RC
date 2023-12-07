#include "common.hpp"

#include <sstream>

using namespace std;

Parser::Parser(string input) {
    this->input = input;

    stringstream ss(input);

    vector<string> tokens;

    string s;

    int i = 0;

    while(getline(ss, s, ' ')) {
        if(i == 0) {
            this->command = s;
        } else {
            this->args.push_back(s);
        }

        i++;
    }

}

string Parser::getCommand() {
    return this->command;
}

vector<string> Parser::getArgs() {
    return this->args;
}

string Parser::getInput() {
    return this->input;
}