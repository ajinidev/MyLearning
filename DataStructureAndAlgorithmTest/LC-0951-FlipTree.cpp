#pragma once

#include "pch.h"
#include "TreeConstruction.h"
#include "BinarySearchTree.h"
#include <unordered_map>

template <class T>
class FlipTree : public TreeConstruction<T> {

public:
    void flip() {
        flip(Tree<T>::mRoot);
    }

private:
    void flip(Node* node) {
        if (node->left) {
            flip(node->left);
        }
        if (node->right) {
            flip(node->right);
        }
        auto temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
//
//struct FlipTreeTestFixture : public testing::Test {
//    FlipTree<int> tester;
//    void SetUp() override {
//    }
//    void TearDown() override {
//    }
//
//    static std::string to_string(int val) { return std::to_string(val); };
//};
//
//TEST_F(FlipTreeTestFixture, NormalTree) {
//    std::vector<int> preorder;
//    for (auto item : { 1,2,4,8,9,5,10,11,3,6,7 }) {
//        preorder.push_back(item);
//    }
//    auto inorder = { 8,4,9,2,10,5,11,1,6,3,7 };
//    tester.buildPreorderInorder_memoryEfficient(preorder, inorder);
//    tester.flip();
//    EXPECT_EQ("7361115102948", tester.inorder(to_string));
//}
//
//TEST_F(FlipTreeTestFixture, BinarySearchTree) {
//    BinarySearchTree<int> bst;
//    for (auto item : { 1,2,4,8,9,5,10,11,3,6,7 }) {
//        bst.insert(item);
//    }
//    tester.setTreeRoot(bst.getRoot());
//    tester.flip();
//    EXPECT_EQ("1110987654321", tester.inorder(to_string));
//}
