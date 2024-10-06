#include "Config.h"
#include <fstream>
#include <iostream>

namespace Core {

    CConfig::CConfig() : mPort(0) {}

    CConfig::~CConfig() {}

    EErrors CConfig::LoadConfiguration() {
        std::ifstream configFile("config.txt");
        if (!configFile.is_open()) {
            std::cerr << "Failed to open configuration file for reading.\n";
            return EErrors::eFileNotFound;
        }

        configFile >> mPort;
        configFile.close();
        return EErrors::eNoError;
    }

    EErrors CConfig::SaveConfiguration() {
        std::ofstream configFile("config.txt");
        if (!configFile.is_open()) {
            std::cerr << "Failed to open configuration file for writing.\n";
            return EErrors::eFileNotFound;
        }

        configFile << mPort;
        configFile.close();
        return EErrors::eNoError;
    }

} // Core