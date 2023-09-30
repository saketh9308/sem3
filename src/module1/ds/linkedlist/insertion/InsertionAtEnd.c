#include<stdio.h>
#include<stdlib.h>

struct Node {
    int i;
    struct Node *nextNodeLocation;
};

struct Node *insertionAtEnd(struct Node *head, int newValue) {

    struct Node *modifiedNode = (struct Node *) malloc(sizeof(struct Node *));
    modifiedNode->i = newValue;
    struct Node *existingNode = head;
    while (existingNode->nextNodeLocation != NULL) {
        existingNode = existingNode->nextNodeLocation;
    }
    if (existingNode->nextNodeLocation == NULL) {
        existingNode->nextNodeLocation = modifiedNode;
    }
    modifiedNode->nextNodeLocation = NULL;
    return head;
}

void printing_InsertionAtEnd_() {

    struct Node *first;
    struct Node *second;
    struct Node *third;

    first = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    first->i = 0;
    second->i = 1;
    third->i = 2;

    first->nextNodeLocation = third;
    third->nextNodeLocation = second;
    second->nextNodeLocation = NULL;

    struct Node *modifiedData = insertionAtEnd(first, 45);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNodeLocation;
    }

    /*
     0
     2
     1
     45
     * */
}

int main() {
    printing_InsertionAtEnd_();
    return 0;
}