#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    return node;
}

List* createList()
{
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;

    return list;
}

void deleteList(List** listRef)
{
    if (listRef == NULL || *listRef == NULL) {
        return;
    }
    List* list = *listRef;

    while (list->head != NULL) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
    free(list);
    *listRef = NULL;
}

void addLast(List* list, int value)
{
    Node* node = createNode();
    node->data = value;
    if (list->head == NULL) {
        node->next = list->head;
        list->head = node;
        list->size++;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        node->next = NULL;
        current->next = node;
        list->size++;
    }
}

void printList(List* list)
{
    if (list->head == NULL) {
        printf("I`m empty\n");
        return;
    }

    Node* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void addFirst(List* list, int value)
{
    Node* node = createNode();
    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}