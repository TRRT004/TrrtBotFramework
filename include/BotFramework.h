#ifndef BOT_FRAMEWORK_H
#define BOT_FRAMEWORK_H

#include <dpp/dpp.h>
#include "CommandRegistry.h"
#include "commands.h"

class BotFramework {
public:
    BotFramework(const std::string& token);

    void start();

private:
    dpp::cluster bot;

    void registerCommands();
    void handleCommand(const dpp::slashcommand_t& event);
};

#endif // BOT_FRAMEWORK_H