#pragma once
#include <functional>
#include "Queue.h"
#include "LinkedList.h"
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

    BinarySearchTree() {
        mRoot = nullptr;
    }

    ~BinarySearchTree() {
        clear();
    }

    void insert(T data) {
        mRoot = insert(mRoot, data);
    }

    void remove(T data) {
        mRoot = remove(mRoot, data);
    }

    bool isEmpty() {
        return mRoot == nullptr;
    }

    bool contains(T data) {
        return contains(data, mRoot);
    }

    void clear() {
        clear(mRoot);
        mRoot = nullptr;
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

    Node* remove(Node* root, T data) {
        if (root == nullptr)
            return nullptr;

        if (data < root->data) {
            root->left = remove(root->left, data);
        }
        else if (data > root->data) {
            root->right = remove(root->right, data);
        }
        else {
            // Check if it a leaf.
            if (root->right == nullptr && root->left == nullptr) {
                delete root;
                return nullptr;
            }

            Node* newNode = getAndRemoveLargestNode(root);
            if (newNode == nullptr) {
                // this means that this node doesnt have a right child. so the new node will be the left child.
                newNode = root->left;
            }
            else {
                newNode->left = root->left;
                newNode->right = root->right;
            }
            delete root;
            root = balance(newNode);
        }
        return root;
    }

    bool contains(T data, Node* root) {
        if (root == nullptr) return false;
        if (data < root->data) {
            return contains(data, root->left);
        }
        else if (data > root->data) {
            return contains(data, root->right);
        }
        return true;
    }

    void clear(Node* root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
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

    Node* getAndRemoveLargestNode(Node* root) {
        auto parent = root;
        auto child = parent->right;
        while (child) {
            if (child->right == nullptr) {
                parent->right = nullptr;
                break;
            }
            parent = child;
            child = child->right;
        }
        return child;
    }
};