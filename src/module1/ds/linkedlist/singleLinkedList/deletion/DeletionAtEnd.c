#include<stdio.h>
#include<stdlib.h>

struct Node {
    int i;
    struct Node *nextLocation;
};

struct Node *deleteAtEnd(struct Node *head) {
    struct Node *deletionNode = head->nextLocation;
    struct Node *previous = head;

    while (deletionNode->nextLocation != NULL) {
        previous = previous->nextLocation;
        deletionNode = deletionNode->nextLocation;
    }

    previous->nextLocation = NULL;
    free(deletionNode);

    return head;
}

void print() {

    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->i = 1;
    second->i = 2;
    third->i = 3;
    fourth->i = 4;

    head->nextLocation = second;
    second->nextLocation = third;
    third->nextLocation = fourth;
    fourth->nextLocation = NULL;

    struct Node *modifiedData = deleteAtEnd(head);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextLocation;
    }
}

void main() {
    print();

    /*
     1
     2
     3
     */
}