#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class RemoveElement {
public:
    int removeElement(vector<int> nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        auto idx = 0;
        for (auto cur: nums) {
            if (cur != val) {
                nums[idx] = cur;
                idx++;
            }
        }
        return idx;
    }
};

TEST(RemoveElementTest, TC1) {
    RemoveElement tester;
    EXPECT_EQ(5, tester.removeElement({ 0,1,2,2,3,0,4,2 }, 2));
}