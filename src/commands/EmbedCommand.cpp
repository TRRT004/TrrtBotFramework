#include "commands/EmbedCommand.h"

void EmbedCommand::registerCommand(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("embed", "Sends an embed back!", bot.me.id),
        [](const dpp::confirmation_callback_t& callback) {
            if (callback.is_error()) {
                std::cerr << "Failed to register 'embed' command: " << callback.get_error().message << std::endl;
            } else {
                std::cout << "'embed' command registered successfully." << std::endl;
            }
        }
    );

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "embed") {
            dpp::embed embed;
            embed.set_color(dpp::colors::red)
                 .set_title("Test Embed")
                 .set_description("This is a test embed message.")
                 .add_field("Field 1", "This is the first field.")
                 .add_field("Field 2", "This is the second field.");

            // Set the reply as ephemeral
            event.reply(dpp::message(embed).set_flags(dpp::m_ephemeral));
        }
    });
}