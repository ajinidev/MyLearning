#pragma once
#include <gtest/gtest.h>
#include "Tree.h"
#include <stack>

template <class T>
class BSTFromPreOrder : public Tree<T> {

public:
    void create(const std::vector<T>& preorder) {
        std::stack<Node*> stack;
        Node* root = new Node(preorder[0]);
        stack.push(root);
        for (auto idx = 1; idx < preorder.size(); idx++) {
            auto item = preorder[idx];
            auto top = stack.top();
            if (top->data > item) {
                top->left = new Node(item);
                stack.push(top->left);
            }
            else {
                while (!stack.empty() && (stack.top()->data <= item)) {
                    top = stack.top();
                    stack.pop();
                }
                top->right = new Node(item);
                stack.push(top->right);
            }
        }
        setTreeRoot(root);
    }
};

struct BSTFromPreOrderTestFixture : public testing::Test {
    BSTFromPreOrder<int> tester;
    void SetUp() override {
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(BSTFromPreOrderTestFixture, NormalTree) {
    tester.create({ 4,2,1,3,8,6,5,7,10,9,11 });
    EXPECT_EQ("1234567891011", tester.inorder(to_string));
}
