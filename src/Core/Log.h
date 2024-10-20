//
// Created by Jean-Michel Frouin on 20/10/2024.
//

#ifndef EOS_LOG_H
#define EOS_LOG_H

#include <string>
#include <fstream>

namespace Core {
    /**
     * @class CLog
     * @brief A class to handle logging.
     */
    class CLog {
    public:
        /**
         * @brief Creates a log file.
         * @param filename The name of the log file.
         */
        static void CreateLogFile(const std::string& filename);

        /**
         * @brief Closes the log file.
         */
        static void CloseLogFile();

        /**
         * @brief Logs a message to the log file.
         * @param message The message to log.
         */
        static void Log(const std::string& message);

        /**
         * @brief Logs a message and an integer to the log file.
         * @param message The message to log.
         * @param value The integer value to log.
         */
        static void Log(const std::string& message, int value);
        static void Log(const std::string& message, const std::string& value); // New overload


    private:
        static bool mEnabled; ///< Indicates if logging is enabled.
        static std::ofstream mFileHandler; ///< The file handler for the log file.
    };
}

#endif //EOS_LOG_H
