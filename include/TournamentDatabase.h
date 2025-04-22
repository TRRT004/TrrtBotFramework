#pragma once

#include <sqlite3.h>
#include <filesystem>
#include <string>
#include <memory>

class TournamentDatabase {
public:
    TournamentDatabase(const std::string& dbName);
    ~TournamentDatabase();

    // Helper function to get the executable directory
    std::string getExecutableDir() const;

private:
    void initializeDatabaseSchema();

    sqlite3* database; // Pointer to the SQLite database
};