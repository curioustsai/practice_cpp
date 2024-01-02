/*
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve. You may complete as many transactions as you like 
 * (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { return dfs(prices, 0, true); }

private:
    map<pair<int, bool>, int> dp;
    int dfs(vector<int>& prices, int index, bool buying) {
        if (index >= prices.size()) return 0;
        if (dp.find({index, buying}) != dp.end()) return dp[{index, buying}];

        int cooldown = dfs(prices, index + 1, buying);
        if (buying) {
            int buying = dfs(prices, index + 1, !buying) - prices[index];
            dp[{index, buying}] = max(buying, cooldown);

        } else {
            int selling = dfs(prices, index + 2, !buying) + prices[index];
            dp[{index, buying}] = max(selling, cooldown);
        }
        return dp[{index, buying}];
    }
};

TEST(MaxProfit, Example1) {
    vector<int> prices = {1, 2, 3, 0, 2};
    int ans = 3;
    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), ans);
}

TEST(MaxProfit, Example2) {
    vector<int> prices = {1};
    int ans = 0;
    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), ans);
}
