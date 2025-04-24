#!/bin/bash

# filepath: /home/rober/coding/discord/TrrtBotFramework/scripts/generate_commands_linux.sh

# Set the paths
COMMANDS_DIR="./../include/commands"
OUTPUT_FILE="./../include/commands.h"

# Ensure the commands directory exists
if [ ! -d "$COMMANDS_DIR" ]; then
    echo "[ERROR] Commands directory '$COMMANDS_DIR' does not exist."
    exit 1
fi

# Always create or overwrite the commands.h file
echo "// Auto-generated commands.h file" > "$OUTPUT_FILE"
echo "#ifndef COMMANDS_H" >> "$OUTPUT_FILE"
echo "#define COMMANDS_H" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
echo "// Automatically generated includes for commands" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

# Iterate over all .h files in the commands directory
for HEADER in "$COMMANDS_DIR"/*.h; do
    if [ -f "$HEADER" ]; then
        BASENAME=$(basename "$HEADER")
        if [ "$BASENAME" != "BaseCommand.h" ]; then
            echo "#include \"commands/$BASENAME\"" >> "$OUTPUT_FILE"
        fi
    fi
done

echo "" >> "$OUTPUT_FILE"
echo "#endif // COMMANDS_H" >> "$OUTPUT_FILE"

echo "[INFO] Generated $OUTPUT_FILE"