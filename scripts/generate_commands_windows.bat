@echo off

:: Set paths
set COMMANDS_DIR=.\..\include\commands
set OUTPUT_FILE=.\..\include\commands.h

:: Ensure the commands directory exists
if not exist "%COMMANDS_DIR%" (
    echo [ERROR] Commands directory "%COMMANDS_DIR%" does not exist.
    exit /b 1
)

:: Always create or overwrite the commands.h file
(
    echo // Auto-generated commands.h file
    echo #ifndef COMMANDS_H
    echo #define COMMANDS_H
    echo.
    echo // Automatically generated includes for commands
    echo.
) > "%OUTPUT_FILE%"

:: Iterate over all .h files in the commands directory
for %%f in ("%COMMANDS_DIR%\*.h") do (
    if /i not "%%~nxf"=="BaseCommand.h" (
        echo #include "commands/%%~nxf" >> "%OUTPUT_FILE%"
    )
)

(
    echo.
    echo #endif // COMMANDS_H
) >> "%OUTPUT_FILE%"

echo [INFO] Generated %OUTPUT_FILE%