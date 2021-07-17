#include <iostream>
#include <string>

using namespace std;

void reverseString(string& str) {
    int length = str.size();
    if (length < 2) return;

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    string str = "book";
    cout << str << endl;
    reverseString(str);
    cout << str << endl;

    return 0;
}
