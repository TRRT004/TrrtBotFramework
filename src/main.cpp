#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> // Include the JSON library (https://github.com/nlohmann/json)
#include <dpp/dpp.h>         // Include the DPP library for Discord API

using json = nlohmann::json;

std::string readBotToken(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open token file: " + filePath);
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
        // Read the bot token from the configuration file
        std::string token = readBotToken("../config/token.json");

        // Initialize the bot
        dpp::cluster bot(token);

        // Set up an event listener for when the bot is ready
        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct on_ready>()) {
                std::cout << "Bot is ready!" << std::endl;
            }
        });

        // Start the bot
        bot.start(false);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}