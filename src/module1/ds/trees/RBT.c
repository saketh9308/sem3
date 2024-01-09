#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
    struct Node *parentNode;
    bool isARedNode;
    int heightOfTheTree;
};

int maxOf(int i, int j) {
    if (i > j)return i; else return j;
}

int heightOfTheTree(struct Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->heightOfTheTree;
    }
}

struct Node *reColorTheUncleNode(struct Node *node) {
    if (node == NULL || node->parentNode == NULL || node->parentNode->parentNode == NULL) {
        return node;
    }
    if (node->parentNode->parentNode == node->parentNode->parentNode->rightChild) {
        node->parentNode->parentNode->rightChild->isARedNode = false;
    } else {
        node->parentNode->parentNode->leftChild->isARedNode = false;
    }
    node->parentNode->parentNode->isARedNode = true;
    node->parentNode->isARedNode = false;
    return node;
}

struct Node *rotateTheRBT(struct Node *node) {
// case 1: if newly inserted node's uncle is in red

}

struct Node *insertInRBT(struct Node *newNode, int newValue, struct Node *parentNode) {
    if (newNode == NULL) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->i = newValue;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->heightOfTheTree = 0;
        newNode->parentNode = parentNode;
        if (newNode->parentNode != NULL) newNode->isARedNode = false; else newNode->isARedNode = true;
        return newNode;
    }

    if (newValue == newNode->i) {
        return newNode;
    }

    if (newValue < newNode->i) {
        newNode->leftChild = insertInRBT(newNode->leftChild, newValue, newNode);
        if (parentNode != NULL && parentNode->leftChild != NULL) {
            parentNode->leftChild->parentNode = parentNode;
        }
    }

    if (newValue > newNode->i) {
        newNode->rightChild = insertInRBT(newNode->rightChild, newValue, newNode);
        if (parentNode != NULL && parentNode->rightChild != NULL) {
            parentNode->rightChild->parentNode = parentNode;
        }
    }
    newNode->heightOfTheTree = maxOf(heightOfTheTree(newNode->leftChild), heightOfTheTree(newNode->rightChild)) + 1;
    return reColorTheUncleNode(newNode);
}

struct Node *insertionsInRBT(struct Node *parentNode, struct Node *newNode) {
    newNode = insertInRBT(newNode, 3, parentNode);
    newNode = insertInRBT(newNode, 1, parentNode);
    newNode = insertInRBT(newNode, 6, parentNode);
    newNode = insertInRBT(newNode, 8, parentNode);
    return newNode;
}

void displayData(struct Node *node) { // preorder traversal
    if (node == NULL) {
        printf("node is null");
        return;
    }
    printf("Current value is %d and color is %d\n", node->i, node->isARedNode);
    if (node->leftChild != NULL) {
        printf("left child of %d is %d and color is %d\n", node->i, node->leftChild->i, node->isARedNode);
    } else {
        printf("left child of %d is NULL and color is %d\n", node->i, node->isARedNode);
    }
    if (node->rightChild != NULL) {
        printf("right child of %d is %d and color is %d\n", node->i, node->rightChild->i, node->isARedNode);
    } else {
        printf("right child of %d is NULL and color is %d\n", node->i, node->isARedNode);
    }
    displayData(node->leftChild);
    displayData(node->rightChild);
}

int main() {
    struct Node *rootNode = NULL;
    rootNode = insertionsInRBT(rootNode, rootNode);
    displayData(rootNode);
    printf("\nheight of the tree = %d", heightOfTheTree(rootNode));
    return 0;
}
