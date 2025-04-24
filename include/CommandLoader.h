#ifndef COMMAND_LOADER_H
#define COMMAND_LOADER_H

#include <vector>
#include <memory>
#include <dpp/dpp.h>
#include "commands/CommandRegistry.h"

class CommandLoader {
public:
    CommandLoader(dpp::cluster& bot) : bot(bot) {
        // Load commands and handlers from the registry
        for (const auto& command : CommandRegistry::getCommands()) {
            auto cmd = command->getCommand(bot.me.id);
            commands.first.push_back(cmd.first);
            commands.second.push_back(cmd.second);
            log("Loaded command: " + cmd.first.name);
        }

        log("Total commands loaded: " + std::to_string(commands.first.size()));
    }

    void registerCommands() {
        // Register all commands in bulk
        bot.global_bulk_command_create(commands.first, [this](const dpp::confirmation_callback_t& callback) {
            if (callback.is_error()) {
                log("Failed to register commands: " + callback.get_error().message, true);
            } else {
                log("All commands registered successfully.");
            }
        });
    }

    void handleCommand(const dpp::slashcommand_t& event) {
        // Find the command by name and execute its handler
        for (size_t i = 0; i < commands.first.size(); ++i) {
            if (event.command.get_command_name() == commands.first[i].name) {
                log("Handling command: " + event.command.get_command_name());
                commands.second[i](event);
                return;
            }
        }
        log("Command not found: " + event.command.get_command_name(), true);
    }

private:
    dpp::cluster& bot;
    std::pair<
        std::vector<dpp::slashcommand>, // Vector of commands
        std::vector<std::function<void(const dpp::slashcommand_t&)>> // Vector of handlers
    > commands;

    // Logging function
    void log(const std::string& message, bool isError = false) const {
        if (isError) {
            std::cerr << "[ERROR] " << message << std::endl;
        } else {
            std::cout << "[INFO] " << message << std::endl;
        }
    }
};

#endif // COMMAND_LOADER_H