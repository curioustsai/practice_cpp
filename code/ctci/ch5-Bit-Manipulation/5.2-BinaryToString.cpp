#include <iostream>
#include <string>

using namespace std;

// Given [0, 1], convert to string
string binaryToString(const double num) {
    string str("");
    if (num > 1 || num < 0) return "ERROR";

    str.append(".");
    double n = num;
    while (n > 0) {
        if (str.length() >= 32) return "ERROR";

        double r = n * 2;
        if (r >= 1) {
            str.append("1");
            n = r - 1;
        } else {
            str.append("0");
            n = r;
        }
    }

    return str;
}

int main(int argc, char* agrv[]) {
    cout << binaryToString(2.0) << endl;
    cout << binaryToString(-2.0) << endl;
    cout << binaryToString(0.75) << endl;
    cout << binaryToString(0.8) << endl;

    return 0;
}
