#pragma once

#include "pch.h"
#include "Stack.h"
#include "LinkedList.h"
#include <gtest/gtest.h>

class BracketSymmetryProblem {

public:
    bool isValidBrackets(std::string brackets) {
        Stack<char, LinkedList<char>> stack;
        for (auto c : brackets) {
            auto rev = getReverse(c);
            if (isPushable(c)) {
                stack.push(c);
            }
            else if (stack.isEmpty() || stack.pop() != rev) {
                return false;
            }
        }
        return stack.isEmpty();
    }

private:
    bool isPushable(char c) {
        return (c == '[') || (c == '(') || (c == '{');
    }

    char getReverse(char c) {
        switch (c) {
        case '}': return '{';
        case ')': return '(';
        case ']': return '[';
        default: return ' ';
        }
    }
};


TEST(BracketSymmetryProblem, Pass) {
    BracketSymmetryProblem tester;
    EXPECT_EQ(false, tester.isValidBrackets("[{})[]"));
}

TEST(BracketSymmetryProblem, Fail) {
    BracketSymmetryProblem tester;
    EXPECT_EQ(true, tester.isValidBrackets("[[{}]()]"));
}