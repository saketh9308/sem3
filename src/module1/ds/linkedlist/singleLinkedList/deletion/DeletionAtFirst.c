#include<stdio.h>
#include<stdlib.h>

struct Node {
    int i;
    struct Node *nextNode;
};

struct Node *deleteAtFirst(struct Node *head) {
    struct Node *firstNode = head;
    struct Node *secondNode = head->nextNode;
    free(firstNode);
    return secondNode;
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

    head->nextNode = second;
    second->nextNode = third;
    third->nextNode = fourth;
    fourth->nextNode = NULL;

    struct Node *modifiedData = deleteAtFirst(head);

    while (modifiedData != NULL) {
        printf("%d\n", modifiedData->i);
        modifiedData = modifiedData->nextNode;
    }
}

void main() {
    print();
    /*
    2
    3
    4
     */
}