#pragma once

#include "pch.h"
#include <gtest/gtest.h>
#include "CircularQueue.h"


struct CircularQueueTestFixture: public testing::Test {
    CircularQueue<int> tester;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            tester.enqueue(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(CircularQueueTestFixture, Base) {
    EXPECT_EQ("10715229", tester.to_string(to_string));
}

TEST_F(CircularQueueTestFixture, Enqueue) {
    tester.enqueue(7);
    EXPECT_EQ("107152297", tester.to_string(to_string));
}

TEST_F(CircularQueueTestFixture, Dequeue) {
    tester.dequeue();
    EXPECT_EQ("715229", tester.to_string(to_string));
}

TEST_F(CircularQueueTestFixture, Combination) {
    tester.enqueue(7);
    tester.dequeue();
    tester.dequeue();
    tester.dequeue();
    tester.dequeue();
    tester.dequeue();
    tester.enqueue(7);
    tester.dequeue();
    tester.dequeue();
    EXPECT_EQ("", tester.to_string(to_string));
}