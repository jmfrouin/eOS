//
// Created by Jean-Michel Frouin on 06/10/2024.
//
#include <gtest/gtest.h>
#include "Core/EOSString.h"

class CEOSStringTest : public ::testing::Test {
    protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(CEOSStringTest, EncodeBase64_EmptyString) {
    Core::CEOSString str;
    EXPECT_EQ(str.encodeBase64(), "");
}

TEST_F(CEOSStringTest, EncodeBase64_SimpleString) {
    Core::CEOSString str("Hello");
    EXPECT_EQ(str.encodeBase64(), "SGVsbG8=");
}

TEST_F(CEOSStringTest, DecodeBase64_EmptyString) {
    Core::CEOSString str;
    EXPECT_EQ(str.decodeBase64(), "");
}

TEST_F(CEOSStringTest, DecodeBase64_SimpleString) {
    Core::CEOSString str("SGVsbG8=");
    EXPECT_EQ(str.decodeBase64(), "Hello");
}

TEST_F(CEOSStringTest, EncodeDecodeBase64) {
    Core::CEOSString str("Test string for Base64 encoding and decoding.");
    std::string encoded = str.encodeBase64();
    Core::CEOSString encodedStr(encoded);
    EXPECT_EQ(encodedStr.decodeBase64(), "Test string for Base64 encoding and decoding.");
}