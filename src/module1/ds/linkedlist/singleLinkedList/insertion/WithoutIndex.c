#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *nextNode;
};

struct Node *insertAfter(struct Node *head, int value, int newValue) {
    struct Node *refNode = head;
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->i = newValue;
    newNode->nextNode = refNode;

    while (refNode->i != value) { // for before :: refNode->nextNode->i!=value
        refNode = refNode->nextNode;
    }
    newNode->nextNode = refNode->nextNode;
    refNode->nextNode = newNode;
    return head;
}


int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->i = 1;
    second->i = 2;
    third->i = 3;
    fourth->i = 4;

    head->nextNode = second;
    second->nextNode = third;
    third->nextNode = fourth;
    fourth->nextNode = NULL;

    struct Node *modifiedNode = insertAfter(head, 4, 45);
    while (modifiedNode != NULL) {
        printf("%d\n", modifiedNode->i);
        modifiedNode = modifiedNode->nextNode;
    }
    /*
    1
    2
    3
    45
    4
    */
    return 0;
}