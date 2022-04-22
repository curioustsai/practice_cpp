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

int flipBit2Win(const int num) {
    int n = num;

    return 0;
}

int main(int argc, char *argv[]) {
    int num = 0b11011101111;
    flipBit2Win(num);

    return 0;
}
