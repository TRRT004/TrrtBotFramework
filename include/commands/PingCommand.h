#ifndef PING_COMMAND_H
#define PING_COMMAND_H

#include "BaseCommand.h"
#include "CommandRegistry.h"

class PingCommand : public BaseCommand {
public:
    PingCommand() = default;

    std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> getCommand(dpp::snowflake application_id) const override {
        dpp::slashcommand command("ping", "Replies with Pong!", application_id);

        auto handler = [](const dpp::slashcommand_t& event) {
            event.reply(dpp::message("Pong!").set_flags(dpp::m_ephemeral));
        };

        return std::make_pair(command, handler);
    }

private:
    inline static const bool registered = []() {
        CommandRegistry::registerCommand(std::make_unique<PingCommand>());
        return true;
    }();
};

#endif // PING_COMMAND_H