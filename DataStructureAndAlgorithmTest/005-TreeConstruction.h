#pragma once
#include <vector>
#include <gtest/gtest.h>
#include "Tree.h"
#include <unordered_map>

template <class T>
class TreeConstruction : public Tree<T> {

public:
    void buildPreorderInorderNormal(std::vector<T> preorder, std::vector<T> inorder) {
        mRoot = buildPreorderInorder(preorder, inorder);
    }
    void buildPreorderInorder_memoryEfficient(std::vector<T> preorder, std::vector<T> inorder) {
        std::unordered_map<T, int> map;
        if (inorder.size() != preorder.size()) {
            throw "Invalid input.";
        }
        std::vector<T> preOrderReversed;
        for (auto i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
            preOrderReversed.push_back(preorder[preorder.size() - 1 -i]);
        }
        mRoot = buildPreorderInorder(preOrderReversed, 0, preOrderReversed.size(), map);
    }
private:
    Node* buildPreorderInorder(std::vector<T>& preorder, std::vector<T> inorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        if (preorder.size() == 1) {
            return new Node(preorder[0]);
        }
        int idx = getIndexOf(inorder, preorder[0]);
        preorder.erase(preorder.begin());
        Node* node = new Node(inorder[idx]);
        node->left = buildPreorderInorder(preorder, std::vector<T>(inorder.begin(), inorder.begin() + idx));
        node->right = buildPreorderInorder(preorder, std::vector<T>(inorder.begin() + idx + 1, inorder.end()));
        return node;
    }

    Node* buildPreorderInorder(std::vector<T>& preOrderReversed, int leftIdx,
        int rightIdx, std::unordered_map<T, int> map) {
        if (leftIdx >= rightIdx) return nullptr;
        auto data = preOrderReversed[preOrderReversed.size() - 1];
        preOrderReversed.pop_back();

        Node* node = new Node(data);
        int idx = map[data];
        node->left = buildPreorderInorder(preOrderReversed, leftIdx, idx, map);
        node->right = buildPreorderInorder(preOrderReversed, idx + 1, rightIdx, map);
        return node;
    }

    int getIndexOf(std::vector<T> arr, T value) {
        auto idx = 0;
        for (auto item : arr) {
            if (item == value) {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};

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