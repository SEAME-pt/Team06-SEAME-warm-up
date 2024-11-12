#include <gtest/gtest.h>
#include "../inc/ex02.hpp"

// Test the convertUp function
TEST(ConvertUpTest, BasicTest) {
    string test_str = "hello";
    EXPECT_EQ(convertUp(test_str), "HELLO");
}

TEST(ConvertUpTest, AlreadyUpperCase) {
    string test_str = "HELLO";
    EXPECT_EQ(convertUp(test_str), "HELLO");
}

TEST(ConvertUpTest, MixedCase) {
    string test_str = "HeLLo";
    EXPECT_EQ(convertUp(test_str), "HELLO");
}

// Test the convertDown function
TEST(ConvertDownTest, BasicTest) {
    string test_str = "HELLO";
    EXPECT_EQ(convertDown(test_str), "hello");
}

TEST(ConvertDownTest, AlreadyLowerCase) {
    string test_str = "hello";
    EXPECT_EQ(convertDown(test_str), "hello");
}

TEST(ConvertDownTest, MixedCase) {
    string test_str = "HeLLo";
    EXPECT_EQ(convertDown(test_str), "hello");
}
