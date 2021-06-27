#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "BinarySearch.h"

struct BinarySearchTestFixture : public testing::Test {
    BinarySearch<int> tester;
    std::vector<int> testArr = { 1,3,5,6,7,8,9,11,15 };
    void SetUp() override {
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(BinarySearchTestFixture, FoundViaLoop) {
    EXPECT_EQ(5, tester.searchLoop(testArr, 8));
    EXPECT_EQ(0, tester.searchLoop(testArr, 1));
    EXPECT_EQ(7, tester.searchLoop(testArr, 11));
    EXPECT_EQ(8, tester.searchLoop(testArr, 15));
}

TEST_F(BinarySearchTestFixture, NotFoundViaLoop) {
    EXPECT_EQ(-1, tester.searchLoop(testArr, 10));
    EXPECT_EQ(-1, tester.searchLoop(testArr, 17));
    EXPECT_EQ(-1, tester.searchLoop(testArr, 0));
}

TEST_F(BinarySearchTestFixture, FoundViaRecursion) {
    EXPECT_EQ(5, tester.searchLoop(testArr, 8));
    EXPECT_EQ(0, tester.searchLoop(testArr, 1));
    EXPECT_EQ(7, tester.searchLoop(testArr, 11));
    EXPECT_EQ(8, tester.searchLoop(testArr, 15));
}

TEST_F(BinarySearchTestFixture, NotFoundViaRecursion) {
    EXPECT_EQ(-1, tester.searchLoop(testArr, 10));
    EXPECT_EQ(-1, tester.searchLoop(testArr, 17));
    EXPECT_EQ(-1, tester.searchLoop(testArr, 0));
}
