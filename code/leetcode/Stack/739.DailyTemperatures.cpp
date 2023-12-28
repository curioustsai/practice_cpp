/*
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 *
 * https://leetcode.com/problems/daily-temperatures/
*/

#include <gtest/gtest.h>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    // Brute force, O(n^2)
    vector<int> dailyTemperatures_BruteForce(vector<int>& temperatures) {
        vector<int> result;
        int n = temperatures.size();

        for (int i = 0; i < n; i++) {
            int day = 0;
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    day = j - i;
                    break;
                }
            }
            result.push_back(day);
        }
        return result;
    }

    // Monotonic decr stack, at each day, compare incr from prev days
    // Time: O(n)
    // Space: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);

        // [index, temperature]
        stack<pair<int, int>> stack;

        for (int i = 0; i < n; i++) {
            int currTemp = temperatures[i];
            int currDate = i;

            while (!stack.empty() && currTemp > stack.top().second) {
                int prevDate = stack.top().first;
                stack.pop();
                result[prevDate] = currDate - prevDate;
            }
            stack.push({currDate, currTemp});
        }

        return result;
    }
};
