#include <iostream>
#include <dpp/dpp.h>
#include "ConfigManager.h"

int main() {
    try {
        // Load the configuration
        ConfigManager config("token.json");
        std::string botToken = config.get<std::string>("token");

        // Initialize the bot
        dpp::cluster bot(botToken);

        bot.on_log(dpp::utility::cout_logger());

        bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
            if (event.command.get_command_name() == "ping") {
                event.reply("Pong!");
            } else if (event.command.get_command_name() == "embed") {
                dpp::embed embed;
                embed.set_color(dpp::colors::red)
                     .set_title("Test Embed")
                     .set_description("This is a test embed message.")
                     .add_field("Field 1", "This is the first field.")
                     .add_field("Field 2", "This is the second field.");

                event.reply(dpp::message(embed));
            } else if (event.command.get_command_name() == "hello") {
                event.reply(dpp::message("Hi").set_flags(dpp::m_ephemeral));
            } else if (event.command.get_command_name() == "pm") {
                dpp::snowflake user;

                // Check if the "user" parameter is provided
                if (event.get_parameter("user").index() == 0) {
                    // Default to the user who issued the command
                    user = event.command.get_issuing_user().id;
                } else {
                    // Use the provided user
                    user = std::get<dpp::snowflake>(event.get_parameter("user"));
                }

                // Send the private message
                bot.direct_message_create(user, dpp::message(std::get<std::string>(event.get_parameter("message"))), [event, user](const dpp::confirmation_callback_t& callback) {
                    if (callback.is_error()) {
                        if (user == event.command.get_issuing_user().id) {
                            event.reply(dpp::message("I couldn't send you a message.").set_flags(dpp::m_ephemeral));
                        } else {
                            event.reply(dpp::message("I couldn't send a message to that user. Please check that is a valid user!").set_flags(dpp::m_ephemeral));
                        }
                    } else {
                        if (user == event.command.get_issuing_user().id) {
                            event.reply(dpp::message("I've sent you a private message.").set_flags(dpp::m_ephemeral));
                        } else {
                            event.reply(dpp::message("I've sent a message to that user.").set_flags(dpp::m_ephemeral));
                        }
                    }
                });
            } else {
                event.reply(dpp::message("Unknown command.").set_flags(dpp::m_ephemeral));
            }
        });

        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                std::cout << "Registering commands..." << std::endl;

                bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id), [](const dpp::confirmation_callback_t& callback) {
                    if (callback.is_error()) {
                        std::cerr << "Failed to register 'ping' command: " << callback.get_error().message << std::endl;
                    } else {
                        std::cout << "'ping' command registered successfully." << std::endl;
                    }
                });

                bot.global_command_create(dpp::slashcommand("embed", "Send a test Embed", bot.me.id), [](const dpp::confirmation_callback_t& callback) {
                    if (callback.is_error()) {
                        std::cerr << "Failed to register 'embed' command: " << callback.get_error().message << std::endl;
                    } else {
                        std::cout << "'embed' command registered successfully." << std::endl;
                    }
                });

                bot.global_command_create(dpp::slashcommand("hello", "Says hi back", bot.me.id), [](const dpp::confirmation_callback_t& callback) {
                    if (callback.is_error()) {
                        std::cerr << "Failed to register 'hello' command: " << callback.get_error().message << std::endl;
                    } else {
                        std::cout << "'hello' command registered successfully." << std::endl;
                    }
                });

                bot.global_command_create(
                    dpp::slashcommand("pm", "Send a private message to a user", bot.me.id)
                        .add_option(
                            dpp::command_option(dpp::co_string, "message", "The message to send", true) // Required
                        )
                        .add_option(
                            dpp::command_option(dpp::co_user, "user", "The user to send the message to", false) // Optional
                        ),
                    [](const dpp::confirmation_callback_t& callback) {
                        if (callback.is_error()) {
                            std::cerr << "Failed to register 'pm' command: " << callback.get_error().message << std::endl;
                        } else {
                            std::cout << "'pm' command registered successfully." << std::endl;
                        }
                    }
                );
            }
        });

        bot.start(dpp::st_wait);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}