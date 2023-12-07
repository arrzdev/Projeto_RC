#ifndef USER_COMMANDPARSER_H
#define USER_COMMANDPARSER_H

#include "../common/common.hpp"

#include "string.h"

#include "command.hpp"
#include "login.hpp"
#include "logout.hpp"
#include "exit.hpp"

using namespace std;


class CommandParser {
public:
    static Command* parseCommand(const std::string &input);
};

#endif // COMMANDPARSER_H
