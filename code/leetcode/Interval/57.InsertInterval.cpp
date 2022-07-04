/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi],
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.

You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals 
(merge overlapping intervals if necessary).

Return intervals after the insertion.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) return intervals;

        vector<vector<int>> res;
        // put all intervals end before newInterval start
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            res.push_back(intervals[index++]);
        }

        // merge overlapping interval, interval start < newInterval end
        int start = newInterval[0];
        int end = newInterval[1];
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            start = min(intervals[index][0], start);
            end = max(intervals[index][1], end);

            index++;
        }
        res.push_back({start, end});

        while (index < intervals.size()) { res.push_back(intervals[index++]); }

        return res;
    }
};

TEST(InsertInterval, ExampleI) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> ans = {{1, 5}, {6, 9}};

    vector<vector<int>> res = sol.insert(intervals, newInterval);

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(res[i], ans[i]); }
}

TEST(InsertInterval, ExampleII) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> ans = {{1, 2}, {3, 10}, {12, 16}};

    vector<vector<int>> res = sol.insert(intervals, newInterval);

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(res[i], ans[i]); }
}
