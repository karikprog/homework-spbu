#include "testCircleShift.h"
#include <stdio.h>

int maxCircleShift(int bin[], int n)
{
    int max = 0;

    int rotated[32];
    for (int i = 0; i < n; i++) {
        rotated[i] = bin[i];
    }
    for (int r = 0; r < n; r++) {
        int value = 0;
        for (int i = 0; i < n; i++) {
            value = (value << 1) | rotated[i];
        }
        if (value > max)
            max = value;

        int first = rotated[0];
        for (int i = 0; i < n - 1; i++) {
            rotated[i] = rotated[i + 1];
        }
        rotated[n - 1] = first;
    }
    return max;
}
int main()
{
    int n;
    printf("Введите длину числа (<=32): ");
    scanf("%d", &n);

    int bin[32];
    printf("Введите биты числа:\n");
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        bin[i] = temp;
    }
    printf("Максимальное значение: %u\n", maxCircleShift(bin, n));
    return 0;
}
