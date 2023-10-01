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

    headOfTheNode->i = 1;
    secondNode->i = 3;
    thirdNode->i = 2;

    headOfTheNode->nextNodeLocation = thirdNode;
    thirdNode->nextNodeLocation = secondNode;
    secondNode->nextNodeLocation = NULL;

    while (headOfTheNode != NULL) {
        printf("%d\n", headOfTheNode->i);
        headOfTheNode = headOfTheNode->nextNodeLocation;
    }
    /*
    1
     2
     3
     * */
}


int main() {
    singleLinkedListSample1();
    singleLinkedListSample2();
    return 0;
}