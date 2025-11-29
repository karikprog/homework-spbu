#include "circularList.h"
#include <stdio.h>
#include <stdlib.h>

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

    CircularListNode* prev = list->head;
    while (prev->next != list->head) {
        prev = prev->next;
    }

    while (list->size > 1) {

        for (int i = 0; i < m - 1; i++) {
            prev = prev->next;
        }

        CircularListNode* victim = prev->next;

        if (victim == list->head) {
            list->head = victim->next;
        }

        prev->next = victim->next;

        free(victim);
        list->size--;
    }
    int k = list->head->data;
    deleteList(list);
    return k;
}

int main(void)
{
    int n;
    int m;
    printf("Введите n и m через пробел ");
    scanf("%d %d", &n, &m);
    int k = countingRhyme(n, m);
    if (k != -1) {
        printf("%d\n", k);
    }
    return 0;
}