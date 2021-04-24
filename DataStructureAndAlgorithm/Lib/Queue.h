#pragma once
#include "pch.h"
#include <functional>

template <class T, typename Container>
class Queue {

private:
    int mSize = 0;
    Container mContainer;

public:
    void enqueue(T data) {
        mContainer.add(data);
        mSize++;
    }

    T dequeue() {
        --mSize;
        if (mSize < 0) {
            throw "Empty Queue";
        }
        return mContainer.removeAt(0);
    }

    T get(int idx) {
        return mContainer.get(idx);
    }

    std::string to_string(std::function<std::string(T)> to_string) {
        return mContainer.to_string(to_string);
    }

    void clear() {
        mContainer.clear();
        mSize = 0;
    }

    int size() {
        return mSize;
    }

    bool isEmpty() {
        return mSize == 0;
    }
};