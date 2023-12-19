#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
};

void insertDataInTheBinaryTree(struct Node *node) {
    int leftBool;
    printf("Do you want to insert the value in the leftChild of %d? 0 or 1", node->i);
    scanf("%d", &leftBool);
    if (leftBool) {
        int currentValue;
        printf("enter the value of leftChild of %d = ", node->i);
        scanf("%d", &currentValue);
        node->leftChild = (struct Node *) malloc(sizeof(struct Node));
        node->leftChild->i = currentValue;
        insertDataInTheBinaryTree(node->leftChild);
    }

    int rightBool;
    printf("Do you want to enter the data in rightChild of %d? 0 or 1", node->i);
    scanf("%d", &rightBool);

    if (rightBool) {
        int currentValue;
        printf("Enter the value for right child of %d", node->i);
        scanf("%d", &currentValue);
        node->rightChild = (struct Node *) malloc(sizeof(struct Node));
        node->rightChild->i = currentValue;
        insertDataInTheBinaryTree(node->rightChild);
    }
}

void main() {
    struct Node *rootNode = (struct Node *) malloc(sizeof(struct Node));
    int rootValue;
    printf("Enter the value of root Node = ");
    scanf("%d", &rootValue);
    rootNode->i = 10;
    insertDataInTheBinaryTree(rootNode);
}