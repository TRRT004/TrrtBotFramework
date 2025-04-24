cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TrrtBotFramework VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all .cpp files under the src and include/src directories (recursively)
file(GLOB_RECURSE SRC_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/include/src/*.cpp
)

# Add the executable
add_executable(TrrtBotFramework ${SRC_SOURCES})

# Include directories for dependencies
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find and link the DPP library
find_package(dpp REQUIRED)
target_link_libraries(TrrtBotFramework dpp::dpp)

# Find and link the nlohmann/json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(TrrtBotFramework nlohmann_json::nlohmann_json)

# Set the output directory for the binary
set_target_properties(TrrtBotFramework PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
	OUTPUT_NAME "Bot"
)

# Add any additional libraries or dependencies here