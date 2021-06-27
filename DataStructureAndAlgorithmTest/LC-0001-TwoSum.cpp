#pragma once
#include "pch.h"

/*
                                    Two sum Problem.

    Given an array of integers nums and an integer target, return indices of the two 
    numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not
    use the same element twice.

    You can return the answer in any order.

    Example 1:
    Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Output: Because nums[0] + nums[1] == 9, we return [0, 1].

    Example 2:
        Input: nums = [3,2,4], target = 6
        Output: [1,2]

    Example 3:
        Input: nums = [3,3], target = 6
        Output: [0,1]

    Constraints:
        2 <= nums.length <= 103
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        Only one valid answer exists.
*/

#include <unordered_map>
class TwoSum {
public:
    std::pair<int, int> solution(std::vector<int> arr, int target) {
        std::unordered_map<int, int> lookup;
        auto index = 0;
        for (auto item : arr) {
            auto diff = target - item;
            if (lookup.find(item) != lookup.end()) {
                return std::make_pair(lookup[item], index);
            }
            lookup[diff] = index;
            ++index;
        }
        return std::make_pair(0,0);
    }
};


struct TwoSumFixture : public testing::Test {
    TwoSum tester;
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(TwoSumFixture, TC1) {
    std::vector<int> input = { 2,7,11,15 };
    auto expectedResult = 9;
    auto result = tester.solution(input, expectedResult);
    EXPECT_EQ(expectedResult, input[result.first] + input[result.second]);
}

TEST_F(TwoSumFixture, TC2) {
    std::vector<int> input = { 3,2,4 };
    auto expectedResult = 6;
    auto result = tester.solution(input, expectedResult);
    EXPECT_EQ(expectedResult, input[result.first] + input[result.second]);
}

TEST_F(TwoSumFixture, TC3) {
    std::vector<int> input = { 3,3 };
    auto expectedResult = 6;
    auto result = tester.solution(input, expectedResult);
    EXPECT_EQ(expectedResult, input[result.first] + input[result.second]);
}