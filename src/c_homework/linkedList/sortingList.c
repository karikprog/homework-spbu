#include "linkedList.h"
#include <stdio.h>

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

void start(SinglyLinkedList* list)
{
    int cmd;
    int value;
    for (;;) {
        printf("Enter the command: ");
        scanf(" %d", &cmd);
        switch (cmd) {
        case 0:
            return;
        case 1:
            printf("Enter number: ");
            if (scanf("%d", &value) == 1)
                addValueInSortList(list, value);
            else {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
            }
            break;
        case 2:
            printf("Enter number: ");
            if (scanf("%d", &value) == 1)
                deleteValue(list, value);
            else {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
            }
            break;
        case 3:
            printList(list);
            break;
        default:
            printf("Command not exist\n");
            while (getchar() != '\n')
                ;
            break;
        }
    }
}

int main(void)
{
    SinglyLinkedList* list = createSinglyLinkedList();
    start(list);

    deleteList(list);
    return 0;
}