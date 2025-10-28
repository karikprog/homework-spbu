#include "circularList.h"
#include <stdio.h>
#include <stdlib.h>

CircularListNode* createNode()
{
    CircularListNode* node = (CircularListNode*)malloc(sizeof(CircularListNode));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    return node;
}

CircularLinkedList* createCircularLinkedList()
{
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if (list == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;

    return list;
}

int isEmpty(CircularLinkedList* list)
{
    if (list->head == NULL) {
        return 1;
    }
    return 0;
}

void addFirst(CircularLinkedList* list, int value)
{
    CircularListNode* node = createNode();
    node->data = value;
    if (isEmpty(list)) {
        list->head = node;
        list->head->next = node;
        list->size++;
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
    return;
}

void addLast(CircularLinkedList* list, int value)
{
    CircularListNode* node = createNode();
    node->data = value;
    if (isEmpty(list)) {
        list->head = node;
        list->head->next = node;
        list->size++;
        return;
    }
    CircularListNode* curr = list->head;
    while (curr->next != list->head) {
        curr = curr->next;
    }
    node->next = list->head;
    curr->next = node;
    list->size++;
    return;
}

void deleteValue(CircularLinkedList* list, int value)
{
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    CircularListNode* curr = list->head;
    CircularListNode* prev = NULL;

    if (curr->next == list->head && curr->data == value) {
        free(curr);
        list->head = NULL;
        list->size = 0;
        return;
    }

    if (curr->data == value) {
        CircularListNode* tail = list->head;
        while (tail->next != list->head)
            tail = tail->next;

        list->head = curr->next;
        tail->next = list->head;
        free(curr);
        list->size--;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            list->size--;
            return;
        }
    } while (curr != list->head);

    printf("Value not found\n");
}

void deleteList(CircularLinkedList* list)
{
    if (isEmpty(list)) {
        free(list);
        return;
    }

    CircularListNode* curr = list->head;
    CircularListNode* next;

    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != list->head);

    free(list);
}