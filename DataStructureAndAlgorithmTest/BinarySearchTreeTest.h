#pragma once
#include "pch.h"


#include <gtest/gtest.h>
#include "BinarySearchTree.h"


struct CircularQueueTestFixture : public testing::Test {
    BinarySearchTree<int> tester;
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            tester.insert(item);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(CircularQueueTestFixture, InOrder) {
    EXPECT_EQ("79101522", tester.inorder(to_string));
}

TEST_F(CircularQueueTestFixture, PreOrder) {
    EXPECT_EQ("10791522", tester.preorder(to_string));
}

TEST_F(CircularQueueTestFixture, PostOrder) {
    EXPECT_EQ("97221510", tester.postorder(to_string));
}