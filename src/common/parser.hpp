#ifndef COMMON_PARSER_H
#define COMMON_PARSER_H

#include <string>
#include <vector>

using namespace std;

struct Auction {
    string id;
    int isOpen;
};

class Parser {
    public:
        Parser(string input);
        string getCommand();
        vector<string> getArgs();
        string getInput();

        vector<Auction> parseAuctions();

    private:
        string input;
        string command;
        vector<string> args;
};

#endif