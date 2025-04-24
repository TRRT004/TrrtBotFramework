#ifndef EMBED_COMMAND_H
#define EMBED_COMMAND_H

#include <dpp/dpp.h>

class EmbedCommand {
public:
    static std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> getCommand(dpp::snowflake bot_id);
};

#endif // EMBED_COMMAND_H