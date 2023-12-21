/*
 *
 * Cheapest Flights Within K Stops 
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        //it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        //it will store minimum cost to reach each node
        vector<int> minCost(n, INT32_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                int currNode = q.front().first;
                int cost = q.front().second;
                q.pop();
                for (auto aj: adj[currNode]) {
                    int neighbour = aj.first;
                    int price = aj.second;

                    if (price + cost < minCost[neighbour]){
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        return (minCost[dst] == INT32_MAX) ? -1:minCost[dst];
    }
};

TEST(FindCheapestPrice, Example1) {
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0; 
    int dst = 3;
    int k = 1;
    int ans = 700;

    Solution sol;
    ASSERT_EQ(sol.findCheapestPrice(n, flights, src, dst, k), ans);
}

TEST(FindCheapestPrice, Example2) {
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0; 
    int dst = 2;
    int k = 1;
    int ans = 200;

    Solution sol;
    ASSERT_EQ(sol.findCheapestPrice(n, flights, src, dst, k), ans);
}

TEST(FindCheapestPrice, Example3) {
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0; 
    int dst = 2;
    int k = 0;
    int ans = 500;

    Solution sol;
    ASSERT_EQ(sol.findCheapestPrice(n, flights, src, dst, k), ans);
}
