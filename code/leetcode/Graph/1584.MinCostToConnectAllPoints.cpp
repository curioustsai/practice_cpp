/*
* You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
* The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
* |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
* Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*
* https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

/*
    Given array of points, return min cost to connect all points
    All points have 1 path b/w them, cost is Manhattan distance

    MST problem, Prim's, greedily pick node not in MST & has smallest edge cost
    Add to MST, & for all its neighbors, try to update min dist values, repeat

    Time: O(n^2)
    Space: O(n)
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n);
        vector<int> minCost(n, INT32_MAX);

        minCost[0] = 0;
        int edgeUsed = 0;
        int result = 0;

        while (edgeUsed < n) {
            // pick up the closet point to MST
            int currNode = -1;
            int currCost = INT32_MAX;

            for (int i = 0; i < n; i++) {
                if (!inMST[i] && currCost > minCost[i]) {
                    currNode = i;
                    currCost = minCost[i];
                }
            }
            result += currCost;
            inMST[currNode] = true;
            edgeUsed++;

            // update adjacent cost
            for (int i = 0; i < n; i++) {
                int cost = abs(points[i][0] - points[currNode][0]) +
                           abs(points[i][1] - points[currNode][1]);

                if (!inMST[i] && minCost[i] > cost) { minCost[i] = cost; }
            }
        }
        return result;
    }
};

TEST(MinCostConnectPoints, Example1) {
    vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int ans = 20;

    Solution sol;
    ASSERT_EQ(sol.minCostConnectPoints(points), ans);
}

TEST(MinCostConnectPoints, Example2) {
    vector<vector<int>> points{{3, 12}, {-2, 5}, {-4, 1}};
    int ans = 18;

    Solution sol;
    ASSERT_EQ(sol.minCostConnectPoints(points), ans);
}
