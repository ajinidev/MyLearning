#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "BinarySearchTree.h"

struct BinarySearchTreeTestFixture : public testing::Test {
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

TEST_F(BinarySearchTreeTestFixture, InOrder) {
    EXPECT_EQ("79101522", tester.inorder(to_string));
}

TEST_F(BinarySearchTreeTestFixture, PreOrder) {
    EXPECT_EQ("10791522", tester.preorder(to_string));
}

TEST_F(BinarySearchTreeTestFixture, PostOrder) {
    EXPECT_EQ("97221510", tester.postorder(to_string));
}

TEST_F(BinarySearchTreeTestFixture, RemoveAndPrintInOrder) {
    tester.remove(7);
    EXPECT_EQ("9101522", tester.inorder(to_string));
    tester.remove(22);
    EXPECT_EQ("91015", tester.inorder(to_string));
    tester.remove(22);
    tester.remove(10);
    EXPECT_EQ("915", tester.inorder(to_string));
    tester.remove(15);
    EXPECT_EQ("9", tester.inorder(to_string));
    tester.remove(7);
    EXPECT_EQ("9", tester.inorder(to_string));
    tester.remove(9);
    EXPECT_EQ("", tester.inorder(to_string));
    tester.remove(99999);
    EXPECT_EQ("", tester.inorder(to_string));
}

TEST_F(BinarySearchTreeTestFixture, Contains) {
    EXPECT_EQ(true, tester.contains(10));
    EXPECT_EQ(true, tester.contains(9));
    EXPECT_EQ(true, tester.contains(15));
    EXPECT_EQ(true, tester.contains(22));
    EXPECT_EQ(true, tester.contains(7));
}

TEST_F(BinarySearchTreeTestFixture, DoesnotContains) {
    EXPECT_EQ(false, tester.contains(77));
    EXPECT_EQ(false, tester.contains(1));
}

TEST_F(BinarySearchTreeTestFixture, IsEmptyAndClear) {
    tester.clear();
    EXPECT_EQ(true, tester.isEmpty());
}

TEST_F(BinarySearchTreeTestFixture, IsNotEmpty) {
    EXPECT_EQ(false, tester.isEmpty());
}