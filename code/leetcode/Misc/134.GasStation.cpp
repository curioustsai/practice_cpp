/*
* There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
* You begin the journey with an empty tank at one of the gas stations.
* Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
* If there exists a solution, it is guaranteed to be unique
*
* https://leetcode.com/problems/gas-station/
*/

#include <gtest/gtest.h>

using namespace std;

//T.C. O(n)
//S.C. O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost) return -1;

        int result = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];

            // cannot make it from the starting point (index 0) to i-th point, so start with next point
            if (total < 0) {
                result = i + 1;
                total = 0;
            }
        }
        return result;
    }
};

TEST(GasStation, Example1) {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int ans = 3;

    Solution sol;
    ASSERT_EQ(sol.canCompleteCircuit(gas, cost), ans);
}

TEST(GasStation, Example2) {
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    int ans = -1;

    Solution sol;
    ASSERT_EQ(sol.canCompleteCircuit(gas, cost), ans);
}
