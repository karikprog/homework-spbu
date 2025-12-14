#pragma once

typedef struct SinglyListNode {
    int data;
    struct SinglyListNode* next;
} SinglyListNode;

typedef struct {
    int size;
    struct SinglyListNode* head;

} SinglyLinkedList;

SinglyListNode* createNode();
SinglyLinkedList* createSinglyLinkedList();
int isEmpty(SinglyLinkedList* list);
int getSize(SinglyLinkedList* list);
void deleteList(SinglyLinkedList** list);
void addFirst(SinglyLinkedList* list, int value);
void addLast(SinglyLinkedList* list, int value);
// void insert(SinglyLinkedList* list, int value, int index);
int getValue(SinglyLinkedList* list, int index);
int deleteValue(SinglyLinkedList* list, int value);
void printList(SinglyLinkedList* list);
int addValueInSortList(SinglyLinkedList* list, int value);