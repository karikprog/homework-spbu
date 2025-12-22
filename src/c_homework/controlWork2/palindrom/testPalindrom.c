#include "list.h"
#include "palindrom.h"
#include "stdio.h"

int testCorrectPalindrom()
{
    List* list = createList();
    int n = 9;
    int values[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    for (int i = 0; i < n; i++) {
        addLast(list, values[i]);
    }
    int result = isPalindrom(list);
    deleteList(&list);
    return result;
}

int testIncorrectPalindrom()
{
    List* list = createList();
    int n = 6;
    int values[] = { 4, 3, 2, 6, 5, 7 };
    for (int i = 0; i < n; i++) {
        addLast(list, values[i]);
    }
    int result = isPalindrom(list);
    deleteList(&list);
    return !result;
}

int testEmptyList()
{
    List* list = createList();
    int result = isPalindrom(list);
    deleteList(&list);
    return result;
}

int testOneValList()
{
    List* list = createList();
    addFirst(list, 5);
    int result = isPalindrom(list);
    return result;
}

void runTest()
{
    printf("---Run tests---");
    int faild = 0;
    if (!testOneValList()) {
        printf("Faild one value list\n");
        faild++;
    } else {
        printf("passed 1\n");
    }
    if (!testCorrectPalindrom()) {
        printf("Faild palindrom\n");
        faild++;
    } else {
        printf("passed 2\n");
    }
    if (!testEmptyList()) {
        printf("Faild empty list\n");
        faild++;
    } else {
        printf("passed 3\n");
    }
    if (!testIncorrectPalindrom()) {
        printf("Faild incorrect palindrom\n");
        faild++;
    } else {
        printf("passed 4\n");
    }
    printf("Faild: %d\n", faild);
    return;
}