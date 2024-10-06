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

TEST(CFileTest, FileSize) {
    Core::CFile File;
    Core::CFile::Touch("test.txt");
    File.Open("test.txt", Core::CFile::eWrite);
    File.Write("Hello, World!");
    File.Close();
    File.Open("test.txt", Core::CFile::eRead);
    EXPECT_EQ(File.Size(), 13);
    File.Close();
}

TEST(CFileTest, FileSeek) {
    Core::CFile File;
    Core::CFile::Touch("test.txt");
    File.Open("test.txt", Core::CFile::eWrite);
    File.Write("Hello, World!");
    File.Close();
    File.Open("test.txt", Core::CFile::eRead);
    EXPECT_EQ(File.Seek(5, SEEK_SET), 0);
    File.Close();
}

TEST(CFileTest, FileTell) {
    Core::CFile File;
    Core::CFile::Touch("test.txt");
    File.Open("test.txt", Core::CFile::eWrite);
    File.Write("Hello, World!");
    File.Close();
    File.Open("test.txt", Core::CFile::eRead);
    EXPECT_EQ(File.Tell(), 0);
    File.Seek(5, SEEK_SET);
    EXPECT_EQ(File.Tell(), 5);
    File.Close();
}

TEST(CFileTest, FileRead) {
    Core::CFile File;
    Core::CFile::Touch("test.txt");
    File.Open("test.txt", Core::CFile::eWrite);
    File.Write("Hello, World!");
    File.Close();
    File.Open("test.txt", Core::CFile::eRead);
    char buffer[14] = {0};
    EXPECT_EQ(File.Read(buffer, 1, 13), 13);
    EXPECT_STREQ(buffer, "Hello, World!");
    File.Close();
}