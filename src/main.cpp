#include <iostream>
#include "ConfigManager.h"
#include "BotFramework.h"

int main() {
    try {
        ConfigManager config("token.json");
        std::string botToken = config.get<std::string>("token");

        BotFramework bot(botToken);
        bot.start();
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}