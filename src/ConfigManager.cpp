#include "tramplib/ConfigManager.h"
#include <fstream>
#include <sstream>

namespace tramplib {

    bool ConfigManager::loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream is_line(line);
            std::string key;
            if (std::getline(is_line, key, '=')) {
                std::string value;
                if (std::getline(is_line, value)) {
                    m_config[key] = value;
                }
            }
        }

        return true;
    }

    std::string ConfigManager::getValue(const std::string& key, const std::string& defaultValue) const {
        auto it = m_config.find(key);
        if (it != m_config.end()) {
            return it->second;
        }
        return defaultValue;
    }

    void ConfigManager::setValue(const std::string& key, const std::string& value) {
        m_config[key] = value;
    }

    bool ConfigManager::saveConfig(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        for (const auto& pair : m_config) {
            file << pair.first << "=" << pair.second << std::endl;
        }

        return true;
    }

}