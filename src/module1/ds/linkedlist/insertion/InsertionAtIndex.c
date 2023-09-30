#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNodeLocation;
};

struct Node *insertionAtIndex(struct Node *startingOfNode, int index, int newValue) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *existingNode = startingOfNode;
    int i = 0;

    while (i < index - 1) {
        existingNode = existingNode->nextNodeLocation;
        i++;
    }

    newNode->i = newValue;
    newNode->nextNodeLocation = existingNode->nextNodeLocation;
    existingNode->nextNodeLocation = newNode;
    return startingOfNode;
}

void printing_InsertionAtIndex_() {

    struct Node *first;
    struct Node *second;
    struct Node *third;

    first = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    first->i = 1;
    second->i = 2;
    third->i = 3;

    first->nextNodeLocation = third;
    third->nextNodeLocation = second;
    second->nextNodeLocation = NULL;

    struct Node *modifiedData = insertionAtIndex(first, 2, 45);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNodeLocation;
    }

    /*
     1
     3
     45
     2
      */
}

int main() {
    printing_InsertionAtIndex_();
    return 0;
}