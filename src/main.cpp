#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <dpp/dpp.h>

using json = nlohmann::json;

std::string getExecutableDir() {
	std::filesystem::path exePath = std::filesystem::canonical("/proc/self/exe");
	return exePath.parent_path().string();
}

std::string readBotToken() {
	std::string baseDir = getExecutableDir();
	std::filesystem::path tokenFilePath = std::filesystem::path(baseDir) / "../config/token.json";

	std::ifstream file(tokenFilePath);
	if (!file.is_open()) {
		throw std::runtime_error("Unable to open token file: " + tokenFilePath.string());
	}

	json config;
	file >> config;
	file.close();

	if (config.contains("token")) {
		return config["token"];
	} else {
		throw std::runtime_error("Token not found in configuration file.");
	}
}

int main() {
	try {
		dpp::cluster bot(readBotToken());

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
						// Handle the error after attempting to send the message
						if (user == event.command.get_issuing_user().id) {
							event.reply(dpp::message("I couldn't send you a message.").set_flags(dpp::m_ephemeral));
						} else {
							event.reply(dpp::message("I couldn't send a message to that user. Please check that is a valid user!").set_flags(dpp::m_ephemeral));
						}
					} else {
						// Handle the success case
						if (user == event.command.get_issuing_user().id) {
							event.reply(dpp::message("I've sent you a private message.").set_flags(dpp::m_ephemeral));
						} else {
							event.reply(dpp::message("I've sent a message to that user.").set_flags(dpp::m_ephemeral));
						}
					}
				});
			} else {
				// Ensure the "Unknown command" reply is ephemeral
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