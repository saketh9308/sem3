#include <stdio.h>
#include <stdlib.h>


struct Node {
    int i;
    struct Node *nextNodeLocation;
};

void singleLinkedListSample1() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));

    head->i = 1;
    head->nextNodeLocation = second;
    second->i = 2;
    second->nextNodeLocation = third;
    third->i = 3;
    third->nextNodeLocation = NULL;

    while (head != NULL) {
        printf("%d\n", head->i);
        head = head->nextNodeLocation;
    }

    /*
     1
     2
     3
     */
}

void singleLinkedListSample2() {
    struct Node *headOfTheNode;
    struct Node *secondNode;
    struct Node *thirdNode;

    headOfTheNode = (struct Node *) malloc(sizeof(struct Node));
    secondNode = (struct Node *) malloc(sizeof(struct Node));
    thirdNode = (struct Node *) malloc(sizeof(struct Node));

    headOfTheNode->i = 23;
    secondNode->i = 45;
    thirdNode->i = 54;

    headOfTheNode->nextNodeLocation = thirdNode;
    thirdNode->nextNodeLocation = secondNode;
    secondNode->nextNodeLocation = NULL;

    while (headOfTheNode != NULL) {
        printf("%d\n", headOfTheNode->i);
        headOfTheNode = headOfTheNode->nextNodeLocation;
    }
    /*
     23
     54
     45
     * */
}

struct Node *insertionAtFirst(struct Node *headOfTheNode, int i) {
    struct Node *modifiedFirstNode = (struct Node *) malloc(sizeof(struct Node));
    modifiedFirstNode->i = i;
    modifiedFirstNode->nextNodeLocation = headOfTheNode;
    return modifiedFirstNode;
}

void printing_InsertionAtFirst_() {

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

    struct Node *modifiedData = insertionAtFirst(first, 45);

    while (modifiedData->nextNodeLocation != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNodeLocation;
    }

    /*
     45
     0
     2
     * */
}

struct Node *insertionAtIndex(struct Node *startingOfNode, int index, int newValue) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    struct Node *existingNode = startingOfNode;
    int i = 0;
    while (i < index) {
        existingNode = existingNode->nextNodeLocation;
        i++;
    }

    newNode->i = newValue;
    newNode->nextNodeLocation = existingNode->nextNodeLocation -;
    existingNode->nextNodeLocation = newNode;
    return newNode;
}

void printing_InsertionAtIndex_() {

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

    struct Node *modifiedData = insertionAtIndex(first, 1, 45);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNodeLocation;
    }

    /*
     45
     0
     2
     * */
}

int main() {
    //singleLinkedListSample1();
    //singleLinkedListSample2();
    //printing_InsertionAtFirst_();
    printing_InsertionAtIndex_();
    return 0;
}