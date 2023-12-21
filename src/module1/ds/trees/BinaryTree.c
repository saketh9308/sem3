#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
};

void insertDataInTheBinaryTree(struct Node *node) {
    int leftBool;
    printf("Do you want to insert the value in the leftChild of %d? 0 or 1:\n", node->i);
    scanf("%d", &leftBool);
    if (leftBool) {
        int currentValue;
        printf("enter the value of leftChild of %d:\n", node->i);
        scanf("%d", &currentValue);
        node->leftChild = (struct Node *) malloc(sizeof(struct Node));
        node->leftChild->i = currentValue;
        node->leftChild->leftChild = NULL;
        node->leftChild->rightChild = NULL;
        insertDataInTheBinaryTree(node->leftChild);
    }

    int rightBool;
    printf("Do you want to enter the data in rightChild of %d? 0 or 1:\n", node->i);
    scanf("%d", &rightBool);

    if (rightBool) {
        int currentValue;
        printf("Enter the value for right child of %d:\n", node->i);
        scanf("%d", &currentValue);
        node->rightChild = (struct Node *) malloc(sizeof(struct Node));
        node->rightChild->i = currentValue;
        node->rightChild->leftChild = NULL;
        node->rightChild->rightChild = NULL;
        insertDataInTheBinaryTree(node->rightChild);
    }
}


void preOrderTraversal(struct Node *node) { // Parent Node -> Left Child -> Right Child
    if (node == NULL) {
        return;
    }
    printf("%d ", node->i);
    preOrderTraversal(node->leftChild);
    preOrderTraversal(node->rightChild);
}

void inOrderTraversal(struct Node *node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->leftChild);
    printf("%d ", node->i);
    inOrderTraversal(node->rightChild);
}

void postOrderTraversal(struct Node *node) {
    if (node == NULL) {
        return;
    }
    postOrderTraversal(node->leftChild);
    postOrderTraversal(node->rightChild);
    printf("%d ", node->i);
}

int main() {
    struct Node *rootNode = (struct Node *) malloc(sizeof(struct Node));
    int rootValue;
    printf("Enter the value of root Node:\n");
    scanf("%d", &rootValue);
    rootNode->i = rootValue;
    insertDataInTheBinaryTree(rootNode);
    printf("PreOrder Traversal: ");
    preOrderTraversal(rootNode);
    printf("\nInOrder Traversal: ");
    inOrderTraversal(rootNode);
    printf("\nPostOrder Traversal: ");
    postOrderTraversal(rootNode);
    return 0;
}

/*Output:
    Enter the value of root Node:
    10
    Do you want to insert the value in the leftChild of 10? 0 or 1:
    1
    enter the value of leftChild of 10:
    20
    Do you want to insert the value in the leftChild of 20? 0 or 1:
    0
    Do you want to enter the data in rightChild of 20? 0 or 1:
    1
    Enter the value for right child of 20:
    30
    Do you want to insert the value in the leftChild of 30? 0 or 1:
    0
    Do you want to enter the data in rightChild of 30? 0 or 1:
    0
    Do you want to enter the data in rightChild of 10? 0 or 1:
    1
    Enter the value for right child of 10:
    40
    Do you want to insert the value in the leftChild of 40? 0 or 1:
    1
    enter the value of leftChild of 40:
    200
    Do you want to insert the value in the leftChild of 200? 0 or 1:
    0
    Do you want to enter the data in rightChild of 200? 0 or 1:
    0
    Do you want to enter the data in rightChild of 40? 0 or 1:
    1
    Enter the value for right child of 40:
    400
    Do you want to insert the value in the leftChild of 400? 0 or 1:
    0
    Do you want to enter the data in rightChild of 400? 0 or 1:
    0
    PreOrder Traversal: 10 20 30 40 200 400
    InOrder Traversal: 20 30 10 200 40 400
    PostOrder Traversal: 30 20 200 400 40 10
 */