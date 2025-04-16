# TftTournamentBot

TftTournamentBot is a Discord bot written in C++ that helps manage tournament registrations on a Discord server. It also integrates with Google Sheets and Excel to export and manage tournament data efficiently.

## Features

- Allows users to register for tournaments via Discord commands.
- Provides administrators with tools to manage registrations.
- Sends notifications and updates about the tournament.
- Exports tournament data to Google Sheets and Excel for easy management.

## Requirements

- C++17 or later
- [Discord API library for C++](https://github.com/discord/discord-api-docs) (e.g., [DPP](https://github.com/brainboxdotcc/DPP) or [Sleepy Discord](https://github.com/yourWaifu/sleepy-discord))
- A Discord bot token (create one [here](https://discord.com/developers/applications))
- [Google Sheets API](https://developers.google.com/sheets/api) credentials for integration
- [Excel library for C++](https://github.com/tfussell/xlnt) or equivalent for Excel file handling

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/TftTournamentBot.git
   cd TftTournamentBot
   ```
2. Install dependencies:
	- Follow the instructions for your chosen Discord API library.
	- Set up the Google Sheets API by creating a credentials.json file in the config/ directory. Refer to the Google Sheets API documentation for setup instructions
	- Install the Excel library (not yet decided)
3. Build the project:
	```bash
	mkdir build
	cd build
	cmake ..
	make
	```
4. Configure the bot: Create a `token.json` file in the `config` directory with your bot token:
	```json
	{
    	"token": "YOUR_DISCORD_BOT_TOKEN"
	}
	```
## Usage
1. Run the bot:
	```bash
	./TftTournamentBot
	```
2. Use the following slash commands in your Discord server:

## Contributing

Contributions are welcome! If you would like to contribute to this project:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes and push them to your fork.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Support

If you encounter any issues or have questions, feel free to open an issue in the repository or contact the maintainer.

---

Happy gaming!
