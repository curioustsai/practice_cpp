#include <stdio.h>

void reverseString(char *str) {
    char *end = str;
    if (str == 0) return;

    while (*end) {
        end++;
    }
    end--;

    while (str < end) {
        char temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

int main(char *argv[], int argc) {
    char str[] = "abc";
    printf("%s\n", str);
    reverseString(str);
    printf("%s\n", str);
    return 0;
}
