#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int i;
    struct Stack *nextElement;
};

struct Stack *addANewElement(int newValue) {
    struct Stack *newNode = (struct Stack *) malloc(sizeof(struct Stack));
    newNode->i = newValue;
    return newNode;
}

struct Stack *pushIntoStack(struct Stack *top) {
    int i = 0;
    while (i < 6) {
        if (top == NULL) {
            struct Stack *newNode = addANewElement(i);
            newNode->nextElement = NULL;
            top = newNode;
        } else {
            struct Stack *newNode = addANewElement(i);
            newNode->nextElement = top;
            top = newNode;
        }
        i++;
    }
    return top;
}

struct Stack *popFromTheStack(struct Stack *top) {
    struct Stack *delNode = top;
    struct Stack *refNode = top->nextElement;
    if (top == NULL) {
        printf("Stack is underflow");
        return NULL;
    } else {
        free(delNode);
        return refNode;
    }
}

int main() {
    struct Stack *top = NULL;
    struct Stack *modifiedStack1 = pushIntoStack(top);
    top = modifiedStack1;
    while (modifiedStack1 != NULL) {
        printf("%d\n", modifiedStack1->i);
        modifiedStack1 = modifiedStack1->nextElement;
    }
    /*
    5
    4
    3
    2
    1
    0
     * */
    struct Stack *modifiedStack2 = popFromTheStack(top);
    while (modifiedStack2 != NULL) {
        printf("%d\n", modifiedStack2->i);
        modifiedStack2 = modifiedStack2->nextElement;
    }
    /*
     4
     3
     2
     1
     0
     * */
}
