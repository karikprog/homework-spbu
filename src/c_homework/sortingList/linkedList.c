#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

SinglyListNode* createNode()
{
    SinglyListNode* node = (SinglyListNode*)malloc(sizeof(SinglyListNode));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    return node;
}

SinglyLinkedList* createSinglyLinkedList()
{
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (list == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;

    return list;
}

int isEmpty(SinglyLinkedList* list)
{
    if (list->head == NULL) {
        return 1;
    }
    return 0;
}

int getSize(SinglyLinkedList* list)
{
    return list->size;
}

void deleteList(SinglyLinkedList** listRef)
{
    if (listRef == NULL || *listRef == NULL) {
        return;
    }
    SinglyLinkedList* list = *listRef;

    while (list->head != NULL) {
        SinglyListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
    free(list);
    *listRef = NULL;
}

void addFirst(SinglyLinkedList* list, int value)
{
    SinglyListNode* node = createNode();
    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}
void addLast(SinglyLinkedList* list, int value)
{
    SinglyListNode* node = createNode();
    node->data = value;
    if (list->head == NULL) {
        node->next = list->head;
        list->head = node;
        list->size++;
    } else {
        SinglyListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        node->next = NULL;
        current->next = node;
        list->size++;
    }
}

int getValue(SinglyLinkedList* list, int index)
{
    if (index > list->size - 1) {
        printf("Index out of range\n");
        return -1;
    }
    SinglyListNode* curr = list->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

int deleteValue(SinglyLinkedList* list, int value)
{
    if (list->head == NULL) {
        printf("List is empty\n");
        return 1;
    }
    SinglyListNode* curr = list->head;

    if (curr->data == value) {
        list->head = list->head->next;
        free(curr);
        list->size--;
        return 0;
    }
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        printf("Value not found\n");
        return 1;
    }

    SinglyListNode* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    list->size--;
    return 0;
}

void printList(SinglyLinkedList* list)
{
    if (list->head == NULL) {
        printf("I`m empty\n");
        return;
    }

    SinglyListNode* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int addValueInSortList(SinglyLinkedList* list, int value)
{
    if (isEmpty(list) || value < list->head->data) {
        addFirst(list, value);
        return 0;
    }
    SinglyListNode* curr = list->head;
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    SinglyListNode* node = createNode();
    node->data = value;
    node->next = curr->next;
    curr->next = node;
    list->size++;
    return 0;
}