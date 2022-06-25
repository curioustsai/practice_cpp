#include <gtest/gtest.h>
#include <string>

using namespace std;
// n factorial with zeros
int countFive(int n) {
    if (n < 5) return 0;
    int count = 0;

    for (int i = 5; i <= n; i++) {
        int num = i;
        while (num % 5 == 0) {
            num /= 5;
            count++;
        }
    }

    return count;
}

int factorial(int n) {
    if (n <= 2) return n;
    return factorial(n - 1) * n;
}

TEST(Medium, FactorialZeros) {
    ASSERT_EQ(factorial(10), 3628800);
    ASSERT_EQ(countFive(10), 2);
}
