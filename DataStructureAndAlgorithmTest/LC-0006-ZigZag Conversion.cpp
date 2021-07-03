#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> result;
        auto size = s.size() / numRows;
        size++;
        for (int i = 0; i < numRows; i++) {
            string arr;
            result.push_back(arr);
        }
        bool forward = true;int i = 0; 
        int arrIdx = 0;
        while (i < s.size()) {
            result[arrIdx].push_back(s[i]);
            if (arrIdx == 0) {
                forward = true;
            }
            else if (arrIdx == numRows - 1) {
                forward = false;
            }
            if(forward) arrIdx++; else arrIdx--;
            i++;
        }
        string ret = "";
        for (auto str : result) {
            ret.append(str);
        }
        return ret;
    }
};


TEST(ZigZagConversion, TC1) {
    Solution tester;
    EXPECT_EQ("PAHNAPLSIIGYIR", tester.convert("PAYPALISHIRING", 3));
}


TEST(ZigZagConversion, TC2) {
    Solution tester;
    EXPECT_EQ("PINALSIGYAHRPI", tester.convert("PAYPALISHIRING", 4));
}


TEST(ZigZagConversion, TC3) {
    Solution tester;
    EXPECT_EQ("A", tester.convert("A", 3));
}

