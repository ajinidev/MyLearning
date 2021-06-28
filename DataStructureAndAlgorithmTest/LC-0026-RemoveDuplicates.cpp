#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class RemoveDuplicates {
public:
    int removeDuplicates(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }
        auto idx = 1;
        for (auto cur = 1; cur < nums.size(); cur++) {
            if (nums[cur - 1] != nums[cur]) {
                nums[idx] = nums[cur];
                idx++;
            }
        }
        return idx;
    }
};

TEST(RemoveDuplicatesTest, NormalTree) {
    RemoveDuplicates tester;
    EXPECT_EQ(5, tester.removeDuplicates({ 0,0,1,1,1,2,2,3,3,4 }));
}