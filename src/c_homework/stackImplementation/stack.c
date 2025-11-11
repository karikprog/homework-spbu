#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

DynamicStack* createStack()
{
    DynamicStack* stack = (DynamicStack*)malloc(sizeof(DynamicStack));
    if (stack == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(DynamicStack* s)
{
    return s->top == NULL;
}

void push(DynamicStack* s, int value)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(DynamicStack* s)
{
    if (isEmpty(s)) {
        printf("Error: stack is empty");
        exit(1);
    }
    StackNode* temp = s->top;
    int popVal = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;

    return popVal;
}

int peak(DynamicStack* s)
{
    if (isEmpty(s)) {
        printf("Error: stack is empty");
        exit(1);
    }

    return s->top->data;
}

int sizeStack(DynamicStack* s)
{
    return s->size;
}

void clearStack(DynamicStack* s)
{
    while (!isEmpty(s)) {
        pop(s);
    }
}

void destroyStack(DynamicStack* s)
{
    clearStack(s);
    free(s);
}
