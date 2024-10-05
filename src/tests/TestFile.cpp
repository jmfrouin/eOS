#include <gtest/gtest.h>
#include <Core/File.h>

TEST(CFileTest, TouchFile) {
    Core::CFile File;
    EXPECT_EQ(File.Touch("test.txt"), Core::eNoError);
}

TEST(CFileTest, OpenFile) {
    Core::CFile File;
    EXPECT_EQ(File.Open("test.txt", Core::CFile::eRead), Core::eNoError);
}

TEST(CFileTest, FileExists) {
    Core::CFile File;
    EXPECT_EQ(File.Exists("test.txt"), Core::eNoError);
}

TEST(CFileTest, RemoveExistingFile) {
    Core::CFile File;
    EXPECT_EQ(File.Remove("test.txt"), Core::eNoError);
}

TEST(CFileTest, RemoveMissingFile) {
    Core::CFile File;
    EXPECT_EQ(File.Remove("test.txt"), Core::eCannotOpenFile);
}
TEST(CFileTest, CloseFile) {
    Core::CFile File;
    EXPECT_EQ(File.Exists("test.txt"), Core::eCannotOpenFile);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}