// Two 32-bit numbers, N, M and two bit position i and j.
// Write a method to insert M into N such that M start at bit j and at bit i.

// review of bit operation

// clear bit i
// x &= ~(1 << i)

// toggle bit i
// x ^= (1 << i)

// get bit i of x
// x & (1 << i)

// set bit i of x
// x |= (1 << i)

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

#include <iostream>
#include <string>

using namespace std;

string toBinary(const int num) {
    string bits;
    int n = num;
    while (n) {
        bits = to_string(n & 1) + bits;
        n >>= 1;
    }

    return bits;
}

int insert(const int N, const int M, const int i, const int j) {

    int new_n = N;
    for (int index_n = i, index_m = 0; index_n <= j; index_n++, index_m++) {
        new_n &= ~(1 << index_n);
        int temp = M & (1 << index_m);
        new_n |= (temp << i);
    }

    return new_n;
}

int main(int argc, char *argv[]) {
    int N = 0b10000000000;
    int M = 0b10011;
    // int new_n = 0b10001001100;

    int new_n = insert(N, M, 2, 6);
    cout << "N: " << toBinary(N) << endl;
    cout << "M: " << toBinary(M) << endl;
    cout << "New N: " << toBinary(new_n) << endl;

    return 0;
}
