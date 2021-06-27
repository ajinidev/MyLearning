#pragma once
#include "pch.h"
#include <vector>
#include "Tree.h"
#include <unordered_map>
#include "TreeConstruction.h"

struct TreeConstructionTestFixture : public testing::Test {
    TreeConstruction<int> tester;
    void SetUp() override {
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(TreeConstructionTestFixture, FromInorderAndPreOrder) {
    std::vector<int> preorder;
    for (auto item : { 1,2,4,8,9,5,10,11,3,6,7 }) {
        preorder.push_back(item);
    }
    auto inorder = { 8,4,9,2,10,5,11,1,6,3,7 };
    tester.buildPreorderInorderNormal(preorder, inorder);
    EXPECT_EQ("8492105111637", tester.inorder(to_string));
}

TEST_F(TreeConstructionTestFixture, FromInorderAndPreOrder_memoryEfficient) {
    std::vector<int> preorder;
    for (auto item : { 1,2,4,8,9,5,10,11,3,6,7 }) {
        preorder.push_back(item);
    }
    auto inorder = { 8,4,9,2,10,5,11,1,6,3,7 };
    tester.buildPreorderInorder_memoryEfficient(preorder, inorder);
    EXPECT_EQ("8492105111637", tester.inorder(to_string));
}