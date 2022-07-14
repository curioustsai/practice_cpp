/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // return max profit
    // complexity O(n^2)
    int maxProfit_brute(vector<int>& prices) {
        int maxprofit = 0;
        vector<int> trade_day(2, 0);

        int buy_index = 0, sell_index = 0;

        for (int buy_index = 0; buy_index < prices.size() - 1; buy_index++) {
            for (int sell_index = buy_index + 1; sell_index < prices.size(); sell_index++) {
                int temp = prices[sell_index] - prices[buy_index];
                if (temp > maxprofit) {
                    maxprofit = temp;
                    trade_day[0] = buy_index;
                    trade_day[1] = sell_index;
                }
            }
        }

        return maxprofit;
    }
    // complexity O(n)
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT32_MAX;

        vector<int> trade_day(2, 0);

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                if (prices[i] - minprice > maxprofit) {
                    maxprofit = prices[i] - minprice;
                    trade_day[1] = i;
                }
            } else {
                if (prices[i] < minprice) {
                    minprice = prices[i];
                    trade_day[0] = i;
                }
            }
        }

        return maxprofit;
    }
};

TEST(BestTime2BuyAndSellStock, Test1) {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = 5;

    ASSERT_EQ(sol.maxProfit(prices), 5);
}
TEST(BestTime2BuyAndSellStock, Test2) {
    Solution sol;
    vector<int> prices = {7, 6, 4, 3, 1};
    int ans = 0;

    ASSERT_EQ(sol.maxProfit(prices), 0);
}
