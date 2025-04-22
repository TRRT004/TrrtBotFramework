#include "TournamentDatabase.h"
#include <stdexcept>
#include <iostream>

TournamentDatabase::TournamentDatabase(const std::string& dbName) : database(nullptr) {
    std::string baseDir = getExecutableDir();
    std::filesystem::path dbFilePath = std::filesystem::path(baseDir) / "../database" / dbName;

    try {
        // Ensure the database directory exists
        std::filesystem::create_directories(dbFilePath.parent_path());

        // Open the SQLite database (create it if it doesn't exist)
        if (sqlite3_open(dbFilePath.string().c_str(), &database) != SQLITE_OK) {
            throw std::runtime_error("Failed to open or create database: " + std::string(sqlite3_errmsg(database)));
        }

        // Initialize the database schema
        initializeDatabaseSchema();
    } catch (const std::exception& e) {
        if (database) {
            sqlite3_close(database);
            database = nullptr;
        }
        throw std::runtime_error("Database initialization failed: " + std::string(e.what()));
    }
}

TournamentDatabase::~TournamentDatabase() {
    if (database) {
        sqlite3_close(database); // Close the database connection
    }
}

std::string TournamentDatabase::getExecutableDir() const {
    std::filesystem::path exePath = std::filesystem::canonical("/proc/self/exe");
    return exePath.parent_path().string();
}

void TournamentDatabase::initializeDatabaseSchema() {
    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS tournaments (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            date TEXT NOT NULL
        );
    )";

    char* errorMessage = nullptr;
    if (sqlite3_exec(database, createTableSQL, nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        std::string error = "Failed to initialize database schema: " + std::string(errorMessage);
        sqlite3_free(errorMessage);
        throw std::runtime_error(error);
    }
}