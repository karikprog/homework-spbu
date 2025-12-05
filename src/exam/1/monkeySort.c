#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSorted(int values[], int n)
{
    int fl = 1;
    for (int i = 0; i < (n - 1); i++) {
        if (values[i] > values[i + 1]) {
            fl = 0;
            break;
        }
    }
    return fl;
}

void shuffle(int array[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void monkeySort(int values[], int n)
{
    int fl = 1;
    while (fl) {
        shuffle(values, n);
        if (isSorted(values, n)) {
            fl = 0;
            break;
        }
    }
}

int main(void)
{
    int values[] = { 1, 6, 3, 5, 7 };
    int n = sizeof(values) / sizeof(int);
    monkeySort(values, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    return 0;
}