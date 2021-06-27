#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "DoubleLinkedList.h"
#include "Stack.h"


struct StackTestFixtureWithDoubleLinkedList : public testing::Test {
    Stack<int, DoubleLinkedList<int>> testArr;
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

TEST_F(StackTestFixtureWithDoubleLinkedList, Push) {
    std::string ret = "10715229";
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(StackTestFixtureWithDoubleLinkedList, Pop) {
    std::string ret = "1071522";
    testArr.pop();
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(StackTestFixtureWithDoubleLinkedList, Clear) {
    testArr.clear();
    EXPECT_EQ("", testArr.to_string(to_string));
}