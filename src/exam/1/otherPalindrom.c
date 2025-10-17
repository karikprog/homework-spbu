#include <stdio.h>
#include <string.h>

void toBinary(int n, char resultString[])
{
    int i = 0;

    if (n == 0) {
        resultString[0] = '0';
    }
    while (n > 0) {
        resultString[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }
    resultString[i] = '\0';
}

int binPalindrom(int n)
{
    char resultString[100];
    toBinary(n, resultString);
    char reverseString[100];
    int lenStr = strlen(resultString);

    for (int i = 0; i < lenStr; i++) {
        reverseString[i] = resultString[i];
    }

    int start = 0;

    int end = lenStr - 1;
    char temp;

    while (start < end) {
        temp = reverseString[start];
        reverseString[start] = reverseString[end];
        reverseString[end] = temp;
        start++;
        end--;
    }
    int fl = 1;
    for (int i = 0; i < lenStr; i++) {
        if (reverseString[i] != resultString[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n = 100;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (binPalindrom(i)) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}