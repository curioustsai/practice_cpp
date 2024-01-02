/*
    Given intervals array & queries array, ans to a query is min interval containing it
    Ex. intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5] -> [3,3,1,4]

    Min heap & sort by size of intervals, top will be min size, 

    Time: O(n log n + q log q) -> n = number of intervals, q = number of queries
    Space: O(n + q)

    https://leetcode.com/problems/minimum-interval-to-include-each-query/description/
*/

#include <gtest/gtest.h>

#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;

        // [size of interval, end of interval]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {query -> size of interval}
        unordered_map<int, int> m;

        // also need only valid intervals so sort by start time & sort queries
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result;

        int i = 0;
        for (int j = 0; j < sortedQueries.size(); j++) {
            int query = sortedQueries[j];

            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }

            while (!pq.empty() && pq.top().second < query) { pq.pop(); }

            if (!pq.empty()) {
                m[query] = pq.top().first;
            } else {
                m[query] = -1;
            }
        }

        for (int j = 0; j < queries.size(); j++) { result.push_back(m[queries[j]]); }
        return result;
    }
};

TEST(MinInterval, Example1) {
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries = {2, 3, 4, 5};
    vector<int> ans = {3, 3, 1, 4};

    ASSERT_EQ(sol.minInterval(intervals, queries), ans);
}

TEST(MinInterval, Example2) {
    Solution sol;
    vector<vector<int>> intervals = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
    vector<int> queries = {2, 19, 5, 22};
    vector<int> ans = {2, -1, 4, 6};

    ASSERT_EQ(sol.minInterval(intervals, queries), ans);
}
