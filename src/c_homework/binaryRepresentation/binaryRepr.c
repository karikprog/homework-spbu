#include <math.h>
#include <stdint.h>
#include <stdio.h>

void toBin(int x, int bits, int out[])
{
    for (int i = bits - 1; i >= 0; i--) {
        out[i] = x & 1;
        x >>= 1;
    }
    return;
}
void sumBin(int x[], int y[], int bits, int out[])
{
    int carry = 0;
    for (int i = bits - 1; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;

        out[i] = sum & 1;
        carry = (sum >> 1) & 1;
    }
}

void printBin(int x[], int bits)
{
    int isStart = 0;
    for (int i = 0; i < bits; i++) {
        if (isStart) {
            printf("%d", x[i]);
        } else if (x[i] == 1) {
            printf("%d", x[i]);
            isStart = 1;
        }
    }
    printf("\n");
    return;
}

int toDec(int x[], int bits)
{
    int value = 0;
    for (int i = 0; i < bits; i++) {
        value = (value << 1) | x[i];
    }
    return value;
}
int main(void)
{
    int a;
    int b;
    int bits = 32;
    int binA[bits];
    int binB[bits];
    int result[bits];
    printf("Введите 2 числа через пробел: ");
    scanf("%d %d", &a, &b);
    toBin(a, bits, binA);
    toBin(b, bits, binB);
    printf("1 число: ");
    printBin(binA, bits);
    printf("2 число: ");
    printBin(binB, bits);
    sumBin(binA, binB, bits, result);
    printf("Сумма в двоичном: ");
    printBin(result, bits);
    printf("Результат в десятичном: %d\n", toDec(result, bits));
    return 0;
}