#pragma once
#include "Queue.h"
#include "LinkedList.h"
#include "Tree.h"
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
class BinarySearchTree : public Tree<T>{
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

    bool contains(T data) {
        return contains(data, mRoot);
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