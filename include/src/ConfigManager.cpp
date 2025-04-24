#include "ConfigManager.h"
#include <fstream>
#include <stdexcept>

std::string ConfigManager::getExecutableDir() const {
    std::filesystem::path exePath = std::filesystem::canonical("/proc/self/exe");
    return exePath.parent_path().string();
}

ConfigManager::ConfigManager(const std::string& configFileName) {
    std::string baseDir = getExecutableDir();
    std::filesystem::path configFilePath = std::filesystem::path(baseDir) / "../config" / configFileName;

    std::ifstream file(configFilePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open configuration file: " + configFilePath.string());
    }

    file >> configData;
    file.close();
}