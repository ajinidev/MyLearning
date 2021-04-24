#pragma once
#include "pch.h"
#include <functional>

template <class T>
class DoubleLinkedList {
    struct Node {
        Node* pNext = nullptr;
        Node* pPrev = nullptr;
        T data;
        Node(T d) {
            data = d;
            pNext = nullptr;
        }
    };
    Node* mHead = nullptr;
    Node* mTail = nullptr;

public:
    ~DoubleLinkedList() {
        clear();
    }
    void add(T data) {
        auto newNode = new Node(data);
        auto lastNode = getLastNode();
        if (lastNode) {
            newNode->pPrev = lastNode;
            lastNode->pNext = newNode;
        }
        else {
            mHead = newNode;
        }
        mTail = newNode;
    }

    T removeAt(int idx) {
        if (idx < 0) {
            throw "Invalid Index";
        }
        auto cur = mHead;
        Node* prev = nullptr;
        auto i = 0;
        while (cur) {
            if (idx == i) {
                auto data = cur->data;
                removeNode(prev, cur);
                return data;
            }
            prev = cur;
            cur = cur->pNext;
            i++;
        }
        throw "Invalid Index";
    }

    bool remove(T data) {
        auto cur = mHead;
        Node* prev = nullptr;
        while (cur) {
            if (cur->data == data) {
                removeNode(prev, cur);
                return true;
            }
            prev = cur;
            cur = cur->pNext;
        }
        return false;
    }

    T get(int idx) {
        auto cur = mHead;
        auto i = 0;
        while (cur) {
            if (idx == i) {
                return cur->data;
            }
            cur = cur->pNext;
            i++;
        }
        throw "Invalid Index";
    }

    int size() {
        int size = 0;
        auto head = mHead;
        while (head) {
            head = head->pNext;
            size++;
        }
        return size;
    }

    int indexOf(T data) {
        auto cur = mHead;
        auto i = 0;
        while (cur) {
            if (cur->data == data) {
                return i;
            }
            cur = cur->pNext;
            i++;
        }
        return -1;
    }

    bool contains(T data) {
        return indexOf(data) != -1;
    }

    std::string to_string(std::function<std::string(T)> to_string) {
        std::string str = "";
        auto cur = mHead;
        while (cur) {
            str += to_string(cur->data);
            cur = cur->pNext;
        }
        return str;
    }

    std::string to_string_rev(std::function<std::string(T)> to_string) {
        std::string str = "";
        auto cur = mTail;
        while (cur) {
            str += to_string(cur->data);
            cur = cur->pPrev;
        }
        return str;
    }
    void clear() {
        auto cur = mHead;
        while (cur) {
            auto temp = cur;
            cur = cur->pNext;
            delete temp;
        }
        mHead = nullptr;
        mTail = nullptr;
    }

private:
    Node* getLastNode() {
        return mTail;
    }
    void removeNode(Node* prev, Node* cur) {
        if (prev) {
            prev->pNext = cur->pNext;
            cur->pPrev = prev;
            if (prev->pNext == nullptr) {
                mTail = prev;
            }
        }
        else {
            mHead = cur->pNext;
            cur->pPrev = nullptr;
            if (mHead == nullptr) {
                mTail = nullptr;
            }
            else if (mHead->pNext == nullptr) {
                mTail = mHead;
            }
        }
        delete cur;
    }
};