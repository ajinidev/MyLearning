#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

    int getNexIdx(vector<int>& arr, int value) {
        if (arr.empty())return -1;
        if (arr.size() == 1) {
            auto idx = arr[0];
            return idx > value ? idx : -1;
        }
        if (value < arr[0]) {
            return arr[0];
        }
        //for (int i = 0; i < arr.size(); i++) {
        //    if (arr[i] > value) return arr[i];
        //}
        //return -1;
        int start = 0, end = arr.size() - 1;
        if (arr[end] <= value) {
            return -1;
        }
        while (start < end) {
            auto mid = (start + end) / 2;
            if (mid + 1 < arr.size() && arr[mid] <= value && arr[mid + 1] > value) {
                return arr[mid + 1];
            }
            else if (arr[mid] < value) {
                start = mid;
            }
            else if (arr[mid] > value) {
                end = mid;
            }
        }
        return -1;
    }

public:
    int numMatchingSubseq(string s, vector<string> words) {
        vector<vector<int>> map(26);
        auto idx = 0;
        for (auto i : s) {
            map[i - 'a'].push_back(idx);
            idx++;
        }
        int count = 0;

        for (auto w : words) {
            bool found = true;
            int idx = -1;
            for (auto c : w) {
                auto nextIdx = getNexIdx(map[c - 'a'], idx);
                if (nextIdx > idx) idx = nextIdx;
                else {
                    found = false;
                    break;
                }
            }
            if (found) count++;
        }
        
        return count;
    }
};

TEST(NumberOfMatchingSubSequences, TC1) {
    Solution tester;
    EXPECT_EQ(3, tester.numMatchingSubseq("abcde", { "a","bb","acd","ace" }));
}

TEST(NumberOfMatchingSubSequences, TC2) {
    Solution tester;
    EXPECT_EQ(2, tester.numMatchingSubseq("dsahjpjauf", { "ahjpjau","ja","ahbwzgqnuk","tnmlanowax" }));
}