#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include <vector>
#include <memory>
#include <iostream>
#include "commands/BaseCommand.h"

class CommandRegistry {
public:
    static void registerCommand(std::unique_ptr<BaseCommand> command) {
        getRegistry().push_back(std::move(command));
    }

    static const std::vector<std::unique_ptr<BaseCommand>>& getCommands() {
        return getRegistry();
    }

private:
    static std::vector<std::unique_ptr<BaseCommand>>& getRegistry() {
        static std::vector<std::unique_ptr<BaseCommand>> registry;
        return registry;
    }
};

#endif // COMMAND_REGISTRY_H