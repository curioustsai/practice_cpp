/*
Given a string s, find the length of the longest substring without repeating characters.
*/

#include <gtest/gtest.h>

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        for (int j = 0; j < s.size(); j++) {
            int count = 0;
            bool hit[256] = {false};

            for (int i = j; i < s.size(); i++) {
                char c = s[i];
                if (!hit[c]) {
                    hit[c] = true;
                    count++;
                } else {
                    break;
                }
            }
            res = max(res, count);
        }

        return res;
    }
};

TEST(LengthOfLongestSubstring, Example1) {
    Solution sol;
    string s = "abcabcbb";
    int ans = 3;
    ASSERT_EQ(sol.lengthOfLongestSubstring(s), ans);
}

TEST(LengthOfLongestSubstring, Example2) {
    Solution sol;
    string s = "bbbbb";
    int ans = 1;
    ASSERT_EQ(sol.lengthOfLongestSubstring(s), ans);
}

TEST(LengthOfLongestSubstring, Example3) {
    Solution sol;
    string s = "pwwkew";
    int ans = 3;
    ASSERT_EQ(sol.lengthOfLongestSubstring(s), ans);
}
