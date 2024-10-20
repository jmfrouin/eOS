#include "Log.h"
#include <iostream>
#include <chrono>
#include <iomanip>

namespace Core {
    bool CLog::mEnabled = false;
    std::ofstream CLog::mFileHandler;

    std::string getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }

    void CLog::CreateLogFile(const std::string& filename) {
        mFileHandler.open(filename, std::ios::out | std::ios::app);
        if (mFileHandler.is_open()) {
            mEnabled = true;
        } else {
            std::cerr << "Failed to create log file: " << filename << std::endl;
        }
    }

    void CLog::CloseLogFile() {
        if (mFileHandler.is_open()) {
            mFileHandler.close();
            mEnabled = false;
        }
    }

    void CLog::Log(const std::string& message) {
        if (mEnabled && mFileHandler.is_open()) {
            mFileHandler << "[" << getCurrentTimestamp() << "] " << message << std::endl;
        }
    }

    void CLog::Log(const std::string& message, int value) {
        if (mEnabled && mFileHandler.is_open()) {
            mFileHandler << "[" << getCurrentTimestamp() << "] " << message << ": " << value << std::endl;
        }
    }

    void CLog::Log(const std::string& message, const std::string& value) {
        if (mEnabled && mFileHandler.is_open()) {
            mFileHandler << "[" << getCurrentTimestamp() << "] " << message << ": " << value << std::endl;
        }
    }
}