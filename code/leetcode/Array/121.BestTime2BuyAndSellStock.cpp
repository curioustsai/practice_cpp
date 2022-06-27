#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // return max profit
    int maxProfit(vector<int>& prices) {
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
