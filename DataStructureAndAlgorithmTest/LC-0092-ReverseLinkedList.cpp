#pragma once
#include "pch.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"

struct ReverseLinkeListTestFixture : public testing::Test {
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

TEST_F(ReverseLinkeListTestFixture, Reverse) {
    testArr.reverse();
    EXPECT_EQ("92215710", testArr.to_string(to_string));
}


struct ReverseDoubleLinkeListTestFixture : public testing::Test {
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

TEST_F(ReverseDoubleLinkeListTestFixture, Reverse) {
    testArr.reverse();
    EXPECT_EQ("92215710", testArr.to_string(to_string));
}