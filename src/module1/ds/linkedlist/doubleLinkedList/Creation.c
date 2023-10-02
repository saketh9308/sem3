#include<stdio.h>
#include<stdlib.h>

struct Node {
    int i;
    struct Node *prevLocation;
    struct Node *nextLocation;
};

void sampleDoubleLinkedList() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));

    head->prevLocation = NULL;
    second->prevLocation = head;
    third->prevLocation = second;

    head->nextLocation = second;
    second->nextLocation = third;
    third->nextLocation = NULL;

    head->i = 1;
    second->i = 2;
    third->i = 3;

    printf("LHS to RHS:\n");

    struct Node *firstNode = head;
    while (firstNode != NULL) {
        printf("%d\n", firstNode->i);
        firstNode = firstNode->nextLocation;
    }

    printf("RHS to LHS:\n");

    struct Node *lastNode = head;
    while (lastNode->nextLocation != NULL) {
        lastNode = lastNode->nextLocation;
    }

    while (lastNode != NULL) {
        printf("%d\n", lastNode->i);
        lastNode = lastNode->prevLocation;
    }
}

void main() {
    sampleDoubleLinkedList();

    /*
     LHS to RHS:
     1
     2
     3
     RHS to LHS:
     3
     2
     1
     */
}