#ifndef EMBED_COMMAND_H
#define EMBED_COMMAND_H

#include "Command.h"

class EmbedCommand : public Command {
	void registerCommand(dpp::cluster& bot) override;
};

#endif // EMBED_COMMAND_H