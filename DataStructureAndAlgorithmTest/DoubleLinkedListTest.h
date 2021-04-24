#pragma once
#include "pch.h"
#include "DoubleLinkedList.h"


#include <gtest/gtest.h>
#include "LinkedList.h"


struct DoubleLinkedListTestFixture : public testing::Test {
    DoubleLinkedList<int> testArr;
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


TEST_F(DoubleLinkedListTestFixture, Add) {
    EXPECT_EQ(10, testArr.get(0));
    EXPECT_EQ(7, testArr.get(1));
    EXPECT_EQ(15, testArr.get(2));
    EXPECT_EQ(22, testArr.get(3));
    EXPECT_EQ(9, testArr.get(4));
}

TEST_F(DoubleLinkedListTestFixture, RemoveAt) {
    EXPECT_EQ(7, testArr.removeAt(1));
}

TEST_F(DoubleLinkedListTestFixture, Remove) {
    EXPECT_EQ(true, testArr.remove(7));
}

TEST_F(DoubleLinkedListTestFixture, indexOf) {
    EXPECT_EQ(1, testArr.indexOf(7));
}

TEST_F(DoubleLinkedListTestFixture, Contains) {
    EXPECT_EQ(true, testArr.contains(7));
}

TEST_F(DoubleLinkedListTestFixture, to_string) {
    std::string ret = "10715229";
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(DoubleLinkedListTestFixture, to_string_rev) {
    std::string ret = "92215710";
    EXPECT_EQ(ret, testArr.to_string_rev(to_string));
}

TEST_F(DoubleLinkedListTestFixture, Clear) {
    testArr.clear();
    EXPECT_EQ("", testArr.to_string(to_string));
}