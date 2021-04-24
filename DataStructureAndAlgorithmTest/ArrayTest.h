#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "Array.h"

struct ArrayTestFixture : public testing::Test {
    Array<int> testArr;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            testArr.add(item);
        }
    }
    void TearDown() override {
    }
};


TEST_F(ArrayTestFixture, Add) {
    EXPECT_EQ(10, testArr.get(0));
    EXPECT_EQ(7, testArr.get(1));
    EXPECT_EQ(15, testArr.get(2));
    EXPECT_EQ(22, testArr.get(3));
    EXPECT_EQ(9, testArr.get(4));
}

TEST_F(ArrayTestFixture, RemoveAt) {
    EXPECT_EQ(7, testArr.removeAt(1));
}

TEST_F(ArrayTestFixture, Remove) {
    EXPECT_EQ(true, testArr.remove(7));
}

TEST_F(ArrayTestFixture, indexOf) {
    EXPECT_EQ(1, testArr.indexOf(7));
}

TEST_F(ArrayTestFixture, Contains) {
    EXPECT_EQ(true, testArr.contains(7));
}