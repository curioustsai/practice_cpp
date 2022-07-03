/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. 
They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    // Reminder: aware of zero headings
    uint32_t reverseBit(uint32_t n) {
        uint32_t res = 0;
        for (int count = 0; count < 32; count++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }

        return res;
    }
};

TEST(Binary, ReverseBit) {
    Solution sol;
    uint32_t input = 0b00000010100101000001111010011100;
    uint32_t ans = 964176192;
    ASSERT_EQ(sol.reverseBit(input), ans);
}

TEST(Binary, ReverseBitII) {
    Solution sol;
    uint32_t input = 0b11111111111111111111111111111101;
    uint32_t ans = 3221225471;
    ASSERT_EQ(sol.reverseBit(input), ans);
}
