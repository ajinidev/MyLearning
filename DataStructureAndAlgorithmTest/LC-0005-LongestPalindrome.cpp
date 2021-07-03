#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int start = 0;
        auto length = 1;
        for (auto idx = 0; idx < s.size();) {
            int beg = idx, end = idx;
            while (end < s.size() - 1 && s[end] == s[end + 1]) {
                // checking for duplicates.
                end++;
            }
            // incrementing index
            idx = end + 1; // instead of ++, we are adding the skipped elements as well.

            // now checking for palindroms on sides.
            while (end < s.size() - 1 && beg > 0 && s[end + 1] == s[beg - 1]) {
                beg--; end++;
            }
            if (length < end - beg + 1) {
                start = beg;
                length = end - beg + 1;
            }
        }
        return s.substr(start, length);
    }
};

TEST(longestPalindromeTest, TC1) {
    Solution tester;
    EXPECT_EQ("bab", tester.longestPalindrome("babad"));
}

TEST(longestPalindromeTest, TC2) {
    Solution tester;
    EXPECT_EQ("bb", tester.longestPalindrome("cbbd"));
}

TEST(longestPalindromeTest, TC3) {
    Solution tester;
    EXPECT_EQ("a", tester.longestPalindrome("a"));
}

TEST(longestPalindromeTest, TC4) {
    Solution tester;
    EXPECT_EQ("a", tester.longestPalindrome("ac"));
}

TEST(longestPalindromeTest, TC5) {
    Solution tester;
    EXPECT_EQ("a", tester.longestPalindrome("ac"));
}