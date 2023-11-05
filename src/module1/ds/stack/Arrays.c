#include <stdio.h>
#define MAX_STACK_SIZE 4

int stackArray[MAX_STACK_SIZE];
int top = -1;

void pushIntoTheStack(int newValue) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack is full and %d can't be added\n", newValue);
    } else {
        top++;
        stackArray[top] = newValue;
        printf("Added: %d\n", newValue);
    }
}

void popFromTheStack() {
    if (top == -1) {
        printf("Stack is underflow");
    } else {
        stackArray[top] = (int) NULL;
        top--;
    }
}

void main() {
    pushIntoTheStack(3);
    pushIntoTheStack(2);
    pushIntoTheStack(42);
    pushIntoTheStack(442);
    pushIntoTheStack(4);
    printf("Before pop\n");
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        printf("%d\n", stackArray[i]);
    }
    popFromTheStack();
    printf("after pop\n");
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        printf("%d\n", stackArray[i]);
    }
}