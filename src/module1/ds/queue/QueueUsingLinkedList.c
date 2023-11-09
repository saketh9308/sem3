#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNode;
};

struct Node *addANewElement(int newValue) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->i = newValue;
    return newNode;
}

struct Node *insertionInQueue(struct Node *frontNode, struct Node *rearNode) {
    int i = 0;
    while (i < 6) {
        if (frontNode == NULL) {
            frontNode = rearNode = addANewElement(i);
            rearNode->nextNode = NULL;
        } else {
            rearNode->nextNode = addANewElement(i);
            rearNode = rearNode->nextNode;
            rearNode->nextNode = NULL;
        }
        i++;
    }
    return frontNode;
}

struct Node *popFromQueue(struct Node *head) {
    struct Node *refNode = head->nextNode;
    struct Node *delNode = head;
    free(delNode);
    return refNode;
}

int main() {
    /*

     struct Node *frontNode = (struct Node *) malloc(sizeof(struct Node));
     frontNode->i = 45;
     frontNode->nextNode = NULL;
     struct Node *rearNode = frontNode;

     */
    struct Node *frontNode = NULL;
    struct Node *rearNode = NULL;
    struct Node *modifiedNode = insertionInQueue(frontNode, rearNode);
    frontNode = modifiedNode;
    while (modifiedNode != NULL) {
        printf("%d\n", modifiedNode->i);
        modifiedNode = modifiedNode->nextNode;
    }
    /*
     0
     1
     2
     3
     4
     5
     * */
    struct Node *modifiedNode1 = popFromQueue(frontNode);
    while (modifiedNode1 != NULL) {
        printf("%d\n", modifiedNode1->i);
        modifiedNode1 = modifiedNode1->nextNode;
    }
    /*
     1
     2
     3
     4
     5
     * */
}