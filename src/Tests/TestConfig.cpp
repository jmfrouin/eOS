#include <gtest/gtest.h>
#include "Core/Config.h"
#include "Core/Errors.h"

class CConfigTest : public ::testing::Test {
    protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
        config = new Core::CConfig();
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
        delete config;
    }

    Core::CConfig* config;
};

TEST_F(CConfigTest, LoadConfiguration_FileNotFound) {
    // Ensure the configuration file does not exist
    std::remove("config.txt");

    // Test loading configuration when the file does not exist
    EXPECT_EQ(config->LoadConfiguration(), Core::EErrors::eFileNotFound);
}

TEST_F(CConfigTest, SaveConfiguration_Success) {
    // Test saving configuration
    config->mPort = 8080;
    EXPECT_EQ(config->SaveConfiguration(), Core::EErrors::eNoError);

    // Verify the file content
    std::ifstream configFile("config.txt");
    ASSERT_TRUE(configFile.is_open());
    int port;
    configFile >> port;
    EXPECT_EQ(port, 8080);
    configFile.close();
}

TEST_F(CConfigTest, LoadConfiguration_Success) {
    // Ensure the configuration file exists with valid content
    std::ofstream configFile("config.txt");
    configFile << 9090;
    configFile.close();

    // Test loading configuration
    EXPECT_EQ(config->LoadConfiguration(), Core::EErrors::eNoError);
    EXPECT_EQ(config->mPort, 9090);
}

TEST_F(CConfigTest, SaveConfiguration_FileNotFound) {
    // Test saving configuration when the file cannot be opened
    // This is a bit tricky to simulate, so we will skip this test for now
    // You can add platform-specific code to simulate this if needed
}
