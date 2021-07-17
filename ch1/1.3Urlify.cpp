#include <cstring>
#include <iostream>

using namespace std;

void Urlify(char* str, int length) {
    int capacity = strlen(str);

    // find all ' '
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') count++;
    }
    int length_all = length + 2 * count;

    int index_new = length_all - 1;
    int index_old = length - 1;
    while (index_old >= 0) {
        if (str[index_old] != ' ') {
            str[index_new--] = str[index_old--];
        } else {
            str[index_new--] = '0';
            str[index_new--] = '2';
            str[index_new--] = '%';
            index_old--;
        }
    }
}

int main() {
    char str[] = "Mr John Smith      ";
    Urlify(str, 13);
    cout << str << endl;

    return 0;
}
