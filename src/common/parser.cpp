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

vector<Auction> Parser::parseAuctions() {
    vector<Auction> auctions;

    int auctionsCount = this->args.size() / 2;

    /**
     * i starts at 1 because the first argument is the status
     * to get id you need to do i * 2 - 1 (1, 3, 5, 7, ...)
     * to get isOpen you need to do i * 2 (2, 4, 6, 8, ...)
    */
    
    for(int i = 1; i < auctionsCount; i++) {
        Auction auction;

        auction.id = this->args[i * 2 - 1];
        auction.isOpen = stoi(this->args[i * 2]);

        auctions.push_back(auction);
    }
    
    return auctions;
}