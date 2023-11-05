#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextLocation;
};

struct Node *createANewNode(int newValue) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->i = newValue;
    return newNode;
}

struct Node *pushIntoStack(int limit, struct Node *top) {
    int tempLimit = 0;
    while (tempLimit < limit) {
        if (top == NULL) {
            struct Node *newNode = createANewNode(tempLimit);
            newNode->nextLocation = NULL;
            top = newNode;
        } else {
            struct Node *newNode = createANewNode(tempLimit);
            newNode->nextLocation = top;
            top = newNode;
        }
        tempLimit++;
        if (tempLimit == limit) {
            break;
        }
    }
    return top;
}

struct Node *popFromTheStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is underflow");
        return NULL;
    } else {
        struct Node *delNode = top;
        struct Node *refNode = top->nextLocation;
        free(delNode);
        printf("pop operation is successful\n");
        return refNode;
    }
}

void peekElement(struct Node *top) {
    printf("Value of the peek element is: %d\n", top->i);
}

int main() {
    struct Node *topNode = NULL;
    struct Node *modifiedPushStack = pushIntoStack(4, topNode);
    topNode = modifiedPushStack;
    peekElement(modifiedPushStack);
    while (modifiedPushStack != NULL) {
        printf("%d\n", modifiedPushStack->i);
        modifiedPushStack = modifiedPushStack->nextLocation;
    }
    struct Node *modifiedPopStack = popFromTheStack(topNode);
    while (modifiedPopStack != NULL) {
        printf("%d\n", modifiedPopStack->i);
        modifiedPopStack = modifiedPopStack->nextLocation;
    }
    return 0;
}