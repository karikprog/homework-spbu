#include "circularList.h"
#include <stdio.h>

int countingRhyme(int n, int m)
{
    if (n < 1 || m < 1) {
        printf("Invalid argument\n");
        return -1;
    }

    CircularLinkedList* list = createCircularLinkedList();
    for (int i = 1; i <= n; i++) {
        addLast(list, i);
    }

    CircularListNode* curr = list->head;
    int position = 1;
    while (list->size > 1) {
        if (position % m == 0) {
            int v = curr->data;
            curr = curr->next;
            deleteValue(list, v);
        } else {
            curr = curr->next;
        }
        position++;
    }
    int k = curr->data;
    deleteList(list);
    return k;
}

int main(void)
{
    int k = countingRhyme(12, 3);
    if (k != -1) {
        printf("%d\n", k);
    }
    return 0;
}