#pragma once

#include "pch.h"
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
            preOrderReversed.push_back(preorder[preorder.size() - 1 - i]);
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