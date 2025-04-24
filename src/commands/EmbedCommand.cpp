#include "commands/EmbedCommand.h"

std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> EmbedCommand::getCommand(dpp::snowflake application_id) {
	dpp::slashcommand command("embed", "Answers the user with an embed", application_id);

	auto handler = [](const dpp::slashcommand_t& event) {
		dpp::embed embed;
		embed.set_color(dpp::colors::red);
		embed.set_title("Embed Title");
		embed.add_field("Field 1", "This is the first field", true);
		embed.add_field("Field 2", "This is the second field", true);
		embed.add_field("Field 3", "This is the third field", false);
		event.reply(dpp::message(embed).set_flags(dpp::m_ephemeral));
	};

	return std::make_pair(command, handler);
}