#include <math.h>
#include <stdio.h>

typedef union {
    double value;
    unsigned char binaryForm[8];
} Number;

void parseDouble(Number num, double* mant, int* pow)
{
    unsigned long long rawBits = 0;
    for (int i = 7; i >= 0; i--) {
        rawBits = (rawBits << 8) | num.binaryForm[i];
    }

    unsigned int sign = (rawBits >> 63) & 1;

    unsigned int rawExponent = (rawBits >> 52) & 0x7FF;

    unsigned long long mantissaBits = rawBits & 0xFFFFFFFFFFFFF;

    int p = (int)rawExponent - 1023;

    double m = 1.0 + (double)mantissaBits / 4503599627370496.0;

    if (sign == 1) {
        *mant = -m;
    }
    *pow = p;

    if (rawExponent == 0 && mantissaBits == 0) {
        *mant = 0.0;
        *pow = 0;
    }
}

int main()
{
    Number num;

    printf("Enter a number: ");
    if (scanf("%lf", &num.value) != 1) {
        printf("Error reading input.\n");
        return 1;
    }
    int pow;
    double mant;

    parseDouble(num, &mant, &pow);
    printf("Result: %.15g*2^%d\n", mant, pow);

    return 0;
}