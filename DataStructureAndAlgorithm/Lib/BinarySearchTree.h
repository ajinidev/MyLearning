#pragma once
#include <functional>
/*
    Tree traversal
        In order    -> Left, Root, Right
        Pre order   -> Root, Left, Right
        Post order  -> Left, Right, Root

    AVL tree is a Binary search tree where the height of the left subtree and
    height of the right subtree is in the range of -1 to 1


    Rotation Logic.
    --------------------Case A-----------------------------------------------------------
    X
        Y           ------>     Left rotation.
            Z
    --------------------Case B-----------------------------------------------------------
            Z
        Y           ------>     Right rotation.
    X
    --------------------Case C-----------------------------------------------------------
    X
        Z          ------->     Right rotation on Y to Z and left rotation of Y[now z pos] to X
    Y
    --------------------Case D-----------------------------------------------------------
        Z
    X              ------->     Left rotation of X and Y. then Right rotation of Y and Z
        Y
    -------------------------------------------------------------------------------------
 */

template <class T>
class BinarySearchTree {

    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        T data;
        Node(T d) {
            left = nullptr;
            right = nullptr;
            data = d;
        }
    };

private:
    Node* mRoot = nullptr;
public:

    void insert(T data) {
        mRoot = insert(mRoot, data);
    }

    void remove(T data) {
        mRoot = remove(mRoot, data);
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

private:

    Node* insert(Node* root, T data) {
        auto node = new Node(data);
        if (root == nullptr) {
            root = node;
            return root;
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
        return balance(root);
    }

    Node* balance(Node* root) {
        auto diff = heightDiff(root);
        // Means that there are more elements on the left side.
        if (diff > 1) {
            if (heightDiff(root->left) > 0) { // left have more
                // this is Case A, solution is a right rotation.
                // LL branch.
                root = handleLL(root);
            }
            else {  // right have more
                // this is case D, solution is a Left rotation followed by right rotation
                // LR branch.
                root = handleLR(root);
            }
        }
        // Means that there are more elements on the right side.
        else if (diff < -1) {
            if (heightDiff(root->right) > 0) { // left have more
                // This is case C, solution is a right rotation followed by left rotation
                // RL branch.
                root = handleRL(root);
            }
            else { // right have more
                // this is Case B, solution is a left rotation.
                // RR branch.
                root = handleRR(root);
            }
        }
        return root;
    }

    Node* handleLL(Node* root) {
        Node* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }

    Node* handleLR(Node* root) {
        Node* newNode = root->left;
        root->left = handleRR(newNode);
        return handleLL(root);
    }

    Node* handleRL(Node* root) {
        Node* newNode = root->right;
        root->right = handleLL(newNode);
        return handleRR(root);
    }

    Node* handleRR(Node* root) {
        Node* newNode = root->right;
        root->right = newNode->left;
        newNode->left = root;
        return newNode;
    }

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

};