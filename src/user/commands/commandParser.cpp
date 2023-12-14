#include "commandParser.hpp"

Command* CommandParser::parseCommand(const string &input) {
    Parser parser(input);

    string command = parser.getCommand();

    vector<string> arguments = parser.getArgs();

    return CommandFactory::createCommand(command, arguments);
} 