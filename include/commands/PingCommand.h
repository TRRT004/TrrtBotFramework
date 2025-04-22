#ifndef PING_COMMAND_H
#define PING_COMMAND_H

#include "Command.h"

class PingCommand : public Command {
public:
    void registerCommand(dpp::cluster& bot) override;
};

#endif // PING_COMMAND_H