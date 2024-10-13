//
// Created by Jean-Michel Frouin on 13/10/2024.
//
#include <gtest/gtest.h>
#include <Core/Memory.h>

using namespace Core;

TEST(CMemoryTest, Compare) {
    char buf1[] = "Hello";
    char buf2[] = "Hello";
    char buf3[] = "World";

    EXPECT_EQ(CMemory::Compare(buf1, buf2, 5), 0);
    EXPECT_NE(CMemory::Compare(buf1, buf3, 5), 0);
}

TEST(CMemoryTest, Copy) {
    char src[] = "Hello";
    char dst[6];

    CMemory::Copy(dst, src, 6);
    EXPECT_STREQ(dst, "Hello");
}

TEST(CMemoryTest, Move) {
    char src[] = "Hello";
    CMemory::Move(src + 2, src, 3);
    EXPECT_STREQ(src, "HeHel");
}

TEST(CMemoryTest, Set) {
    char buf[6];
    CMemory::Set(buf, 'A', 5);
    buf[5] = '\0';
    EXPECT_STREQ(buf, "AAAAA");
}

TEST(CMemoryTest, MallocAndFree) {
    int *array = (int *)CMemory::Malloc(10 * sizeof(int));
    ASSERT_NE(array, nullptr);

    for (int i = 0; i < 10; ++i) {
        array[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(array[i], i);
    }

    CMemory::Free(array);
}

TEST(CMemoryTest, Realloc) {
    int *array = (int *)CMemory::Malloc(5 * sizeof(int));
    ASSERT_NE(array, nullptr);

    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }

    array = (int *)CMemory::Realloc(array, 10 * sizeof(int));
    ASSERT_NE(array, nullptr);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], i);
    }

    CMemory::Free(array);
}