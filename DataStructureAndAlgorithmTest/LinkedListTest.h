#pragma once
#include "pch.h"
#include "LinkedList.h"

#include <gtest/gtest.h>
#include "LinkedList.h"

auto to_string = [](int val) { return std::to_string(val); };

struct LinkeListTestFixture : public testing::Test {
    LinkedList<int> testArr;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            testArr.add(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};


TEST_F(LinkeListTestFixture, Add) {
    EXPECT_EQ(10, testArr.get(0));
    EXPECT_EQ(7, testArr.get(1));
    EXPECT_EQ(15, testArr.get(2));
    EXPECT_EQ(22, testArr.get(3));
    EXPECT_EQ(9, testArr.get(4));
}

TEST_F(LinkeListTestFixture, RemoveAt) {
    EXPECT_EQ(7, testArr.removeAt(1));
}

TEST_F(LinkeListTestFixture, Remove) {
    EXPECT_EQ(true, testArr.remove(7));
}

TEST_F(LinkeListTestFixture, indexOf) {
    EXPECT_EQ(1, testArr.indexOf(7));
}

TEST_F(LinkeListTestFixture, Contains) {
    EXPECT_EQ(true, testArr.contains(7));
}

TEST_F(LinkeListTestFixture, Clear) {
    testArr.clear();
    EXPECT_EQ("", testArr.to_string(to_string));
}