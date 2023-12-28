/*
* You are given a network of n nodes, labeled from 1 to n.
* You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
* We will send a signal from a given node k.
* Return the minimum time it takes for all the n nodes to receive the signal.
* If it is impossible for all the n nodes to receive the signal, return -1.
*
* https://leetcode.com/problems/network-delay-time/
*/

#include <gtest/gtest.h>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[source].push_back({time, dest});
        }

        vector<int> signalReceiveTime(n + 1, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        // time for start node is 0
        signalReceiveTime[k] = 0;

        while (!pq.empty()) {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNodeTime > signalReceiveTime[currNode]) { continue; }

            // send signal to adjacent nodes
            for (int i = 0; i < adj[currNode].size(); i++) {
                pair<int, int> edge = adj[currNode][i];
                int time = edge.first;
                int neighborNode = edge.second;

                // fastest signal time for neighborNode so far
                if (signalReceiveTime[neighborNode] > currNodeTime + time) {
                    signalReceiveTime[neighborNode] = currNodeTime + time;
                    pq.push({signalReceiveTime[neighborNode], neighborNode});
                }
            }
        }

        int result = INT32_MIN;
        for (int i = 1; i <= n; i++) { result = max(result, signalReceiveTime[i]); }

        return (result == INT32_MAX) ? -1 : result;
    }
};

TEST(NetworkDelayTime, Example1) {
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int ans = 2;
    Solution sol;

    ASSERT_EQ(sol.networkDelayTime(times, n, k), ans);
}

TEST(NetworkDelayTime, Example2) {
    vector<vector<int>> times = {{1, 2, 1}};
    int n = 2;
    int k = 1;
    int ans = 1;
    Solution sol;

    ASSERT_EQ(sol.networkDelayTime(times, n, k), ans);
}

TEST(NetworkDelayTime, Example3) {
    vector<vector<int>> times = {{1, 2, 1}};
    int n = 2;
    int k = 2;
    int ans = -1;
    Solution sol;

    ASSERT_EQ(sol.networkDelayTime(times, n, k), ans);
}
