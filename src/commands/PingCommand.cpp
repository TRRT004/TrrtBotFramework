#include "commands/PingCommand.h"

void PingCommand::registerCommand(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("ping", "Ping pong!", bot.me.id),
        [](const dpp::confirmation_callback_t& callback) {
            if (callback.is_error()) {
                std::cerr << "Failed to register 'ping' command: " << callback.get_error().message << std::endl;
            } else {
                std::cout << "'ping' command registered successfully." << std::endl;
            }
        }
    );

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });
}