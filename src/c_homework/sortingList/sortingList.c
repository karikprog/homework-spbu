#include "linkedList.h"
#include "tests/testSortingList.h"
#include <stdio.h>
#include <string.h>

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

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0) {
            return runTest();
        }
    }
    SinglyLinkedList* list = createSinglyLinkedList();
    start(list);

    deleteList(&list);
    return 0;
}