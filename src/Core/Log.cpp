//
// Created by Jean-Michel Frouin on 20/10/2024.
//

#include "Log.h"
#include <iostream>

namespace Core {
    bool CLog::mEnabled = false;
    std::ofstream CLog::mFileHandler;

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
            mFileHandler << message << std::endl;
        }
    }

    void CLog::Log(const std::string& message, int value) {
        if (mEnabled && mFileHandler.is_open()) {
            mFileHandler << message << ": " << value << std::endl;
        }
    }

    void CLog::Log(const std::string& message, const std::string& value) { // New method
        if (mEnabled && mFileHandler.is_open()) {
            mFileHandler << message << ": " << value << std::endl;
        }
    }
}