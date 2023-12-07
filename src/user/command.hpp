#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include "../common/common.hpp"

using namespace std;

// Command abstract class
/**
 * 0 is a pure virtual function
 * default tells the compiler to use the default implementation
*/
class Command {
public:
    virtual ~Command() = default;

    virtual void send() = 0;

    virtual string getCommand() = 0;
};

#endif