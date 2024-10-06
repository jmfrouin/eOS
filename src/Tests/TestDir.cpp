#include <gtest/gtest.h>
#include <Core/Dir.h>
#include <filesystem>
#include <fstream>

class CDirTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a test directory structure
        std::filesystem::create_directory("test_dir");
        std::filesystem::create_directory("test_dir/subdir");
        std::ofstream("test_dir/file.txt");
    }

    void TearDown() override {
        // Clean up the test directory structure
        std::filesystem::remove_all("test_dir");
    }
};

TEST_F(CDirTest, CD) {
    Core::CDir dir;
    dir.ChRoot("test_dir");
    EXPECT_TRUE(dir.CD("subdir"));
    EXPECT_EQ(dir.Dir(), "test_dir/subdir");
}

TEST_F(CDirTest, CDUp) {
    Core::CDir dir;
    dir.ChRoot("test_dir/subdir");
    EXPECT_TRUE(dir.CDUp());
    EXPECT_EQ(dir.Dir(), "test_dir");
}

TEST_F(CDirTest, ChRoot) {
    Core::CDir dir;
    EXPECT_TRUE(dir.ChRoot("test_dir"));
    EXPECT_EQ(dir.Dir(), "test_dir");
}

TEST_F(CDirTest, Name) {
    Core::CDir dir;
    dir.ChRoot("test_dir");
    EXPECT_EQ(dir.Name(), "test_dir");
}

TEST_F(CDirTest, Normalize) {
    std::string path = "test\\dir";
    EXPECT_EQ(Core::CDir::Normalize(path), "test/dir");
}

TEST_F(CDirTest, mkdir) {
    EXPECT_TRUE(Core::CDir::mkdir("test_dir/new_dir"));
    EXPECT_TRUE(std::filesystem::exists("test_dir/new_dir"));
}

TEST_F(CDirTest, rmdir) {
    EXPECT_TRUE(Core::CDir::rmdir("test_dir/subdir"));
    EXPECT_FALSE(std::filesystem::exists("test_dir/subdir"));
}