#ifndef EOS_LOG_H
#define EOS_LOG_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <iomanip>

#define LOG_TO_FILE
#define LOG_FILE "eOS.log"

namespace Core {
    /**
     * @class CLog
     * @brief A class to handle logging.
     */
    class CLog {
    public:
        static std::string getCurrentTimestamp() {
            auto now = std::chrono::system_clock::now();
            auto in_time_t = std::chrono::system_clock::to_time_t(now);
            std::stringstream ss;
            ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
            return ss.str();
        }

        static void Log(const std::string &file, const int &line, const std::string &message) {
#ifdef LOG_TO_FILE
            std::ofstream File;
            File.open(LOG_FILE, std::ios::out | std::ios::app);
            File << "[" << getCurrentTimestamp() << "] "
                 << file << ":" << line << " "
                 << message << std::endl;
            File.close();
#else
            std::cout << "[" << getCurrentTimestamp() << "] "
                      << file << ":" << line << " "
                      << message << std::endl;
#endif
        }

        static void Log(const std::string &file, const int &line, const std::string &message, int value) {
#ifdef LOG_TO_FILE
            std::ofstream File;
            File.open(LOG_FILE, std::ios::out | std::ios::app);
            File << "[" << getCurrentTimestamp() << "] "
                 << file << ":" << line << " "
                 << message << ": " << value << std::endl;
            File.close();
#else
            std::cout << "[" << getCurrentTimestamp() << "] "
                      << file << ":" << line << " "
                      << message << ": " << value << std::endl;
#endif
        }

        static void Log(const std::string &file, const int &line, const std::string &message, const std::string &value) {
#ifdef LOG_TO_FILE
            std::ofstream File;
            File.open(LOG_FILE, std::ios::out | std::ios::app);
            File << "[" << getCurrentTimestamp() << "] "
                 << file << ":" << line << " "
                 << message << ": " << value << std::endl;
            File.close();
#else
            std::cout << "[" << getCurrentTimestamp() << "] "
                      << file << ":" << line << " "
                      << message << ": " << value << std::endl;
#endif
        }
    };
}

#endif //EOS_LOG_H