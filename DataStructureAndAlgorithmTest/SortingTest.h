#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

struct SortingTestFixture : public testing::Test {
    std::vector<int> testArr = { 7,6,9,5,15,11,8,1,3 };
    void SetUp() override {
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };

    std::string getString() {
        std::string str = "";
        for (auto a : testArr) {
            str += std::to_string(a);
        }
        return str;
    }
};

TEST_F(SortingTestFixture, BubbleSort) {
    BubbleSort<int> tester;
    tester.sort(testArr);
    EXPECT_EQ("13567891115", getString());
}

TEST_F(SortingTestFixture, SelectionSort) {
    SelectionSort<int> tester;
    tester.sort(testArr);
    EXPECT_EQ("13567891115", getString());
}

TEST_F(SortingTestFixture, InsertionSort) {
    InsertionSort<int> tester;
    tester.sort(testArr);
    EXPECT_EQ("13567891115", getString());
}

TEST_F(SortingTestFixture, QuickSort) {
    QuickSort<int> tester;
    tester.sort(testArr);
    EXPECT_EQ("13567891115", getString());
}