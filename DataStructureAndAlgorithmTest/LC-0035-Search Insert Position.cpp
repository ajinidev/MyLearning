#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class SearchInsertPosition {
public:
    int searchInsert(vector<int> nums, int target) {
        if (nums.empty())return 0;
        else if (target < nums[0]) return 0;
        else if (target > nums[nums.size() - 1]) return nums.size();
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            auto mid = (start + end) / 2;
            if (end - start <= 1) {
                if (target > nums[start]) {
                    return end;
                }
                else {
                    return end - 1;
                }
            }
            else if (nums[mid] < target) {
                start = mid;
            }
            else if (nums[mid] >= target) {
                end = mid;
            }
        }
        return end;
    }
};

TEST(SearchInsertPositionTest, TC0) {
    SearchInsertPosition tester;
    EXPECT_EQ(1, tester.searchInsert({ 1,3 }, 2));
}


TEST(SearchInsertPositionTest, TC1) {
    SearchInsertPosition tester;
    EXPECT_EQ(2, tester.searchInsert({ 1,3,5,6 }, 5));
}

TEST(SearchInsertPositionTest, TC2) {
    SearchInsertPosition tester;
    EXPECT_EQ(1, tester.searchInsert({ 1,3,5,6 }, 2));
}

TEST(SearchInsertPositionTest, TC3) {
    SearchInsertPosition tester;
    EXPECT_EQ(4, tester.searchInsert({ 1,3,5,6 }, 7));
}

TEST(SearchInsertPositionTest, TC4) {
    SearchInsertPosition tester;
    EXPECT_EQ(0, tester.searchInsert({ 1,3,5,6 }, 0));
}

TEST(SearchInsertPositionTest, TC5) {
    SearchInsertPosition tester;
    EXPECT_EQ(0, tester.searchInsert({ 1 }, 0));
}