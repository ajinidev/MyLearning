#pragma once
#include "pch.h"

#include <gtest/gtest.h>
#include "LinkedList.h"
#include "Queue.h"

struct QueueTestFixtureWithLinkedList : public testing::Test {
    Queue<int, LinkedList<int>> testArr;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            testArr.enqueue(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(QueueTestFixtureWithLinkedList, Push) {
    std::string ret = "10715229";
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(QueueTestFixtureWithLinkedList, Pop) {
    std::string ret = "715229";
    testArr.dequeue();
    EXPECT_EQ(ret, testArr.to_string(to_string));
}

TEST_F(QueueTestFixtureWithLinkedList, Clear) {
    testArr.clear();
    EXPECT_EQ("", testArr.to_string(to_string));
}