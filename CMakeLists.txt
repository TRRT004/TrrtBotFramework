cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TftTournamentBot VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all .cpp files under the src directory (recursively)
file(GLOB_RECURSE SRC_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add the executable
add_executable(TftTournamentBot ${SRC_SOURCES})

# Include directories for dependencies
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find and link the DPP library
find_package(dpp REQUIRED)
target_link_libraries(TftTournamentBot dpp::dpp)

# Find and link the nlohmann/json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(TftTournamentBot nlohmann_json::nlohmann_json)

# Add SQLite3 manually
find_library(SQLITE3_LIBRARY sqlite3 REQUIRED)
target_include_directories(TftTournamentBot PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TftTournamentBot ${SQLITE3_LIBRARY})

# Set the output directory for the binary
set_target_properties(TftTournamentBot PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add any additional libraries or dependencies here