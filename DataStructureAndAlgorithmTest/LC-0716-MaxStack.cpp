#pragma once
#include "pch.h"

/*
 Implement a container which will return the maximum value from a stack.
*/

#include <stack>

template < class T>
class MaxStack {
private:
    std::stack<T> stack;
    std::stack<T> maxStack;
public:

    void push(T data) {
        stack.push(data);
        if (!maxStack.empty()) {
            if (data > maxStack.top()) {
                maxStack.push(data);
            }
        }
        else {
            maxStack.push(data);
        }
    }

    T pop() {
        auto data = stack.top();
        stack.pop();
        if (data == maxStack.top()) {
            maxStack.pop();
        }
        return data;
    }

    T peek() {
        return stack.top();
    }

    T getMin() {
        return maxStack.top();
    }
};

struct MaxStackFixture : public testing::Test {
    MaxStack<int> tester;
    void SetUp() override {
        tester.push(4);
        tester.push(7);
        tester.push(3);
        tester.push(5);
    }
    void TearDown() override {
    }
};

TEST_F(MaxStackFixture, TC1) {
    EXPECT_EQ(7, tester.getMin());
}

TEST_F(MaxStackFixture, TC2) {
    tester.pop();
    EXPECT_EQ(7, tester.getMin());
}

TEST_F(MaxStackFixture, TC3) {
    tester.pop();
    tester.pop();
    tester.pop();
    EXPECT_EQ(4, tester.getMin());
}
