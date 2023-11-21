/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum/
*/
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    // brute force
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            vector<int> null = {};
            res.push_back(null);
            return res;
        }

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> r;
                        r.push_back(nums[i]);
                        r.push_back(nums[j]);
                        r.push_back(nums[k]);
                        sort(r.begin(), r.end());
                        res.push_back(r);
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> threeSum_opt(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            res.push_back({});
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int residue = -(nums[i] + nums[j]);

                if (binary_search(nums, j + 1, nums.size() - 1, residue) != -1) {
                    res.push_back({nums[i], nums[j], residue});
                }
            }
        }
        return res;
    }

    // reference opt, time complexity O(n^2)
    vector<vector<int>> threeSum_opt2(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            res.push_back({});
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    // when sum == 0
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    while ((nums[left] == nums[left - 1]) && (left < right))
                        left++; //move to next element
                }
            }
        }
        return res;
    }

private:
    int binary_search(vector<int> arr, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) return mid;

            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

TEST(ThreeSum, Test1) {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = {{-1, 0, 1}, {-1, -1, 2}};
    vector<vector<int>> ans_swap = {{-1, -1, 2}, {-1, 0, 1}};

    // vector<vector<int>> res = sol.threeSum(nums);
    vector<vector<int>> res = sol.threeSum_opt2(nums);

    for (vector<int> v : res) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    bool eq = equal(ans.begin(), ans.end(), res.begin());
    eq |= equal(ans_swap.begin(), ans_swap.end(), res.begin());

    ASSERT_EQ(eq, true);
}

TEST(ThreeSum, Test2) {
    Solution sol;
    vector<int> nums = {};
    vector<vector<int>> ans = {{}};

    vector<vector<int>> res = sol.threeSum(nums);

    ASSERT_EQ(equal(ans.begin(), ans.end(), res.begin()), true);
}

TEST(ThreeSum, Test3) {
    Solution sol;
    vector<int> nums = {0};
    vector<vector<int>> ans = {{}};

    vector<vector<int>> res = sol.threeSum(nums);

    ASSERT_EQ(equal(ans.begin(), ans.end(), res.begin()), true);
}
