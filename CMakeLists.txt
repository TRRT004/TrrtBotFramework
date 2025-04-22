cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TftTournamentBot VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(TftTournamentBot src/main.cpp src/classes/ConfigManager.cpp)

# Include directories for dependencies
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find and link the DPP library
find_package(dpp REQUIRED)
target_link_libraries(TftTournamentBot dpp::dpp)

# Find and link the nlohmann/json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(TftTournamentBot nlohmann_json::nlohmann_json)

# Set the output directory for the binary
set_target_properties(TftTournamentBot PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add any additional libraries or dependencies here