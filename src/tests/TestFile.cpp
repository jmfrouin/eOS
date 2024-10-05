#include <gtest/gtest.h>
#include <core/File.h>

TEST(CFileTest, TouchFile) {
    Core::CFile file;
    EXPECT_EQ(file.Touch("test.txt"), Core::eNoError);
}

TEST(CFileTest, OpenFile) {
    Core::CFile file;
    EXPECT_EQ(file.Open("test.txt", Core::CFile::eRead), Core::eNoError);
}

TEST(CFileTest, FileExists) {
    Core::CFile file;
    EXPECT_EQ(file.Exists("test.txt"), Core::eNoError);
}

TEST(CFileTest, CloseFile) {
    Core::CFile file;
    file.Open("test.txt", Core::CFile::eRead);
    file.Close();
    EXPECT_EQ(file.Exists("nonexistent.txt"), Core::eCannotOpenFile);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}