#include "quickSort.h"
#include <stdio.h>
#include <string.h>

int swapCount(int l1[], int l2[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (l1[i] != l2[i]) {
            c++;
        }
    }
    return c;
}
int main()
{
    int values[100];
    int valuesCopy[100];
    int n = 0;
    while (n < 100) {
        int result = scanf("%d", &values[n]);
        if (result == 1) {
            n++;
        } else {
            break;
        }
        int nextChar = getchar();
        if (nextChar == '\n') {
            break;
        }
    }

    memcpy(valuesCopy, values, n * sizeof(int));

    quickSort(values, 0, n - 1);
    int swCount = swapCount(values, valuesCopy, n);
    printf("%d\n", swCount);

    return swCount;
}
