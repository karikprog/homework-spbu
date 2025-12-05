#include "list.h"
#include "testPalindrom.h"
#include <stdio.h>

int isPalindrom(List* list)
{
    if (list->size <= 1) {
        return 1;
    }
    List* listRev = createList();
    Node* curr = list->head;
    for (int i = 0; i < list->size; i++) {
        addFirst(listRev, curr->data);
        curr = curr->next;
    }
    Node* left = list->head;
    Node* rihgt = listRev->head;
    for (int i = 0; i < list->size; i++) {
        if (left->data != rihgt->data) {
            deleteList(&listRev);
            return 0;
        }
        left = left->next;
        rihgt = rihgt->next;
    }
    deleteList(&listRev);
    return 1;
}

int start()
{
    int n = 0;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    List* list = createList();
    printf("Введите через пробел: ");
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addLast(list, val);
    }
    int result = isPalindrom(list);
    deleteList(&list);
    return result;
}

int main(void)
{
    if (start()) {
        printf("Палиндром\n");
    } else {
        printf("Не палиндром\n");
    }
    runTest();

    return 0;
}