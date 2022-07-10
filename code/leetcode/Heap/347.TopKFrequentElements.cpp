/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

#include <gtest/gtest.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int n : nums) { map[n]++; }

        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // optmized version
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> map;
    //     vector<int> res;
    //     for (int n : nums) { map[n]++; }

    //     priority_queue<pair<int, int>> pq;
    //     for (auto it = map.begin(); it != map.end(); it++) {
    //         pq.push(make_pair(it->second, it->first));

    //         if (pq.size() > (int)map.size() - k) {
    //             res.push_back(pq.top().second);
    //             pq.pop();
    //         }
    //     }
    //     return res;
    // }
};

TEST(TopKElements, Example1) {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = {1, 2};

    ASSERT_EQ(sol.topKFrequent(nums, k), ans);
}

TEST(TopKElements, Example2) {
    Solution sol;
    vector<int> nums = {1};
    int k = 1;
    vector<int> ans = {1};

    ASSERT_EQ(sol.topKFrequent(nums, k), ans);
}
