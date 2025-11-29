#include "linkedList.h"
#include "sortingList.h"
#include "testSortingList.h"
#include <stdio.h>
#include <string.h>

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