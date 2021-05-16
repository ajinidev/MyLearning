#pragma once
#include <functional>

template <class T>
class Tree {

protected:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        T data;
        Node() = default;
        Node(T d) {
            left = nullptr;
            right = nullptr;
            data = d;
        }
    };
    Node* mRoot = nullptr;

public:
    Node* getRoot() { return mRoot; }
    void setTreeRoot(Node* root) {
        clear(mRoot);
        mRoot = root;
    }

    std::string preorder(std::function<std::string(T)> to_string) {
        return preorder(mRoot, to_string);
    }

    std::string inorder(std::function<std::string(T)> to_string) {
        return inorder(mRoot, to_string);
    }

    std::string postorder(std::function<std::string(T)> to_string) {
        return postorder(mRoot, to_string);
    }

    std::string bfsOrder(std::function<std::string(T)> to_string) {
        Queue<Node*, LinkedList<Node*>> queue;
        std::string out = "";
        queue.enqueue(mRoot);
        while (!queue.isEmpty()) {
            Node* node = queue.dequeue();
            if (node->left) {
                queue.enqueue(node->left);
            }
            if (node->right) {
                queue.enqueue(node->right);
            }
            out += to_string(node->data);
        }
        return out;
    }

    bool isEmpty() {
        return mRoot == nullptr;
    }

    void clear() {
        clear(mRoot);
        mRoot = nullptr;
    }

protected:
    int height(Node* node) {
        return (node) ? std::max(height(node->left), height(node->right)) + 1 : 0;
    }

    int heightDiff(Node* node) {
        return height(node->left) - height(node->right);
    }

    std::string preorder(Node* node, std::function<std::string(T)> to_string) {
        if (node == nullptr) return "";
        return to_string(node->data) + preorder(node->left, to_string) + preorder(node->right, to_string);
    }

    std::string inorder(Node* node, std::function<std::string(T)> to_string) {
        if (node == nullptr) return "";
        return inorder(node->left, to_string) + to_string(node->data) + inorder(node->right, to_string);
    }

    std::string postorder(Node* node, std::function<std::string(T)> to_string) {
        if (node == nullptr) return "";
        return postorder(node->left, to_string) + postorder(node->right, to_string) + to_string(node->data);
    }

    void clear(Node* root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }
};