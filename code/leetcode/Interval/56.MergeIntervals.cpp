/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                //over lap, merge
                res.back()[1] = max(res.back()[1], intervals[i][1]);

            } else {
                res.push_back(intervals[i]);
            };
        }

        return res;
    }
};

TEST(MergeInterval, ExampleI) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = {{1, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res = sol.merge(intervals);

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(res[i], ans[i]); }
}

TEST(MergeInterval, ExampleII) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> ans = {{1, 5}};

    vector<vector<int>> res = sol.merge(intervals);

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(res[i], ans[i]); }
}
