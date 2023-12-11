#ifndef USER_COMMAND_FACTORY_H
#define USER_COMMAND_FACTORY_H

#include "constants.hpp"

#include "command.hpp"
#include "login.hpp"
#include "logout.hpp"
#include "exit.hpp"
#include "unregister.hpp"
#include "myauctions.hpp"
#include "mybids.hpp"
#include "list.hpp"

#include <string>
#include <vector>

class CommandFactory {
public:
    static Command* createCommand(string command, vector<string> args);

private:
    static Command* createLogin(vector<string> args);
    static Command* createLogout(vector<string> args);
    static Command* createExit(vector<string> args);
    static Command* createUnregister(vector<string> args);
    static Command* createMyAuctions(vector<string> args);
    static Command* createMyBids(vector<string> args);
    static Command* createList(vector<string> args);
};

#endif // USER_COMMAND_FACTORY_H