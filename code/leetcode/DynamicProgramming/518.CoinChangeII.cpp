/*
* You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
* Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
* You may assume that you have an infinite number of each kind of coin.
* The answer is guaranteed to fit into a signed 32-bit integer.
*
* https://leetcode.com/problems/coin-change-ii/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) { return dfs(coins, 0, 0, amount); }

private:
    map<pair<int, int>, int> dp;
    int dfs(vector<int>& coins, int i, int sum, int amount) {
        if (i == coins.size()) return 0;

        if (sum > amount) return 0;

        if (sum == amount) return 1;

        if (dp.find({i, sum}) != dp.end()) { return dp[{i, sum}]; }

        dp[{i, sum}] = dfs(coins, i, sum + coins[i], amount) + dfs(coins, i + 1, sum, amount);

        return dp[{i, sum}];
    }
};

TEST(CoinChangeII, Example1) {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int ans = 4;
    Solution sol;

    ASSERT_EQ(sol.change(amount, coins), ans);
}

TEST(CoinChangeII, Example2) {
    int amount = 3;
    vector<int> coins = {2};
    int ans = 0;

    Solution sol;

    ASSERT_EQ(sol.change(amount, coins), ans);
}

TEST(CoinChangeII, Example3) {
    int amount = 10;
    vector<int> coins = {10};
    int ans = 1;

    Solution sol;

    ASSERT_EQ(sol.change(amount, coins), ans);
}
