/*
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position.
 * Return the max sliding window.
 *
 * https://leetcode.com/problems/sliding-window-maximum/
*/

#include <gtest/gtest.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int i = 0;
        int j = 0;

        // monotonic descrease deque, leftmost is the largest number
        while (j < nums.size()) {
            while (!dq.empty() && nums[j] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if (i > dq.front())
                dq.pop_front();

            if (j + 1 >= k) {
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return result;
    }
};

TEST(MaxSlidingWindow, Example1) {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3
  vector<int> ans = {3,3,5,5,6,7};
  Solution sol;

  ASSERT(sol.maxSlidingWindow(nums, k), ans);
}

TEST(MaxSlidingWindow, Example2) {
  vector<int> nums = {1};
  int k = 1
  vector<int> ans = {1};
  Solution sol;

  ASSERT(sol.maxSlidingWindow(nums, k), ans);
}
