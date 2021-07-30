#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isFound(string substr, vector<string>& strs) {
        bool found = true;
        for (auto str : strs) {
            if (str.substr(0, substr.size()) != substr) {
                found = false; break;
            }
        }
        return found;
    }
    string longestCommonPrefix(vector<string> strs) {
        unordered_map<string, int> map;
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        auto first = strs[0];
        int start = 0; int end = first.size();
        while (start < end) {
            auto mid = (start + end + 1) / 2;
            auto substr = first.substr(0, mid);
            auto found = map[substr] == 1 ? true : isFound(substr, strs);
            if (found) {
                map[substr] = 1;
                start = mid;
            }
            else {
                auto prevstr = substr.substr(0, substr.size() - 1);
                if (map[prevstr] != 1) {
                    if (isFound(prevstr, strs)) {
                        map[prevstr] = 1;
                    }
                }
                if (map[prevstr] == 1) {
                    return prevstr;
                }
                end = mid;
            }
            if (mid == first.size()) {
                return first;
            }
        }
        return "";
    }
};


TEST(LongestCommonPrefix, TC1) {
    Solution tester;
    EXPECT_EQ("fl", tester.longestCommonPrefix({ "flower","flow","flight" }));
}


TEST(LongestCommonPrefix, TC2) {
    Solution tester;
    EXPECT_EQ("", tester.longestCommonPrefix({ "dog","racecar","car" }));
}


TEST(LongestCommonPrefix, TC3) {
    Solution tester;
    EXPECT_EQ("flower", tester.longestCommonPrefix({ "flower","flower","flower","flower" }));
}