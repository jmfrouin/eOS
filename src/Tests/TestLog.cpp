#include <gtest/gtest.h>
#include <Core/Log.h>
#include <fstream>

using namespace Core;

class CLogTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Ensure the log file is not present before each test
        std::remove("eOS.log");
    }

    void TearDown() override {
        // Clean up the log file after each test
        std::remove("eOS.log");
    }
};

TEST_F(CLogTest, LogMessage) {
    CLog::Log(__FILE__, __LINE__, "Test message");
    std::ifstream file("eOS.log");
    std::string line;
    std::getline(file, line);
    EXPECT_NE(line.find("Test message"), std::string::npos);
    file.close();
}

TEST_F(CLogTest, LogMessageWithInt) {
    CLog::Log(__FILE__, __LINE__, "Test message", 42);
    std::ifstream file("eOS.log");
    std::string line;
    std::getline(file, line);
    EXPECT_NE(line.find("Test message"), std::string::npos);
    EXPECT_NE(line.find("42"), std::string::npos);
    file.close();
}

TEST_F(CLogTest, LogMessageWithString) {
    CLog::Log(__FILE__, __LINE__, "Test message", "additional info");
    std::ifstream file("eOS.log");
    std::string line;
    std::getline(file, line);
    EXPECT_NE(line.find("Test message"), std::string::npos);
    EXPECT_NE(line.find("additional info"), std::string::npos);
    file.close();
}