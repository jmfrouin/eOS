//
// Created by Jean-Michel Frouin on 20/10/2024.
//
#include <gtest/gtest.h>
#include <Core/Log.h>
#include <fstream>

using namespace Core;

class CLogTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Ensure the log file is not present before each test
        std::remove("test.log");
    }

    void TearDown() override {
        // Clean up the log file after each test
        std::remove("test.log");
    }
};

TEST_F(CLogTest, CreateLogFile) {
    CLog::CreateLogFile("test.log");
    std::ifstream file("test.log");
    EXPECT_TRUE(file.is_open());
    file.close();
    CLog::CloseLogFile();
}

TEST_F(CLogTest, LogMessage) {
    CLog::CreateLogFile("test.log");
    CLog::Log("Test message");
    CLog::CloseLogFile();

    std::ifstream file("test.log");
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Test message");
    file.close();
}

TEST_F(CLogTest, LogMessageWithInt) {
    CLog::CreateLogFile("test.log");
    CLog::Log("Test message", 42);
    CLog::CloseLogFile();

    std::ifstream file("test.log");
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Test message: 42");
    file.close();
}

TEST_F(CLogTest, CloseLogFile) {
    CLog::CreateLogFile("test.log");
    CLog::CloseLogFile();
    std::ifstream file("test.log");
    EXPECT_TRUE(file.is_open());
    file.close();
}