#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:

    vector<vector<int>> threeSum(vector<int> nums) {
        unordered_map<int, int> lookup;
        multimap<int, pair<int, int>> map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)continue;
                auto x = make_pair(-1 * (nums[i] + nums[j]), make_pair(i, j));
                map.insert(x);
                lookup[-1 * (nums[i] + nums[j])] = 1;
            }
        }
        set<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            if (0 == lookup[nums[i]]) continue;
            auto range = map.equal_range(nums[i]);
            for (auto start = range.first; start != range.second; start++) {
                if (i == start->second.first || i == start->second.second) {
                    continue;
                }
                vector<int> tt = { nums[i], nums[start->second.first], nums[start->second.second] };
                sort(tt.begin(), tt.end());
                results.insert(tt);
            }
        }
        vector<vector<int>> ret;
        for (auto& i : results) {
            ret.push_back(i);
        }
        return ret;
    }
};

string to_string(vector<vector<int>> result) {
    vector<int> resString;
    for (auto item : result) {
        for (auto s : item) {
            resString.push_back(s);
        }
    }
    sort(resString.begin(), resString.end());
    string res;
    for (auto s : resString) {
        res += to_string(s);
    }
    return res;
}

TEST(ThreeSum, TC1) {
    Solution tester;
    vector<vector<int>> result = {
        { -1,-1,2 }, { -1,0,1 }
    };
    EXPECT_EQ(to_string(result), to_string(tester.threeSum({ -1,0,1,2,-1,-4 })));
}

TEST(ThreeSum, TC2) {
    Solution tester;
    vector<vector<int>> result = {
    };
    EXPECT_EQ(to_string(result), to_string(tester.threeSum({  })));
}

TEST(ThreeSum, TC3) {
    Solution tester;
    vector<vector<int>> result = {

    };
    EXPECT_EQ(to_string(result), to_string(tester.threeSum({ 0 })));
}