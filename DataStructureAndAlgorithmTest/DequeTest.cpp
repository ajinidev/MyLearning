#pragma once

#include "pch.h"
#include <gtest/gtest.h>
#include "Deque.h"


struct DequeTestFixture : public testing::Test {
    Deque<int> tester;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            tester.insertRear(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(DequeTestFixture, Base) {
    EXPECT_EQ("10715229", tester.to_string(to_string));
}

TEST_F(DequeTestFixture, InsertRear) {
    tester.insertRear(7);
    EXPECT_EQ("107152297", tester.to_string(to_string));
}

TEST_F(DequeTestFixture, RemoveFront) {
    tester.removeFront();
    EXPECT_EQ("715229", tester.to_string(to_string));
}

TEST_F(DequeTestFixture, InsertFront) {
    tester.insertFront(7);
    EXPECT_EQ("710715229", tester.to_string(to_string));
}

TEST_F(DequeTestFixture, RemoveRear) {
    tester.removeRear();
    EXPECT_EQ("1071522", tester.to_string(to_string));
}

TEST_F(DequeTestFixture, Combination) {
    tester.insertRear(7);
    tester.removeFront();
    tester.removeFront();
    tester.removeFront();
    tester.removeFront();
    tester.removeFront();
    tester.insertRear(7);
    tester.removeFront();
    tester.removeFront();
    EXPECT_EQ("", tester.to_string(to_string));
}