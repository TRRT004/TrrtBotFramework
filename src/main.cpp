#include <iostream>
#include <dpp/dpp.h>
#include <sqlite3.h>
#include "ConfigManager.h"
#include "commands/CommandLoader.h"

int main() {
    try {
        // Load the configuration
        ConfigManager config("token.json");
        std::string botToken = config.get<std::string>("token");

        // Initialize the bot
        dpp::cluster bot(botToken);

        bot.on_log(dpp::utility::cout_logger());

        // Register commands when the bot is ready
        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                CommandLoader commandLoader(bot);
                // Register all commands
				commandLoader.registerCommands();
            }
        });

        // Handle slash commands
        bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
            CommandLoader commandLoader(bot);
            commandLoader.handleCommand(event);
        });

        bot.start(dpp::st_wait);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}