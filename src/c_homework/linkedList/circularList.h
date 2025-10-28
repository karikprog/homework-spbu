#pragma once

typedef struct CircularListNode {
    int data;
    struct CircularListNode* next;
} CircularListNode;

typedef struct {
    int size;
    struct CircularListNode* head;
} CircularLinkedList;

CircularListNode* createNode();
CircularLinkedList* createCircularLinkedList();
int isEmpty(CircularLinkedList* list);
void addFirst(CircularLinkedList* list, int value);
void addLast(CircularLinkedList* list, int value);
void deleteValue(CircularLinkedList* list, int value);
void deleteList(CircularLinkedList* list);