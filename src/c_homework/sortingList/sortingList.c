#include "linkedList.h"
#include "tests/testSortingList.h"
#include <stdio.h>

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
