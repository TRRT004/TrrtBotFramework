#ifndef EMBED_COMMAND_H
#define EMBED_COMMAND_H

#include "BaseCommand.h"
#include "CommandRegistry.h"

class EmbedCommand : public BaseCommand {
public:
    EmbedCommand() = default;

    std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> getCommand(dpp::snowflake application_id) const override {
        dpp::slashcommand command("embed", "Replies with an embed!", application_id);

        auto handler = [](const dpp::slashcommand_t& event) {
            dpp::embed embed;
            embed.set_title("Embed Title")
                 .set_description("This is an example embed.")
                 .set_color(dpp::colors::blue);

            event.reply(dpp::message().add_embed(embed).set_flags(dpp::m_ephemeral));
        };

        return std::make_pair(command, handler);
    }

private:
    inline static const bool registered = []() {
        CommandRegistry::registerCommand(std::make_unique<EmbedCommand>());
        return true;
    }();
};

#endif // EMBED_COMMAND_H