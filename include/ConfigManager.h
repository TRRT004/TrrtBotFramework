#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ConfigManager {
private:
    json configData;

    // Helper function to get the executable directory
    std::string getExecutableDir() const;

public:
    // Constructor to load the configuration file
    ConfigManager(const std::string& configFileName);

    // Function to get a value from the configuration file
    template <typename T>
    T get(const std::string& key) const {
        if (configData.contains(key)) {
            return configData[key].get<T>();
        } else {
            throw std::runtime_error("Key '" + key + "' not found in configuration file.");
        }
    }
};

#endif // CONFIG_MANAGER_H