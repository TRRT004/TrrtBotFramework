#ifndef PING_COMMAND_H
#define PING_COMMAND_H

#include <dpp/dpp.h>
#include <utility>
#include <functional>

class PingCommand {
public:
    // Method to get the slash command definition and its handler
    static std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> getCommand(dpp::snowflake bot_id);
};

#endif // PING_COMMAND_H