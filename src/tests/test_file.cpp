//
// Created by Jean-Michel Frouin on 05/10/2024.
//
#include <gtest/gtest.h>
#include <core/file.h>

TEST(CFileTest, OpenFile) {
    CFile file;
    EXPECT_FALSE(file.Open("test.txt", CFile::eRead));
}

TEST(CFileTest, FileExists) {
    CFile file;
    EXPECT_FALSE(file.Exists("test.txt"));
}

TEST(CFileTest, CloseFile) {
    CFile file;
    file.Open("test.txt", CFile::eRead);
    file.Close();
    EXPECT_FALSE(file.Exists("nonexistent.txt"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}