#ifndef USER_COMMAND_FACTORY_H
#define USER_COMMAND_FACTORY_H

#include "../constants.hpp"

#include "command.hpp"

#include "./local/exit.hpp"

#include "./UDP/login.hpp"
#include "./UDP/logout.hpp"
#include "./UDP/unregister.hpp"
#include "./UDP/myauctions.hpp"
#include "./UDP/mybids.hpp"
#include "./UDP/list.hpp"
#include "./UDP/showrecord.hpp"

#include "./TCP/showasset.hpp"

#include <string>
#include <vector>

class CommandFactory {
public:
    static Command* createCommand(string command, vector<string> args);

private:
    // UDP commands
    static Command* createLogin(vector<string> args);
    static Command* createLogout(vector<string> args);
    static Command* createExit(vector<string> args);
    static Command* createUnregister(vector<string> args);
    static Command* createMyAuctions(vector<string> args);
    static Command* createMyBids(vector<string> args);
    static Command* createList(vector<string> args);
    static Command* createShowRecord(vector<string> args);

    // TCP commands
    static Command* createShowAsset(vector<string> args);
};

#endif // USER_COMMAND_FACTORY_H