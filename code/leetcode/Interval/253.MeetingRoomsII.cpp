/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // https://github.com/grandyang/leetcode/issues/253
    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> begins;
        vector<int> ends;

        for (vector<int> interval : intervals) {
            begins.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(begins.begin(), begins.end());
        sort(ends.begin(), ends.end());

        int endpos = 0;
        int res = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (begins[i] < ends[endpos])
                res++;
            else
                endpos++;
        }

        return res;
    }

    int minMeetingRooms2(vector<vector<int>> &intervals) {
        map<int, int> m;
        for (auto &interval : intervals) {
            m[interval[0]]++;
            m[interval[1]]--;
        }

        int res = 0, room = 0;
        // map<int, int>::iterator it;
        // for (it = m.begin(); it !=m.end(); it++) {
        //     res = max(res, room += it->second);
        // }
        for (auto it : m) { res = max(res, room += it.second); }
        return res;
    }
};

TEST(MeetingRoomI, ExampleI) {
    Solution sol;
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    int ans = 2;

    ASSERT_EQ(sol.minMeetingRooms(intervals), ans);
}

TEST(MeetingRoomI, ExampleII) {
    Solution sol;
    vector<vector<int>> intervals = {{7, 10}, {2, 4}};
    int ans = 1;

    ASSERT_EQ(sol.minMeetingRooms(intervals), ans);
}
