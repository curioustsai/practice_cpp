/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        vector<int> res;
        if (s.size() < p.size()) return res;

        int left = 0, right = 0;
        while (right < p.size()) {
            hash[s[right] - 'a']++;
            phash[p[right] - 'a']++;
            right++;
        }
        right--;

        while (right < s.size()) {
            if (hash == phash) { res.push_back(left); }
            right++;
            if (right == s.size()) break;
            hash[s[right] - 'a']++;
            hash[s[left] - 'a']--;
            left++;
        }
        return res;
    }
};

TEST(FindAnagrams, Example1) {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = {0, 6};

    ASSERT_EQ(sol.findAnagrams(s, p), ans);
}

TEST(FindAnagrams, Example2) {
    Solution sol;
    string s = "abab";
    string p = "ab";
    vector<int> ans = {0, 1, 2};

    ASSERT_EQ(sol.findAnagrams(s, p), ans);
}

TEST(FindAnagrams, Example3) {
    Solution sol;
    string s = "aa";
    string p = "bb";
    vector<int> ans = {};

    ASSERT_EQ(sol.findAnagrams(s, p), ans);
}
