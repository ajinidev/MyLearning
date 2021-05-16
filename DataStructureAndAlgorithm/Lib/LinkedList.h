#pragma once
#include <functional>
#include <stack>

template <class T>
class LinkedList {
    struct Node {
        Node* pNext = nullptr;
        T data;
        Node(T d) {
            data = d;
            pNext = nullptr;
        }
    };
    Node* mHead = nullptr;
public:
    ~LinkedList() {
        clear();
    }

    void add(T data) {
        auto newNode = new Node(data);
        auto lastNode = getLastNode();
        if (lastNode) {
            lastNode->pNext = newNode;
        }
        else {
            mHead = newNode;
        }
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

    void clear() {
        auto cur = mHead;
        while (cur) {
            auto temp = cur;
            cur = cur->pNext;
            delete temp;
        }
        mHead = nullptr;
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

    void reverse() {
        Node* node = mHead;
        std::stack<Node*> stack;
        while (node) {
            stack.push(node);
            node = node->pNext;
        }
        node = stack.top();
        auto head = node;
        stack.pop();
        while (!stack.empty()) {
            node->pNext = stack.top();
            node = node->pNext;
            node->pNext = nullptr;
            stack.pop();
        }
        mHead = head;
    }

private:
    Node* getLastNode() {
        auto head = mHead;
        while (head && head->pNext) {
            head = head->pNext;
        }
        return head;
    }
    void removeNode(Node* prev, Node* cur) {
        if (prev) {
            prev->pNext = cur->pNext;
        }
        else {
            mHead = cur->pNext;
        }
        delete cur;
    }
};