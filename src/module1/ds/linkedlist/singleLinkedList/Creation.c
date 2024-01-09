#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNodeLocation;
};


struct Node *creation() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));

    head->i = 1;
    head->nextNodeLocation = second;
    second->i = 2;
    second->nextNodeLocation = third;
    third->i = 3;
    third->nextNodeLocation = NULL;
    return head;
}

struct Node *insertionAtFirst(struct Node *headOfTheNode, int i) {
    struct Node *modifiedFirstNode = (struct Node *) malloc(sizeof(struct Node));
    modifiedFirstNode->i = i;
    modifiedFirstNode->nextNodeLocation = headOfTheNode;
    return modifiedFirstNode;
}

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

void insertInBetween(struct Node *prevNode, int newData, int insertAfter) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    while (prevNode->nextNodeLocation->i == insertAfter) {
        prevNode = prevNode->nextNodeLocation;
    }
    newNode->i = newData;
    newNode->nextNodeLocation = prevNode->nextNodeLocation;
    prevNode->nextNodeLocation = newNode;
}

struct Node *deleteAtFirst(struct Node *head) {
    struct Node *firstNode = head;
    struct Node *secondNode = head->nextNodeLocation;
    free(firstNode);
    return secondNode;
}

struct Node *deleteAtEnd(struct Node *head) {
    struct Node *deletionNode = head->nextNodeLocation;
    struct Node *previous = head;

    while (deletionNode->nextNodeLocation != NULL) {
        previous = previous->nextNodeLocation;
        deletionNode = deletionNode->nextNodeLocation;
    }

    previous->nextNodeLocation = NULL;
    free(deletionNode);
    return head;
}

struct Node *deletionAfter(struct Node *head, int index) {
    struct Node *locationOfDeletingNode = head->nextNodeLocation;
    struct Node *locationOfPreviousNode = head;

    int i = 0;

    while (locationOfPreviousNode->nextNodeLocation->i == index) {
        locationOfDeletingNode = locationOfDeletingNode->nextNodeLocation;
        locationOfPreviousNode = locationOfPreviousNode->nextNodeLocation;
        i++;
    }

    locationOfPreviousNode->nextNodeLocation = locationOfDeletingNode->nextNodeLocation;
    free(locationOfDeletingNode);

    return head;
}

int main() {
    struct Node *rootNode1 = creation();
    struct Node *rootNode2 = creation();
    struct Node *rootNode3 = creation();
    rootNode1 = insertionAtFirst(rootNode1, 101);
    printf("\nrootNode1:\n");
    while (rootNode1 != NULL) {
        printf("%d\n", rootNode1->i);
        rootNode1 = rootNode1->nextNodeLocation;
    }
    insertInBetween(rootNode2, 202, 2);
    printf("\nrootNode2:\n");
    while (rootNode2 != NULL) {
        printf("%d\n", rootNode2->i);
        rootNode2 = rootNode2->nextNodeLocation;
    }
    insertionAtEnd(rootNode3, 303);
    printf("\nrootNode3:\n");
    while (rootNode3 != NULL) {
        printf("%d\n", rootNode3->i);
        rootNode3 = rootNode3->nextNodeLocation;
    }
    struct Node *rootNode4 = creation();
    struct Node *rootNode5 = creation();
    struct Node *rootNode6 = creation();

    rootNode4 = deleteAtFirst(rootNode4);
    printf("\nrootNode4:\n");
    while (rootNode4 != NULL) {
        printf("%d\n", rootNode4->i);
        rootNode4 = rootNode4->nextNodeLocation;
    }

    rootNode5 = deletionAfter(rootNode5, 1);
    printf("\nrootNode5:\n");
    while (rootNode5 != NULL) {
        printf("%d\n", rootNode5->i);
        rootNode5 = rootNode5->nextNodeLocation;
    }

    rootNode6 = deleteAtEnd(rootNode6);
    printf("\nrootNode6:\n");
    while (rootNode6 != NULL) {
        printf("%d\n", rootNode6->i);
        rootNode6 = rootNode6->nextNodeLocation;
    }
    return 0;
}

/*
 Output:
    rootNode1:
    101
    1
    2
    3
    
    rootNode2:
    1
    2
    202
    3

    rootNode3:
    1
    2
    3
    303

    rootNode4:
    2
    3

    rootNode5:
    1
    3

    rootNode6:
    1
    2
 * */