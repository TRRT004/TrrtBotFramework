#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include <dpp/dpp.h>
#include <utility>
#include <functional>

class BaseCommand {
public:
    virtual ~BaseCommand() = default;

    virtual std::pair<dpp::slashcommand, std::function<void(const dpp::slashcommand_t&)>> getCommand(dpp::snowflake application_id) const = 0;
};

#endif // BASE_COMMAND_H