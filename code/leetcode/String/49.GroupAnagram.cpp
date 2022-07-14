/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Solution:
https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) { mp[strSort(s)].push_back(s); }

        vector<vector<string>> anagrams;
        for (auto p : mp) { anagrams.push_back(p.second); }
        return anagrams;
    }

private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) { counter[c - 'a']++; }
        string t;
        for (int c = 0; c < 26; c++) { t += string(counter[c], c + 'a'); }
        return t;
    }
};

TEST(GroupAnagram, Example1) {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    vector<vector<string>> ret = sol.groupAnagrams(strs);
}

TEST(GroupAnagram, Example2) {
    Solution sol;
    vector<string> strs = {""};
    vector<vector<string>> ans = {{""}};
    vector<vector<string>> ret = sol.groupAnagrams(strs);
}

TEST(GroupAnagram, Example3) {
    Solution sol;
    vector<string> strs = {"a"};
    vector<vector<string>> ans = {{"a"}};
    vector<vector<string>> ret = sol.groupAnagrams(strs);
}
