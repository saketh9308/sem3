#include <stdio.h>
#include <stdlib.h>


struct Node {
    int i;
    struct Node *nextLocation;
};

struct Node *deletionAtIndex(struct Node *head, int index) {
    struct Node *locationOfDeletingNode = head->nextLocation;
    struct Node *locationOfPreviousNode = head;

    int i = 0;

    while (i < index - 1) {
        locationOfDeletingNode = locationOfDeletingNode->nextLocation;
        locationOfPreviousNode = locationOfPreviousNode->nextLocation;
        i++;
    }

    locationOfPreviousNode->nextLocation = locationOfDeletingNode->nextLocation;
    free(locationOfDeletingNode);

    return head;

    /*
     1
     2
     4
    */
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

    struct Node *modifiedData = deletionAtIndex(head, 2);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextLocation;
    }
}

void main() {
    print();
}