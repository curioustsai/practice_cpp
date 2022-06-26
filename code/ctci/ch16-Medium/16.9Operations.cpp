// Write method to implement the multiply, subtract and divide operations for integers.
//The results of all of these are integers. Use only the add operator

#include <gtest/gtest.h>

namespace practice {
int negate(int x) { return (x == INT32_MIN) ? INT32_MAX : ~x + 1; }
int multiply(int x, int y) {
    int res = 0;
    bool sign = true;
    if (x > 0 && y < 0) {
        y = negate(y);
        sign = false;
    } else if (x < 0 && y > 0) {
        x = negate(x);
        sign = false;
    } else if (x < 0 && y < 0) {
        x = negate(x);
        y = negate(y);
    }
    for (int i = 1; i <= y; i++) { res += x; }
    return (sign == false) ? negate(res) : res;
}

int divide(int x, int y) {
    bool sign = true;
    if (x > 0 && y < 0) {
        y = negate(y);
        sign = false;
    } else if (x < 0 && y > 0) {
        x = negate(x);
        sign = false;
    } else if (x < 0 && y < 0) {
        x = negate(x);
        y = negate(y);
    }

    int count = 0;
    int temp = y;
    while (temp <= x) {
        count++;
        temp += y;
    }

    return (sign == false) ? negate(count) : count;
}

} // namespace practice

TEST(Opertor, Negate) {
    ASSERT_EQ(practice::negate(100), -100);
    ASSERT_EQ(practice::negate(-123), 123);
    ASSERT_EQ(practice::negate(2147483647), -2147483647);
    ASSERT_EQ(practice::negate(-2147483648), 2147483647);
}

TEST(Operater, Substract) {
    ASSERT_EQ(1 - 2, 1 + practice::negate(2));
    //TODO consider overflow
    //ASSERT_EQ(INT32_MIN - INT32_MAX, INT32_MIN + practice::negate(INT32_MAX));
}

TEST(Operater, Muplitply) {
    ASSERT_EQ(5 * 4, practice::multiply(5, 4));
    ASSERT_EQ(5 * -4, practice::multiply(5, -4));
    ASSERT_EQ(-5 * 4, practice::multiply(-5, 4));
    ASSERT_EQ(-5 * -4, practice::multiply(-5, -4));
}

TEST(Operater, Divide) {
    ASSERT_EQ(20 / 4, practice::divide(20, 4));
    ASSERT_EQ(20 / -4, practice::divide(20, -4));
    ASSERT_EQ(-20 / 4, practice::divide(-20, 4));
    ASSERT_EQ(-20 / -4, practice::divide(-20, -4));

    ASSERT_EQ(22 / 4, practice::divide(22, 4));
    ASSERT_EQ(22 / -4, practice::divide(22, -4));
    ASSERT_EQ(-22 / 4, practice::divide(-22, 4));
    ASSERT_EQ(-22 / -4, practice::divide(-22, -4));
}
