#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include <vector>
#include <memory>
#include "BaseCommand.h"

class CommandRegistry {
public:
    // Add a command to the registry
    static void registerCommand(std::unique_ptr<BaseCommand> command) {
        getRegistry().push_back(std::move(command));
    }

    // Get all registered commands
    static const std::vector<std::unique_ptr<BaseCommand>>& getCommands() {
        return getRegistry();
    }

private:
    // Singleton-like access to the registry
    static std::vector<std::unique_ptr<BaseCommand>>& getRegistry() {
        static std::vector<std::unique_ptr<BaseCommand>> registry;
        return registry;
    }
};

#endif // COMMAND_REGISTRY_H