#ifndef BOT_FRAMEWORK_H
#define BOT_FRAMEWORK_H

#include <dpp/dpp.h>
#include "commands/CommandRegistry.h"

class BotFramework {
public:
    BotFramework(const std::string& token) : bot(token) {
        bot.on_log(dpp::utility::cout_logger());

        // Register commands when the bot is ready
        bot.on_ready([this](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                registerCommands();
            }
        });

        // Handle slash commands
        bot.on_slashcommand([this](const dpp::slashcommand_t& event) {
            handleCommand(event);
        });
    }

    void start() {
        bot.start(dpp::st_wait);
    }

private:
    dpp::cluster bot;

    void registerCommands() {
        std::vector<dpp::slashcommand> commands;
        for (const auto& command : CommandRegistry::getCommands()) {
            commands.push_back(command->getCommand(bot.me.id).first);
        }

        bot.global_bulk_command_create(commands, [](const dpp::confirmation_callback_t& callback) {
            if (callback.is_error()) {
                std::cerr << "[ERROR] Failed to register commands: " << callback.get_error().message << std::endl;
            } else {
                std::cout << "[INFO] All commands registered successfully." << std::endl;
            }
        });
    }

    void handleCommand(const dpp::slashcommand_t& event) {
        for (const auto& command : CommandRegistry::getCommands()) {
            if (event.command.get_command_name() == command->getCommand(event.command.id).first.name) {
                command->getCommand(event.command.id).second(event);
                return;
            }
        }
        std::cerr << "[ERROR] Command not found: " << event.command.get_command_name() << std::endl;
    }
};

#endif // BOT_FRAMEWORK_H