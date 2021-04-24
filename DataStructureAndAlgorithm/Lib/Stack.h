#pragma once
#include <functional>

template <class T, typename Container>
class Stack {

private:
    int mSize = 0;
    Container mContainer;

public:
    void push(T data) {
        mContainer.add(data);
        mSize++;
    }

    T pop() {
        return mContainer.removeAt(--mSize);
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