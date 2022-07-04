/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/non-overlapping-intervals/discuss/792726/C%2B%2B-Simple-O(NlogN)-solution-with-explanation
    // Sort by end, greedy thinking. If we take the one endings first, we can take more intervals.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int previous = 0;
        int eraseCount = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[previous][1]) {
                previous = i;
            } else {
                eraseCount++;
            }
        }

        return eraseCount;
    }
};

TEST(EraseOverlapIntervals, ExampleI) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int ans = 1;

    ASSERT_EQ(sol.eraseOverlapIntervals(intervals), ans);
}

TEST(EraseOverlapIntervals, ExampleII) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
    int ans = 2;

    ASSERT_EQ(sol.eraseOverlapIntervals(intervals), ans);
}

TEST(EraseOverlapIntervals, ExampleIII) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}};
    int ans = 0;

    ASSERT_EQ(sol.eraseOverlapIntervals(intervals), ans);
}
