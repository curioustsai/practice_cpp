/*
* Given a signed 32-bit integer x, return x with its digits reversed. 
* If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0. 
* Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*
* https://leetcode.com/problems/reverse-integer/description/
*/
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int temp = x % 10;
            x =  x / 10;

            // prevent overflow
            if (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && temp > 7))
                return 0;
            // prevent overflow
            if (res < INT32_MIN / 10 || (res == INT32_MIN / 10 && temp < -8))
                return 0;
            res = res * 10 + temp;
        }

        return res;
    }
};
