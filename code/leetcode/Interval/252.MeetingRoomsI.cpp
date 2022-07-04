/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool attendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }

        return true;
    }
};

TEST(MeetingRoomI, ExampleI) {
    Solution sol;
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool ans = false;

    ASSERT_EQ(sol.attendMeetings(intervals), ans);
}

TEST(MeetingRoomI, ExampleII) {
    Solution sol;
    vector<vector<int>> intervals = {{7, 10}, {2, 4}};
    bool ans = true;

    ASSERT_EQ(sol.attendMeetings(intervals), ans);
}
