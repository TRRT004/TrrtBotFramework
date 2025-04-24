#include <iostream>
#include <dpp/dpp.h>
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

		bot.global_bulk_command_delete([&bot](const dpp::confirmation_callback_t& callback) {
			if (callback.is_error()) {
				std::cerr << "Failed to delete commands: " << callback.get_error().message << std::endl;
			} else {
				std::cout << "All commands deleted successfully." << std::endl;
			}
		});

        // Register commands
		CommandLoader commandLoader(bot);
		commandLoader.registerCommands();

        // Handle slash commands
        bot.on_slashcommand([&commandLoader](const dpp::slashcommand_t& event) {
            commandLoader.handleCommand(event);
        });

        bot.start(dpp::st_wait);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}