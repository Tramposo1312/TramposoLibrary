#ifndef TRAMPLIB_CONFIG_MANAGER_H
#define TRAMPLIB_CONFIG_MANAGER_H

#include <string>
#include <unordered_map>

namespace tramplib {

    /**
     * @class ConfigManager
     * @brief Manages game configuration settings.
     *
     * This class provides functionality to load, access, and modify game settings
     * stored in an INI-style configuration file.
     */
    class ConfigManager {
    public:
        /**
         * @brief Loads configuration from a file.
         * @param filename The name of the configuration file to load.
         * @return True if loading was successful, false otherwise.
         */
        bool loadConfig(const std::string& filename);

        /**
         * @brief Gets the value of a configuration setting.
         * @param key The key of the setting to retrieve.
         * @param defaultValue The default value to return if the key is not found.
         * @return The value of the setting, or the default value if not found.
         */
        std::string getValue(const std::string& key, const std::string& defaultValue = "") const;

        /**
         * @brief Sets the value of a configuration setting.
         * @param key The key of the setting to set.
         * @param value The value to set.
         */
        void setValue(const std::string& key, const std::string& value);

        /**
         * @brief Saves the current configuration to a file.
         * @param filename The name of the file to save the configuration to.
         * @return True if saving was successful, false otherwise.
         */
        bool saveConfig(const std::string& filename) const;

    private:
        std::unordered_map<std::string, std::string> m_config; ///< Stores the configuration key-value pairs.
    };

} 

#endif