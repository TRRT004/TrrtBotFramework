#include <iostream>
#include <dpp/dpp.h>
#include "ConfigManager.h"
#include "commands/CommandLoader.h"

int main() {
    try {
        // Load the configuration
        ConfigManager config("token.json");

		// Initialize the bot
		dpp::cluster bot(config.get<std::string>("token"));

        bot.on_log(dpp::utility::cout_logger());

        // Load and register commands
        auto commands = CommandLoader::loadCommands();
        for (const auto& command : commands) {
            command->registerCommand(bot);
        }

        bot.start(dpp::st_wait);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}