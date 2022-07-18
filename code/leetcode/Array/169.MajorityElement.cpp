/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

https://www.geeksforgeeks.org/majority-element/
*/

#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // get candidate
        int maj_index = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[maj_index]) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                maj_index = i;
                count = 1;
            }
        }

        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[maj_index]) count++;
        }

        return count > nums.size() / 2 ? nums[maj_index] : -1;
    }

    // TC O(n), SC O(n)
    int majorityElementHash(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) { map[n]++; }

        int max = 0;
        int maj = -1;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second > max) { maj = it->first; }
        }

        return maj;
    }
};

TEST(MajorElement, Example1) {
    vector<int> nums = {3, 2, 3};
    int ans = 3;
    Solution sol;

    ASSERT_EQ(sol.majorityElement(nums), ans);
}

TEST(MajorElement, Example2) {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = 2;
    Solution sol;

    ASSERT_EQ(sol.majorityElement(nums), ans);
}

TEST(MajorElement, Example3) {
    vector<int> nums = {6, 5, 5};
    int ans = 5;
    Solution sol;

    ASSERT_EQ(sol.majorityElement(nums), ans);
}
