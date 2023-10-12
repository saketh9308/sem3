#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNodeLocation;
};

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

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNodeLocation;
    }

    /*
     45
     0
     2
     1
     * */
}

int main() {
    printing_InsertionAtFirst_();
    return 0;
}