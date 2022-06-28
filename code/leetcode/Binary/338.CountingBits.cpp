#include <gtest/gtest.h>

using namespace std;

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; i++) { res[i] = count1s(i); }
        return res;
    }

private:
    int count1s(int n) {
        int count = 0;
        while (n) {

            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};

TEST(Binary, CountBits) {
    Solution sol;
    int n = 2;
    vector<int> ans = {0, 1, 1};
    ASSERT_EQ(sol.countBits(n), ans);
}

TEST(Binary, CountBitsII) {
    Solution sol;
    int n = 5;
    vector<int> ans = {0, 1, 1, 2, 1, 2};
    ASSERT_EQ(sol.countBits(n), ans);
}
