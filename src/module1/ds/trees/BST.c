#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
    int heightOfTheNode;
};

int heightOfTheTree(struct Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->heightOfTheNode;
    }
}

int maxValue(int i, int j) {
    if (i > j) return i; else return j;
}

struct Node *insertANodeInBST(struct Node *node, int currentValue) {
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->i = currentValue;
        node->leftChild = NULL;
        node->rightChild = NULL;
        node->heightOfTheNode = 0;
        return node;
    }

    if (currentValue == node->i) {
        return node;
    }
    if (currentValue < node->i) {
        node->leftChild = insertANodeInBST(node->leftChild, currentValue);
    }
    if (currentValue > node->i) {
        node->rightChild = insertANodeInBST(node->rightChild, currentValue);
    }
    int _maxValue = maxValue(heightOfTheTree(node->leftChild), heightOfTheTree(node->rightChild)) + 1;
    node->heightOfTheNode = _maxValue;
    return node;
}

struct Node *insertDataInBST(struct Node *node) {
    node = insertANodeInBST(node, 5);
    node = insertANodeInBST(node, 2);
    node = insertANodeInBST(node, 7);
    node = insertANodeInBST(node, 1);
    node = insertANodeInBST(node, 4);
    node = insertANodeInBST(node, 42);
    node = insertANodeInBST(node, 44);
    return node;
}

void displayDetails(struct Node *node) {
    if (node == NULL) return;
    if (node->leftChild != NULL) {
        printf("Current parent node is = %d, contains %d as the left child\n", node->i,
               node->leftChild->i);
    } else {
        printf("Current parent node is = %d, contains NULL as the left child\n", node->i);
    }
    if (node->rightChild != NULL) {
        printf("Current parent node is = %d, contains %d as the right child\n", node->i,
               node->rightChild->i);
    } else {
        printf("Current parent node is = %d, contains NULL as the right child\n", node->i);
    }
    displayDetails(node->leftChild);
    displayDetails(node->rightChild);
}

struct Node *inOrder(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    inOrder(node->leftChild);
    printf("current node value in inorder = %d\n", node->i);
    inOrder(node->rightChild);
    return node;
}

bool isTreeBalanced(struct Node *node) {
    if (node == NULL) {
        return true;
    }
    return abs(heightOfTheTree(node->leftChild) - heightOfTheTree(node->rightChild)) <= 1 &&
           isTreeBalanced(node->leftChild) &&
           isTreeBalanced(node->rightChild);
}

struct Node *searchForANode(struct Node *node, int value) {
    if (node == NULL || node->i == value) {
        return node;
    }

    if (value < node->i) {
        return searchForANode(node->leftChild, value);
    }
    if (value > node->i) {
        return searchForANode(node->rightChild, value);
    }
}

int main() {
    struct Node *rootNode = NULL;
    rootNode = insertDataInBST(rootNode);
    displayDetails(rootNode);
    inOrder(rootNode);
    printf("\nbalanced tree? :: %d", isTreeBalanced(rootNode));
    printf("\nnode is at %d", searchForANode(rootNode, 42)->i);
    return 0;
}
/*
 Output:-
    Current parent node is = 5, contains 2 as the left child
    Current parent node is = 5, contains 7 as the right child
    Current parent node is = 2, contains 1 as the left child
    Current parent node is = 2, contains 4 as the right child
    Current parent node is = 1, contains NULL as the left child
    Current parent node is = 1, contains NULL as the right child
    Current parent node is = 4, contains NULL as the left child
    Current parent node is = 4, contains NULL as the right child
    Current parent node is = 7, contains NULL as the left child
    Current parent node is = 7, contains 42 as the right child
    Current parent node is = 42, contains NULL as the left child
    Current parent node is = 42, contains 44 as the right child
    Current parent node is = 44, contains NULL as the left child
    Current parent node is = 44, contains NULL as the right child
    current node value in inorder = 1
    current node value in inorder = 2
    current node value in inorder = 4
    current node value in inorder = 5
    current node value in inorder = 7
    current node value in inorder = 42
    current node value in inorder = 44

    balanced tree? :: 1
    node is at 42
 * */