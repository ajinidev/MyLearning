#pragma once
#include "pch.h"

#include <gtest/gtest.h>
#include "LinkedList.h"
#include "Stack.h"

struct StackTestFixtureWithLinkedList : public testing::Test {
    Stack<int, LinkedList<int>> testArr;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            testArr.push(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(StackTestFixtureWithLinkedList, Push) {
    std::string ret = "10715229";
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(StackTestFixtureWithLinkedList, Pop) {
    std::string ret = "1071522";
    testArr.pop();
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(StackTestFixtureWithLinkedList, Clear) {
    testArr.clear();
    EXPECT_EQ("", testArr.to_string(to_string));
}