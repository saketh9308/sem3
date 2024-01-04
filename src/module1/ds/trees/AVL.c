#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
    int heightOfTheTree; //independent of the node
};

int maxValue(int i, int j) {
    if (i > j) return i; else return j;
}

int heightOfTheTree(struct Node *node) {
    if (node == NULL) return 0; else return node->heightOfTheTree;
}

struct Node *rightRotateTheNode(struct Node *parentNode) {
    struct Node *newParentNode = parentNode->leftChild;
    struct Node *rightSubTree = newParentNode->rightChild;
    newParentNode->rightChild = parentNode;
    parentNode->leftChild = rightSubTree;

    parentNode->heightOfTheTree =
            maxValue(heightOfTheTree(parentNode->leftChild), heightOfTheTree(parentNode->leftChild)) + 1;
    newParentNode->heightOfTheTree =
            maxValue(heightOfTheTree(newParentNode->leftChild), heightOfTheTree(newParentNode->leftChild)) + 1;

    return newParentNode;
}

struct Node *leftRotateTheNode(struct Node *childNode) {
    struct Node *newChildNode = childNode->rightChild;
    struct Node *leftSubtree = childNode->leftChild;

    newChildNode->leftChild = childNode;
    childNode->rightChild = leftSubtree;
    childNode->heightOfTheTree =
            maxValue(heightOfTheTree(childNode->leftChild), heightOfTheTree(childNode->rightChild)) + 1;
    newChildNode->heightOfTheTree =
            maxValue(heightOfTheTree(newChildNode->leftChild), heightOfTheTree(newChildNode->rightChild)) + 1;

    return newChildNode;
}

struct Node *rotateTheTree(struct Node *node) {
    // left unbalanced
    if (heightOfTheTree(node->leftChild) - heightOfTheTree(node->rightChild) > 1) {
        if (heightOfTheTree(node->leftChild->leftChild) - heightOfTheTree(node->leftChild->rightChild) > 0) {
            // left-left case
            return rightRotateTheNode(node);
        } else {
            // left-right case
            node->leftChild = leftRotateTheNode(node->leftChild);
            return rightRotateTheNode(node);
        }
    }

    // right unbalanced
    if (heightOfTheTree(node->rightChild) - heightOfTheTree(node->leftChild) > 1) {
        if (heightOfTheTree(node->rightChild->leftChild) - heightOfTheTree(node->rightChild->rightChild) < 0) {
            return leftRotateTheNode(node);
        } else {
            node->rightChild = rightRotateTheNode(node->rightChild);
            return leftRotateTheNode(node);
        }
    }
    return node;
}

struct Node *insertANodeInAVL(struct Node *node, int newValue) {
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->i = newValue;
        node->leftChild = NULL;
        node->rightChild = NULL;
        node->heightOfTheTree = 0;
        return node;
    }

    if (newValue < node->i) {
        node->leftChild = insertANodeInAVL(node->leftChild, newValue);
    }

    if (newValue > node->i) {
        node->rightChild = insertANodeInAVL(node->rightChild, newValue);
    }
    node->heightOfTheTree = maxValue(heightOfTheTree(node->leftChild), heightOfTheTree(node->rightChild)) + 1;
    return rotateTheTree(node);
}

void displayData(struct Node *node) { // preorder traversal
    if (node == NULL) {
        printf("node is null");
        return;
    }
    printf("Current value is %d\n", node->i);
    if (node->leftChild != NULL) {
        printf("left child of %d is %d\n", node->i, node->leftChild->i);
    } else {
        printf("left child of %d is NULL\n", node->i);
    }
    if (node->rightChild != NULL) {
        printf("right child of %d is %d\n", node->i, node->rightChild->i);
    } else {
        printf("right child of %d is NULL\n", node->i);
    }
    displayData(node->leftChild);
    displayData(node->rightChild);
}

struct Node *insertionsInAVL(struct Node *node) {
    for (int i = 0; i < 1001; ++i) {
        node = insertANodeInAVL(node, i);
    }
    return node;
}

int main() {
    struct Node *rootNode = NULL;
    rootNode = insertionsInAVL(rootNode);
    displayData(rootNode);
    printf("\nheight of the tree = %d", heightOfTheTree(rootNode));
    return 0;
}