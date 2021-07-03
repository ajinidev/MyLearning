#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string result = s; 
        int out = 0, idx = 0;
        while (idx < s.size()) {
            auto item = s[idx];
            bool removed = false;
            while (out > 0) {
                if (result[out - 1] != item) {
                    break;
                }
                else {
                    out--;
                    removed = true;
                }
            }
            if (!removed) {
                result[out] = item;
                out++;
            }

            idx++;
        }
        return result.substr(0, out);
    }
};

TEST(RemoveAdjacentDuplicates, TC1) {
    Solution tester;
    EXPECT_EQ("ca", tester.removeDuplicates("abbaca"));
}

TEST(RemoveAdjacentDuplicates, TC2) {
    Solution tester;
    EXPECT_EQ("ay", tester.removeDuplicates("azxxzy"));
}