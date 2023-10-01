#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNodeLocation;
};

struct Node *insertAfter(int newValue, int afterIndex, struct Node *head) {

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *referenceNode = head;
    int i = 0;
    while (i < afterIndex) {
        referenceNode = referenceNode->nextNodeLocation;
        i++;
    }
    newNode->nextNodeLocation = referenceNode->nextNodeLocation;
    newNode->i = newValue;
    referenceNode->nextNodeLocation = newNode;
    return head;
    // when index is 2
    //10
    //20
    //30
    //45 --> newValue
    //40
}

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


struct Node *insertBefore(int newValue, int afterIndex, struct Node *head) {

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *referenceNode = head;
    int i = 0;
    while (i < afterIndex - 2) {
        referenceNode = referenceNode->nextNodeLocation;
        i++;
    }
    newNode->nextNodeLocation = referenceNode->nextNodeLocation;
    newNode->i = newValue;
    referenceNode->nextNodeLocation = newNode;
    return head;
    // when index is 2
    // 10
    //45 --> newValue
    //20
    //30
    //40
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