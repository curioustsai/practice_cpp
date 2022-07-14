/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> maps(26, 0);

        int n = s.length();
        for (int i = 0; i < n; i++) {
            maps[s[i] - 'a']++;
            maps[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (maps[i]) return false;
        }
        return true;
    }

    bool isAnagramHash(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> maps;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            maps[s[i]]++;
            maps[t[i]]--;
        }

        for (auto it = maps.begin(); it != maps.end(); it++) {
            if (it->second) return false;
        }
        return true;
    }
};

TEST(IsAnagram, Example1) {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    ASSERT_EQ(sol.isAnagramHash(s, t), true);
}

TEST(IsAnagram, Example2) {
    Solution sol;
    string s = "rat";
    string t = "car";

    ASSERT_EQ(sol.isAnagramHash(s, t), false);
}
