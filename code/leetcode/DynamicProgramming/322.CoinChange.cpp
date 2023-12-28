/*
You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money. Return
the fewest number of coins that you need to make up that amount. If that amount
of money cannot be made up by any combination of the coins, return -1. You may
assume that you have an infinite number of each kind of coin.

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 10e4

https://leetcode.com/problems/coin-change/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, 1e5);

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                // residue is negative, break
                if (i - c < 0) continue;
                // min btw dp[i-c] + 1 & dp[i]
                dp[i] = std::min(dp[i - c] + 1, dp[i]);
            }
        }

        return dp[amount] == 1e5 ? -1 : dp[amount];
    }
};

// recursive + memo
// Time: O(n.m)
// Space: O(n.m)
class Solution3 {
public:
    int coinChange(vector<int> &coins, int amount) {
        int res = dfs(coins, amount, 0);
        return (res == INT32_MAX - 1) ? -1 : res;
    }

private:
    map<pair<int, int>, int> mp;
    int dfs(vector<int> &coins, int amount, int index) {
        if (index >= coins.size() || amount < 0) return INT32_MAX - 1;
        if (amount == 0) return 0;

        if (mp.find({index, amount}) != mp.end()) return mp[{index, amount}];

        if (coins[index] > amount) {
            mp[{index, amount}] = dfs(coins, amount, index + 1);
        } else {
            mp[{index, amount}] =
                min(dfs(coins, amount - coins[index], index) + 1, dfs(coins, amount, index + 1));
        }

        return mp[{index, amount}];
    }
};

// recursive
// Time: O(2^n)
// Space: O(n)
class Solution2 {
public:
    int coinChange(vector<int> &coins, int amount) {
        int res = dfs(coins, amount, 0);
        return (res == INT32_MAX - 1) ? -1 : res;
    }

private:
    int dfs(vector<int> &coins, int amount, int index) {
        if (index >= coins.size() || amount < 0) return INT32_MAX - 1;

        if (amount == 0) return 0;

        if (coins[index] > amount) {
            return dfs(coins, amount, index + 1);
        } else {
            // min btw take and not take
            return min(dfs(coins, amount - coins[index], index) + 1, dfs(coins, amount, index + 1));
        }
    }
};

TEST(CoinChange, ExampleI) {
    Solution sol;
    vector<int> input = {1, 2, 5};
    int amount = 11;
    uint32_t ans = 3;
    ASSERT_EQ(sol.coinChange(input, amount), ans);
}

TEST(CoinChange, ExampleII) {
    Solution sol;
    vector<int> input = {2};
    int amount = 3;
    uint32_t ans = -1;
    ASSERT_EQ(sol.coinChange(input, amount), ans);
}

TEST(CoinChange, ExampleIII) {
    Solution sol;
    vector<int> input = {1};
    int amount = 0;
    uint32_t ans = 0;
    ASSERT_EQ(sol.coinChange(input, amount), ans);
}

TEST(CoinChange, ExampleIV) {
    Solution sol;
    vector<int> input = {474, 83, 404, 3};
    int amount = 264;
    uint32_t ans = 8;
    ASSERT_EQ(sol.coinChange(input, amount), ans);
}
