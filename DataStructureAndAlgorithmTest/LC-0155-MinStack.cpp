#pragma once
#include "pch.h"


/*
 Implement a container which will return the minimum value from a stack.
*/

#include <stack>

template < class T>
class MinStack {
private:
    std::stack<T> stack;
    std::stack<T> minStack;
public:

    void push(T data) {
        stack.push(data);
        if (!minStack.empty()) {
            if (data < minStack.top()) {
                minStack.push(data);
            }
        }
        else {
            minStack.push(data);
        }
    }

    T pop() {
        auto data = stack.top();
        stack.pop();
        if (data == minStack.top()) {
            minStack.pop();
        }
        return data;
    }

    T peek() {
        return stack.top();
    }

    T getMin() {
        return minStack.top();
    }
};

struct MinStackFixture : public testing::Test {
    MinStack<int> tester;
    void SetUp() override {
        tester.push(4);
        tester.push(7);
        tester.push(3);
        tester.push(5);
        tester.push(1);
        tester.push(2);
    }
    void TearDown() override {
    }
};

TEST_F(MinStackFixture, TC1) {
    EXPECT_EQ(1, tester.getMin());
}

TEST_F(MinStackFixture, TC2) {
    tester.pop();
    EXPECT_EQ(1, tester.getMin());
}

TEST_F(MinStackFixture, TC3) {
    tester.pop();
    tester.pop();
    EXPECT_EQ(3, tester.getMin());
}
