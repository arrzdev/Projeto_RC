#ifndef __COMMAND_FACTORY_HPP__
#define __COMMAND_FACTORY_HPP__

#include "../constants.hpp"
#include "command.hpp"
#include "../../common/common.hpp"

#include "login.hpp"

#include <string>
#include <vector>

class CommandFactory {
public:
  static Command *createCommand(string protocolMessage);
};

#endif