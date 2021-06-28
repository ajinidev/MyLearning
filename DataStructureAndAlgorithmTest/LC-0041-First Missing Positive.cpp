#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class MissingPositive {
public:
    int firstMissingPositive(vector<int> nums) {
        int n = nums.size();
        int i, j;
        for (i = 0; i < n; i++) {
            int cur = nums[i];
            // if in place or non-pos or out of bounds, skip.
            if (cur == i + 1 || cur <= 0 || cur > n)continue;
            swap(nums[i], nums[cur - 1]);
            // if not the same, then reprocess it.
            if (nums[i] != nums[cur - 1])
                i--;
        }

        for (i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};

TEST(MissingPositiveTest, TC1) {
    MissingPositive tester;
    EXPECT_EQ(2, tester.firstMissingPositive({ 3,4,-1,1 }));
}