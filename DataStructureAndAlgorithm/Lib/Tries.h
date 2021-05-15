#pragma once
#include <string>
#include <cctype>

template <class T>
class Trie {

    struct Node {
        Node* next[26] = { 0 };
        T data;
    };

    Node mNode;
    T mDefault;
public:
    void setDefaultValue(T def) { mDefault = def; }
    void insert(std::string path, T value) {
        insert(to_lower(path), value, &mNode);
    }

    void remove(std::string path) {
        remove(to_lower(path), &mNode);
    }

    T getValue(std::string path) {
        return getValue(to_lower(path), &mNode);
    }

private:
    std::string to_lower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
        return str;
    }

    int getIdx(const std::string& path) {
        auto idx = static_cast<int>(path[0] - 'a');
        if (idx < 0 || idx > 26) {
            throw "Invalid Character Found.";
        }
        return idx;
    }

    void insert(std::string path, T value, Node* node) {
        if (path.empty()) {
            node->data = value;
        }
        else {
            int idx = getIdx(path);
            if (node->next[idx] == nullptr) {
                node->next[idx] = new Node();
            }
            insert(path.substr(1, path.size() - 1), value, node->next[idx]);
        }
    }

    void remove(std::string path, Node* node) {
        if (path.empty()) {
            node->data = mDefault;
        }
        else {
            if (node == nullptr) {
                return;
            }
            int idx = getIdx(path);
            if (node->next[idx] != nullptr) {
                remove(path.substr(1, path.size() - 1), node->next[idx]);
            }
        }
    }

    T getValue(std::string path, Node* node) {
        if (path.empty()) {
            return (node) ? node->data : mDefault;
        }
        else if (node != nullptr) {
            int idx = getIdx(path);
            if (node->next[idx] != nullptr) {
                return getValue(path.substr(1, path.size() - 1), node->next[idx]);
            }
        }
        return mDefault;
    }
};