# TrrtBotFramework

TrrtBotFramework is a C++ framework for building Discord bots using the DPP library. It provides a basic setup for creating and managing slash commands, so developers can focus on implementing their bot's functionality.

## Features

- Easy-to-use command registration system.
- Modular structure for adding new commands.
- Built-in support for DPP (Discord API library for C++).
- Example commands included (`/ping`, `/embed`).

## Requirements

- C++17 or later
- [DPP (Discord API library for C++)](https://github.com/brainboxdotcc/DPP)
- A Discord bot token (create one [here](https://discord.com/developers/applications))
- [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing

## Installation

### Linux

1. Clone the repository:
   ```bash
   git clone https://github.com/TRRT004/TftTournamentBot.git
   cd TftTournamentBot
   ```

2. Install dependencies:
   - Install the DPP library:
     ```bash
     sudo apt install libdpp-dev
     ```
   - Install nlohmann/json:
     ```bash
     sudo apt install nlohmann-json3-dev
     ```

3. Build the project:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

4. Configure the bot:
   - Create a `token.json` file in the `config` directory with your bot token:
     ```json
     {
         "token": "YOUR_DISCORD_BOT_TOKEN"
     }
     ```

5. Run the bot:
   ```bash
   ./build/Bot
   ```

### macOS

1. Clone the repository:
   ```bash
   git clone https://github.com/TRRT004/TftTournamentBot.git
   cd TftTournamentBot
   ```

2. Install dependencies using Homebrew:
   - Install the DPP library:
     ```bash
     brew install dpp
     ```
   - Install nlohmann/json:
     ```bash
     brew install nlohmann-json
     ```

3. Build the project:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

4. Configure the bot:
   - Create a `token.json` file in the `config` directory with your bot token:
     ```json
     {
         "token": "YOUR_DISCORD_BOT_TOKEN"
     }
     ```

5. Run the bot:
   ```bash
   ./build/Bot
   ```

### Windows

1. Clone the repository:
   ```powershell
   git clone https://github.com/TRRT004/TftTournamentBot.git
   cd TftTournamentBot
   ```

2. Install dependencies:

   #### Option 1: Using `vcpkg`
   - Install `vcpkg` by following the instructions [here](https://github.com/microsoft/vcpkg).
   - Install the required libraries:
     ```powershell
     vcpkg install dpp nlohmann-json
     ```
   - Integrate `vcpkg` with CMake:
     ```powershell
     cmake .. -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
     ```

   #### Option 2: Without `vcpkg`
   - Install the DPP library:
     - Download and build the library from [DPP GitHub](https://github.com/brainboxdotcc/DPP).
   - Install `nlohmann/json`:
     - Download the single-header file from [nlohmann/json GitHub](https://github.com/nlohmann/json/releases) and include it in your project.

3. Build the project:
   - Open a terminal in the project directory and run:
     ```powershell
     cmake -S . -B build
   	 cmake --build build
     ```

4. Configure the bot:
   - Create a `token.json` file in the `config` directory with your bot token:
     ```json
     {
         "token": "YOUR_DISCORD_BOT_TOKEN"
     }
     ```

5. Run the bot:
   ```powershell
    .\build\Bot.exe
   ```

## Usage

1. Start the bot:
   ```bash
   ./Bot
   ```
2. Use the following slash commands in your Discord server:
   - `/ping`: Test the bot's responsiveness.
   - `/embed`: Sends an embedded message.

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