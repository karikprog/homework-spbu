#include "../linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int testEmptyList()
{
    SinglyLinkedList* list1 = createSinglyLinkedList();
    SinglyLinkedList* list2 = createSinglyLinkedList();
    addFirst(list1, 3);

    int result = !isEmpty(list1) && isEmpty(list2);
    deleteList(&list1);
    deleteList(&list2);
    return !result;
}

int testGetSize()
{
    int data[] = { 12, 33, 123, 4, 545, 55, 45, 54, 554, 66, 6123, 33 };
    int len = sizeof(data) / sizeof(int);
    SinglyLinkedList* list1 = createSinglyLinkedList();
    for (int i = 0; i < len; i++) {
        addFirst(list1, data[i]);
    }

    int result = getSize(list1);
    deleteList(&list1);
    return !(result == len);
}

int testAddFirst()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    addFirst(list, 12);
    addFirst(list, 10);
    int result = list->head->data;
    int nextVal = list->head->next->data;
    deleteList(&list);
    return !(result == 10 && nextVal == 12);
}

int testAddLast()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    int data[] = { 12, 33, 123, 4, 545, 55, 45, 54, 554, 66, 6123, 33 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        addFirst(list, data[i]);
    }
    addLast(list, 64);
    SinglyListNode* node = createNode();
    node = list->head;
    for (int i = 0; i < len; i++) {
        node = node->next;
    }
    int result = node->data == 64 && node->next == NULL;
    deleteList(&list);
    return !(result);
}

int testGetValue()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    int data[] = { 12, 33, 123, 4, 545, 55, 45, 54, 554, 66, 6123, 33 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        addLast(list, data[i]);
    }

    int val = getValue(list, 4);
    int incorrectVal = getValue(list, 1233);
    deleteList(&list);
    return !(val == 545 && incorrectVal == -1);
}

int testDeleteValue()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    int data[] = { 12, 33, 123, 4, 545, 55, 45, 54, 554, 66, 6123, 33 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        addLast(list, data[i]);
    }
    int err = deleteValue(list, 4);
    if (err != 0) {
        return 1;
    }
    int resultIncorrect = deleteValue(list, 999);
    SinglyListNode* node = createNode();
    node = list->head;
    for (int i = 0; i < 2; i++) {
        node = node->next;
    }
    int result = node->next->data == 545;
    deleteList(&list);
    return !(result && resultIncorrect);
}

int testDeleteOneValueList()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    SinglyListNode* node = createNode();
    node->data = 6;
    list->head = node;
    int err = deleteValue(list, 6);
    if (err != 0) {
        return 1;
    }
    int result = list->head == NULL;
    deleteList(&list);
    return !result;
}

int testAddValueInSortList()
{
    SinglyLinkedList* list = createSinglyLinkedList();
    int data[] = { 12, 33, 123, 4, 545, 55, 45, 54, 554, 66, 6123, 33 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        addValueInSortList(list, data[i]);
    }
    SinglyListNode* currNode = createNode();
    currNode = list->head;
    int result = 1;
    for (int i = 0; i < len - 1; i++) {
        if (currNode->data > currNode->next->data) {
            result = 0;
            break;
        }
        currNode = currNode->next;
    }
    deleteList(&list);
    return !result;
}

int runTest()
{
    printf("---- Run Test ----\n");
    int failures = 0;
    if (testEmptyList() != 0) {
        fprintf(stderr, "FAILURE: Empty check error\n");
        failures++;
    } else {
        printf("Test 1 PASSED.\n");
    }
    if (testAddFirst() != 0) {
        fprintf(stderr, "FAILURE: Adding to beginning error\n");
        failures++;
    } else {
        printf("Test 2 PASSED.\n");
    }
    if (testAddLast() != 0) {
        fprintf(stderr, "FAILURE: Append error\n");
        failures++;
    } else {
        printf("Test 3 PASSED.\n");
    }
    if (testAddValueInSortList() != 0) {
        fprintf(stderr, "FAILURE: Add value in sort list error\n");
        failures++;
    } else {
        printf("Test 4 PASSED.\n");
    }
    if (testDeleteOneValueList() != 0) {
        fprintf(stderr, "FAILURE: Deleting from singleton list error\n");
        failures++;
    } else {
        printf("Test 5 PASSED.\n");
    }
    if (testDeleteValue() != 0) {
        fprintf(stderr, "FAILURE: Delete value error\n");
        failures++;
    } else {
        printf("Test 6 PASSED.\n");
    }
    if (testGetSize() != 0) {
        fprintf(stderr, "FAILURE: Get size error\n");
        failures++;
    } else {
        printf("Test 7 PASSED.\n");
    }
    if (testGetValue() != 0) {
        fprintf(stderr, "FAILURE: Get value error\n");
        failures++;
    } else {
        printf("Test 8 PASSED.\n");
    }
    if (failures > 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}