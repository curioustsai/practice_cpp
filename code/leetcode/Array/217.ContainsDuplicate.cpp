/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
//https://leetcode.com/problems/contains-duplicate/
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // Complexity O(nlogn)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }

        return false;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    bool containsDuplicateHash(vector<int>& nums) {
        map<int, bool> dict;

        for (int n : nums) {
            if (dict.find(n) != dict.end()) { return true; }
            dict.insert(make_pair(n, true));
        }

        return false;
    }

    bool containsDuplicateSet(vector<int>& nums) {
        set<int> set;

        for (int n : nums) {
            if (set.count(n))
                return true;
            else
                set.insert(n);
        }
        return false;
    }
};

TEST(ContainsDuplicate, Test1) {
    Solution sol;
    vector<int> prices = {1, 2, 3, 1};

    ASSERT_EQ(sol.containsDuplicate(prices), true);
}

TEST(ContainsDuplicate, Test2) {
    Solution sol;
    vector<int> prices = {1, 2, 3, 4};

    ASSERT_EQ(sol.containsDuplicate(prices), false);
}

TEST(ContainsDuplicate, Test3) {
    Solution sol;
    vector<int> prices = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    ASSERT_EQ(sol.containsDuplicate(prices), true);
}

TEST(containsDuplicateHash, Test1) {
    Solution sol;
    vector<int> prices = {1, 2, 3, 1};

    ASSERT_EQ(sol.containsDuplicateHash(prices), true);
}

TEST(containsDuplicateHash, Test2) {
    Solution sol;
    vector<int> prices = {1, 2, 3, 4};

    ASSERT_EQ(sol.containsDuplicateHash(prices), false);
}

TEST(containsDuplicateHash, Test3) {
    Solution sol;
    vector<int> prices = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    ASSERT_EQ(sol.containsDuplicateHash(prices), true);
}
