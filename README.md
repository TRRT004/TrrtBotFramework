# TftTournamentBot

TftTournamentBot is a Discord bot written in C++ that helps manage tournament registrations on a Discord server.

## Features

- Allows users to register for tournaments via Discord commands.
- Provides administrators with tools to manage registrations.
- Sends notifications and updates about the tournament.

## Requirements

- C++17 or later
- [Discord API library for C++](https://github.com/discord/discord-api-docs) (e.g., [DPP](https://github.com/brainboxdotcc/DPP) or [Sleepy Discord](https://github.com/yourWaifu/sleepy-discord))
- A Discord bot token (create one [here](https://discord.com/developers/applications))

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/TftTournamentBot.git
   cd TftTournamentBot
   ```
2. Install dependencies: Follow the instructions for your chosen Discord API library.
3. Build the project:
	```bash
	mkdir build
	cd build
	cmake ..
	make
	```
4. Configure the bot: Create a `config.json` file in the root directory with your bot token:
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
2. Use the following commands in your Discord server:

   - `!register`: Register yourself for the tournament.
   - `!unregister`: Remove yourself from the tournament registration.
   - `!list`: Display the list of all registered participants.
   - `!status`: Check the current status of the tournament.

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
