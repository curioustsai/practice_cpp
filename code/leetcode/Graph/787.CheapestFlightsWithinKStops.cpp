/*
 *
 * Cheapest Flights Within K Stops 
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // BFS
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

    /*
     * Bellman-Ford Algorithm
     * In bellman-ford algo calculates the shortest distance from the source point to all of the vertices.
     * Time complexity of Bellman-Ford is O(VE),
    */
    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minDist(n, INT32_MAX);
        minDist[src] = 0;

        for (int stop = 0; stop <= k; stop++) {
            vector<int> temp(minDist);
            for (auto flight: flights) {
                if (minDist[flight[0]] != INT32_MAX) {
                    temp[flight[1]] = min(temp[flight[1]], minDist[flight[0]] + flight[2]);
                }
            }
            minDist = temp;
        }
        return (minDist[dst] == INT32_MAX) ? -1: minDist[dst];
    }

    /* Dijkstra’s Algorithm allows you to calculate the shortest path between 
    one node of your choosing and every other node in a graph. 
    
    Given a graph and a source vertex in the graph, find shortest paths from source
    to all vertices in the given graph.
    
    We generate a SPT (shortest path tree) with given source as root. We maintain
    two sets, one set contains vertices included in shortest path tree, other set
    includes vertices not yet included in shortest path tree. At every step of the
    algorithm, we find a vertex which is in the other set (set of not yet included)
    and has a minimum distance from the source.
    
    Time Complexity:  If we take a closer look, we can observe that the statements
    in inner loop are executed O(V+E) times (similar to BFS).
    So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)
    */
    
    int findCheapestPrice3(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // create adjacency list
        unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        // minHeap based on cost of distance from source
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, K+1 } ); // cost, vertex, hops
        
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if( curr == dst )
                return cost;

            if( stop > 0 )
                for( auto next : adjList[curr] )
                    minHeap.push( { cost+next.second, next.first, stop-1 } );
        }
        return -1;
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
