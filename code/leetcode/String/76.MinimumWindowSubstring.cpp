/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Solution:
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
*/

#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // sliding window
    // string minWindows(string s, string t) {
    //     vector<int> maps(128, 0);
    //     for (auto c : t) maps[c]++;
    //     int counter = t.size(), begin = 0, end = 0, d = INT32_MAX, head = 0;
    //     while (end < s.size()) {
    //         if (maps[s[end++]]-- > 0) counter--;
    //         while (counter == 0) {
    //             if (end - begin < d) d = end - (head = begin);
    //             if (maps[s[begin++]]++ == 0) counter++;
    //         }
    //     }
    //     return (d == INT32_MAX) ? "" : s.substr(head, d);
    // }

    // sliding window
    string minWindows(string s, string t) {
        unordered_map<char, int> maps;
        for (auto c : t) maps[c]++;

        int counter = t.size();
        int begin = 0, end = 0;
        int head = 0, d = INT32_MAX;

        while (end < s.size()) {
            // find the rightmost boundary
            // s[end] in string t
            if (maps[s[end]] > 0) { counter--; }
            // if s[end] not in string t, it'd be negative
            maps[s[end]]--;
            end++;

            while (counter == 0) {
                if (end - begin < d) {
                    d = end - begin;
                    head = begin;
                }
                maps[s[begin]]++;

                // s[begin] in string t, break the loop
                // only characters in string t will be > 0; otherwise maximum equals 0.
                if (maps[s[begin]] > 0) { counter++; }
                begin++;
            }
        }

        return (d == INT32_MAX) ? "" : s.substr(head, d);
    }
};

TEST(MinWindows, Example1) {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string output = "BANC";
    ASSERT_EQ(sol.minWindows(s, t), output);
}

TEST(MinWindows, Example2) {
    Solution sol;
    string s = "a";
    string t = "a";
    string output = "a";
    ASSERT_EQ(sol.minWindows(s, t), output);
}

TEST(MinWindows, Example3) {
    Solution sol;
    string s = "a";
    string t = "aa";
    string output = "";
    ASSERT_EQ(sol.minWindows(s, t), output);
}
