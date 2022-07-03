/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

#include <gtest/gtest.h>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    https://leetcode.com/problems/word-break/discuss/169383/solved-The-Time-Complexity-of-The-Brute-Force-Method-Should-Be-O(2n)-and-Prove-It-Below
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet);
    }

    bool check(string s, set<string>& wordSet) {
        int length = s.length();
        if (length == 0) return true;

        for (int i = 1; i <= length; i++) {
            if (wordSet.count(s.substr(0, i)) && check(s.substr(i), wordSet)) { return true; }
        }
        return false;
    }

    // bool check(string s, set<string>& wordSet, int start, vector<int>& memo) {
    //     if (start > s.size()) return true;
    //     if (memo[start] != -1) return memo[start];
    //     for (int i = start + 1; i < s.size(); ++i) {
    //         if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
    //             memo[start] = 1;
    //             return memo[start];
    //         }
    //     }
    //     memo[start] = 0;
    //     return memo[start];
    // }
};

TEST(WordBreak, ExampleI) {
    Solution sol;
    string input = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    ASSERT_EQ(sol.wordBreak(input, wordDict), true);
}
