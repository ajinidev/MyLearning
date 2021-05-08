#pragma once
#include "LinkedList.h"

template<class Key, typename Value>
class LinearProbingHashing {

private:
    struct ListItem {
        Key key;
        Value value;
        bool operator == (ListItem item) {
            return item.key == key;
        }
        ListItem() {

        }
        ListItem(Key k, Value v) {
            key = k;
            value = v;
        }
    };
    ListItem** mList;
    std::function<int(Key)> hashingFunction;
    int mSize = 0;
    ChainingHashing() = delete;

public:
    ChainingHashing(std::function<int(Key)> hashFunc, int size) : hashingFunction(hashFunc), mSize(size) {
        mList = new ListItem*[mSize];
        for (auto& item : mList) {
            item = nullptr;
        }
    }

    void insert(Key key, Value value) {
        int idx = hashingFunction(key);
        if (idx >= mSize) {
            throw "Invalid Size!";
        }
        if (mList[idx] == nullptr) {
            mList[idx] = new ListItem(key, value);
        }
        else {
            auto initIdx = idx;
            idx = (idx++) % mSize;
            while (mList[idx] == nullptr) {
                mList[idx] = new ListItem(key, value);
                idx = (idx++) % mSize;
                if (idx == initIdx) {
                    throw "Hashtable Full";
                }
            }
        }
    }

    Value value(Key key) {
        int idx = hashingFunction(key);
        if (idx >= mSize) {
            throw "Invalid Size!";
        }
        auto item = mList[idx];
        if (item == nullptr) {
            throw "Invalid Key";
        }
        return item->value;
    }

    Value operator [] (int idx) {
        return value(idx);
    }
};