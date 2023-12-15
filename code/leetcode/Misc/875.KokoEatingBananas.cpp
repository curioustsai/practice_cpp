/*
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
        for (auto p : piles) {
            high = max(p, high);
        }

        int result = high;
        while (low <= high) {
            int k = (low + high) / 2;
            long int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double)piles[i]/k);
            }
            
            if (hours <= h) {
                result = min(k, result);
                high = k -1;
            } else {
                low = k + 1;
            }
        }
        return result;
    }
};
