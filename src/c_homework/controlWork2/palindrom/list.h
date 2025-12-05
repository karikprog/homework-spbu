#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    int size;
    struct Node* head;
} List;

Node* createNode();
List* createList();
void printList(List* list);
void addFirst(List* list, int value);
void deleteList(List** listRef);
void addLast(List* list, int value);
