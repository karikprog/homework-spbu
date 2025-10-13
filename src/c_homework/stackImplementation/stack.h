#pragma once

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} DynamicStack;

int isEmpty(DynamicStack* s);
void push(DynamicStack* s, int value);
int pop(DynamicStack* s);
int peak(DynamicStack* s);
int sizeStack(DynamicStack* s);
void clearStack(DynamicStack* s);
void destroyStack(DynamicStack* s);
