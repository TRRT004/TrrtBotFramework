#ifndef COMMAND_H
#define COMMAND_H

#include <dpp/dpp.h>

class Command {
public:
    virtual ~Command() = default;

    // Method to register the command
    virtual void registerCommand(dpp::cluster& bot) = 0;
};

#endif // COMMAND_H