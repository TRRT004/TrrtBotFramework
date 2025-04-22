#ifndef COMMAND_LOADER_H
#define COMMAND_LOADER_H

#include <vector>
#include <memory>
#include "Command.h"
#include "PingCommand.h"
#include "EmbedCommand.h"

class CommandLoader {
public:
    static std::vector<std::unique_ptr<Command>> loadCommands() {
        std::vector<std::unique_ptr<Command>> commands;

        // Add commands here
        commands.push_back(std::make_unique<PingCommand>());
        commands.push_back(std::make_unique<EmbedCommand>());

        return commands;
    }
};

#endif // COMMAND_LOADER_H