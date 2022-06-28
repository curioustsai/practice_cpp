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
    int count1s(uint32_t a) {
        int count = 0;
        while (a) {
            if (a & 1) count++;
            a >>= 1;
        }
        return count;
    }
};

TEST(Binary, Count1s) {
    Solution sol;
    int a = 0b00000000000000000000000000001011;
    int ans = 3;
    ASSERT_EQ(sol.count1s(a), ans);
}

TEST(Binary, Count1sII) {
    Solution sol;
    int a = 0b00000000000000000000000010000000;
    int ans = 1;
    ASSERT_EQ(sol.count1s(a), ans);
}

TEST(Binary, Count1sIII) {
    Solution sol;
    int a = 0b11111111111111111111111111111101;
    int ans = 31;
    ASSERT_EQ(sol.count1s(a), ans);
}
