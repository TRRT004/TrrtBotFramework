# TftTournamentBot

TftTournamentBot is a Discord bot written in C++ that helps manage tournament registrations on a Discord server. It also integrates with Google Sheets and Excel to export and manage tournament data efficiently.

## Features

- **Implemented**:
  - Allows users to register for tournaments via Discord commands.
  - Provides administrators with tools to manage registrations.
  - Sends notifications and updates about the tournament.
  - Slash commands:
    - `/ping`: Test the bot's responsiveness.
    - `/embed`: Sends an embedded message.

- **To Be Implemented**:
  - Export tournament data to Google Sheets and Excel for easy management.
  - Integration with Google Sheets API.
  - Integration with an Excel library for C++ (e.g., [xlnt](https://github.com/tfussell/xlnt)).

## Requirements

- C++17 or later
- [DPP (Discord API library for C++)](https://github.com/brainboxdotcc/DPP)
- A Discord bot token (create one [here](https://discord.com/developers/applications))
- SQLite3 for database management
- [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing
- (To be implemented) [Google Sheets API](https://developers.google.com/sheets/api) credentials for integration
- (To be implemented) [Excel library for C++](https://github.com/tfussell/xlnt) or equivalent for Excel file handling

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
   - Install SQLite3:
     ```bash
     sudo apt install libsqlite3-dev
     ```
   - Install nlohmann/json:
     ```bash
     sudo apt install nlohmann-json3-dev
     ```

3. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
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
   ./TftTournamentBot
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
   - Install SQLite3:
     ```bash
     brew install sqlite
     ```
   - Install nlohmann/json:
     ```bash
     brew install nlohmann-json
     ```

3. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
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
   ./TftTournamentBot
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
     vcpkg install dpp sqlite3 nlohmann-json
     ```
   - Integrate `vcpkg` with CMake:
     ```powershell
     cmake .. -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
     ```

   #### Option 2: Without `vcpkg`
   - Install the DPP library:
     - Download and build the library from [DPP GitHub](https://github.com/brainboxdotcc/DPP).
   - Install SQLite3:
     - Download the precompiled binaries from [SQLite Downloads](https://www.sqlite.org/download.html).
   - Install `nlohmann/json`:
     - Download the single-header file from [nlohmann/json GitHub](https://github.com/nlohmann/json/releases) and include it in your project.

3. Build the project:
   - Open a terminal in the project directory and run:
     ```powershell
     mkdir build
     cd build
     cmake .. -G "MinGW Makefiles"
     mingw32-make
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
   .\TftTournamentBot.exe
   ```

## Usage

1. Start the bot:
   ```bash
   ./TftTournamentBot
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