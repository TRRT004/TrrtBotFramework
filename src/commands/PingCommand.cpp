#include "commands/PingCommand.h"

std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> PingCommand::getCommand(dpp::snowflake application_id) {
    // Define the slash command
    dpp::slashcommand command("ping", "Replies with Pong!", application_id);

    // Define the handler function
    auto handler = [](const dpp::slashcommand_t& event) {
        // Reply with "Pong!"
        event.reply(dpp::message("Pong!").set_flags(dpp::m_ephemeral));
    };

    // Return the command and its handler as a pair
    return std::make_pair(command, handler);
}