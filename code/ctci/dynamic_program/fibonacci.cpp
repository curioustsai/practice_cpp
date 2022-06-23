#include <gtest/gtest.h>

// recursive version
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// dynamic_program
int fibonacci_dp(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int* mem = new int[n];
    mem[0] = 0;
    mem[1] = 1;

    for (int i = 2; i <= n; i++) { mem[i] = mem[i - 1] + mem[i - 2]; }
    delete[] mem;

    return mem[n];
}

TEST(fibonacci, recursive) { ASSERT_EQ(fibonacci(10), 55); }
TEST(fibonacci, dynamic_program) { ASSERT_EQ(fibonacci_dp(10), 55); }
