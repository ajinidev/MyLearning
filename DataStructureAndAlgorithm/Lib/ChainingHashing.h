#pragma once
#include "LinkedList.h"

template<class Key, typename Value>
class ChainingHashing {

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
    LinkedList<ListItem>* mList;
    std::function<int(Key)> hashingFunction;
    int mSize = 0;
    ChainingHashing() = delete;
public:
    ChainingHashing(std::function<int(Key)> hashFunc, int size) : hashingFunction(hashFunc), mSize(size){
        mList = new LinkedList<ListItem>[mSize];
    }

    void insert(Key key, Value value) {
        int idx = hashingFunction(key);
        if (idx >= mSize) {
            throw "Invalid Size!";
        }
        mList[idx].add(ListItem(key, value));
    }

    Value value(Key key) {
        int idx = hashingFunction(key);
        if (idx >= mSize) {
            throw "Invalid Size!";
        }
        ListItem searchItem;
        searchItem.key = key;
        auto llIdx = mList[idx].indexOf(searchItem);
        if (llIdx < 0) {
            throw "Invalid Key.";
        }
        return mList[idx].get(llIdx).value;
    }

    Value operator [] (int idx) {
        return value(idx);
    }
};