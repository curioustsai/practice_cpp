/*
 * Koko loves to eat bananas.
 * There are n piles of bananas, the ith pile has piles[i] bananas.
 * The guards have gone and will come back in h hours.
 * Koko can decide her bananas-per-hour eating speed of k.
 * Each hour, she chooses some pile of bananas and eats k bananas from that pile.
 * If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
*/

#include <gtest/gtest.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (auto p : piles) { high = max(p, high); }

        int result = high;
        while (low <= high) {
            int k = (low + high) / 2;
            long int hours = 0;
            for (int i = 0; i < piles.size(); i++) { hours += ceil((double)piles[i] / k); }

            if (hours <= h) {
                result = min(k, result);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return result;
    }
};
