#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int i;
    struct Node *leftChild;
    struct Node *rightChild;
    int heightOfTheTree; /// independent of the Node
};

int heightOfTheTree(struct Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->heightOfTheTree;
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
        node->heightOfTheTree = 0;
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
    node->heightOfTheTree = _maxValue;
    return node;
}

struct Node *insertDataInBST(struct Node *node) {
    node = insertANodeInBST(node, 8);
    node = insertANodeInBST(node, 3);
    node = insertANodeInBST(node, 1);
    node = insertANodeInBST(node, 6);
    node = insertANodeInBST(node, 10);
    node = insertANodeInBST(node, 14);
    node = insertANodeInBST(node, 7);
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

void inOrder(struct Node *node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->leftChild);
    printf("%d ", node->i);
    inOrder(node->rightChild);
}


bool isTreeBalanced(struct Node *node) {
    if (node == NULL) {
        return true;
    }
    return abs(heightOfTheTree(node->leftChild) - heightOfTheTree(node->rightChild)) <= 1 &&
           isTreeBalanced(node->leftChild) &&
           isTreeBalanced(node->rightChild);
}

bool doesThisNodeExist(struct Node *node, int value) {
    if (node == NULL) {
        return false;
    }
    if (node->i == value) {
        return true;
    }

    if (value < node->i) {
        return doesThisNodeExist(node->leftChild, value);
    }

    if (value > node->i) {
        return doesThisNodeExist(node->rightChild, value);
    }
}

struct Node *searchForANode(struct Node *node, int value) {
    if (!doesThisNodeExist(node, value)) {
        printf("\n%d doesn't exist", value);
        return node;
    }
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


struct Node *deleteANode(struct Node *node, int value) {
    if (!doesThisNodeExist(node, value) || node == NULL) {
        printf("\n%d doesn't exists in the data", value);
        return NULL;
    }

    if (value < node->i) {
        node->leftChild = deleteANode(node->leftChild, value);
    } else if (value > node->i) {
        node->rightChild = deleteANode(node->rightChild, value);
    } else {
        // case 1: node with no children
        if (node->leftChild == NULL && node->rightChild == NULL) {
            free(node);
            printf("\ndeleting based on node with no children case");
            return NULL;
        }

        // case 2: node with a single child
        if (node->rightChild == NULL) {
            struct Node *refNode = node->leftChild;
            free(node);
            printf("\ndeleting based on node with a single leftChild case");
            return refNode;
        } else if (node->leftChild == NULL) {
            struct Node *refNode = node->rightChild;
            free(node);
            printf("\ndeleting based on node with a single rightChild case");
            return refNode;
        }

        // case 3: node with two children (logic is based on predecessor value)
        struct Node *delNode = node;
        if (node->rightChild != NULL && node->leftChild != NULL) {
            delNode = delNode->leftChild;
            while (delNode->rightChild != NULL) {
                delNode = delNode->rightChild;
            }
            node->i = delNode->i;
            free(delNode);
            node->leftChild = NULL;
            printf("\ndeleting based on node with two children (logic is based on predecessor value)");
            return node;
        }
    }
    return node;
}

int main() {
    struct Node *rootNode = NULL;
    rootNode = insertDataInBST(rootNode);
    printf("before deleting:\n");
    displayDetails(rootNode);
    inOrder(rootNode);
    deleteANode(rootNode, 3);
    printf("\nafter deleting:\n");
    displayDetails(rootNode);
    inOrder(rootNode);
    printf("\nbalanced tree? :: %d", isTreeBalanced(rootNode));
    printf("\nnode is at %d", searchForANode(rootNode, 42)->i);
    printf("\ndoes this node exist? %d", doesThisNodeExist(rootNode, 42));
    return 0;
}
/**
 Output:-
    before deleting:
    Current parent node is = 8, contains 3 as the left child
    Current parent node is = 8, contains 10 as the right child
    Current parent node is = 3, contains 1 as the left child
    Current parent node is = 3, contains 6 as the right child
    Current parent node is = 1, contains NULL as the left child
    Current parent node is = 1, contains NULL as the right child
    Current parent node is = 6, contains NULL as the left child
    Current parent node is = 6, contains 7 as the right child
    Current parent node is = 7, contains NULL as the left child
    Current parent node is = 7, contains NULL as the right child
    Current parent node is = 10, contains NULL as the left child
    Current parent node is = 10, contains 14 as the right child
    Current parent node is = 14, contains NULL as the left child
    Current parent node is = 14, contains NULL as the right child
    1 3 6 7 8 10 14
    deleting based on node with two children (logic is based on predecessor value)
    after deleting:
    Current parent node is = 8, contains 1 as the left child
    Current parent node is = 8, contains 10 as the right child
    Current parent node is = 1, contains NULL as the left child
    Current parent node is = 1, contains 6 as the right child
    Current parent node is = 6, contains NULL as the left child
    Current parent node is = 6, contains 7 as the right child
    Current parent node is = 7, contains NULL as the left child
    Current parent node is = 7, contains NULL as the right child
    Current parent node is = 10, contains NULL as the left child
    Current parent node is = 10, contains 14 as the right child
    Current parent node is = 14, contains NULL as the left child
    Current parent node is = 14, contains NULL as the right child
    1 6 7 8 10 14
    balanced tree? :: 1
    42 doesn't exist
    node is at 8
    does this node exist? 0
 **/