#include <gtest/gtest.h>
#include <iostream>

// review of bit operation
// bitwise and
// 0, 0, 0
// 1, 0, 0
// 0, 1, 0
// 1, 1, 1

// bitwise or
// 0, 0, 0
// 1, 0, 1
// 0, 1, 1
// 1, 1, 1

// bitwise xor
// 0, 0, 0
// 1, 0, 1
// 0, 1, 1
// 1, 1, 0

using namespace std;

// utils
string stringifyBit(const int x) {
    string ret = "";
    int num = x;

    while (num) {
        ret = to_string(num & 1) + ret;
        num = num >> 1;
    }

    return ret;
}

int getBit(const int x, int n) { return (x >> n) & 1; }
int setBit(const int x, int n) { return x | (1 << n); }
int clearBit(const int x, int n) { return x & ~(1 << n); }
int toggleBit(const int x, int n) { return x ^ (1 << n); }

TEST(BitManipulation, StringifyBit) { ASSERT_EQ(stringifyBit(1234), "10011010010"); }
TEST(BitManipulation, getBit) { ASSERT_EQ(getBit(1234, 4), 1); }
TEST(BitManipulation, setBit) { ASSERT_EQ(stringifyBit(setBit(1234, 5)), "10011110010"); }
TEST(BitManipulation, clearBit) { ASSERT_EQ(stringifyBit(clearBit(1234, 5)), "10011010010"); }
TEST(BitManipulation, toggleBit) {
    int res = toggleBit(1234, 5);
    ASSERT_EQ(stringifyBit(res), "10011110010");
    res = toggleBit(res, 5);
    ASSERT_EQ(stringifyBit(res), "10011010010");
}
