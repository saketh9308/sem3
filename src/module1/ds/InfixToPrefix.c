#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack {
    int topOfTheStack;
    int capacity;
    char *arr;
};

int isStackEmpty(struct Stack *stack) {
    return stack->topOfTheStack == -1;
}

int precedence(char value) {
    if (value == '+' || value == '-') {
        return 1;
    } else if (value == '*' || value == '/') {
        return 2;
    } else {
        return 0;
    }
}

bool isOpenParenthesis(char value) {
    return value == '(';
}

bool isCloseParenthesis(char value) {
    return value == ')';
}

bool isOperator(char value) {
    if (value == '+' || value == '-' || value == '*' || value == '/') {
        return true;
    } else {
        return false;
    }
}

void pushIntoTheStack(struct Stack *stack, char newValue) {
    stack->arr[++stack->topOfTheStack] = newValue;
}

char popFromTheStack(struct Stack *stack) {
    char tempValue = stack->arr[stack->topOfTheStack];
    stack->topOfTheStack--;
    return tempValue;
}

char *infixToPrefix(char *infixExp) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->topOfTheStack = -1;
    stack->capacity = 100;
    stack->arr = (char *) malloc(stack->capacity * sizeof(char));

    char *prefixExp = (char *) malloc((strlen(infixExp) + 1) * sizeof(char));

    int infixIterator = strlen(infixExp) - 1;
    int preFixIterator = 0;
// code changes here:
    while (infixIterator >= 0) {
        if (!isOperator(infixExp[infixIterator]) && !isOpenParenthesis(infixExp[infixIterator]) &&
            !isCloseParenthesis(infixExp[infixIterator])) {
            prefixExp[preFixIterator] = infixExp[infixIterator];
            infixIterator--;
            preFixIterator++;
        } else if (isCloseParenthesis(infixExp[infixIterator])) {
            pushIntoTheStack(stack, infixExp[infixIterator]);
            infixIterator--;
            // code changes here:
        } else if (isOpenParenthesis(infixExp[infixIterator])) {
            // code changes here:
            while (!isStackEmpty(stack) && !isCloseParenthesis(stack->arr[stack->topOfTheStack])) {
                prefixExp[preFixIterator] = popFromTheStack(stack);
                preFixIterator++;
            }
            popFromTheStack(stack);
            infixIterator--;
        } else {
            // code changes here:
            if (precedence(infixExp[infixIterator]) >= precedence(stack->arr[stack->topOfTheStack])) {
                pushIntoTheStack(stack, infixExp[infixIterator]);
                infixIterator--;
            } else {
                prefixExp[preFixIterator] = popFromTheStack(stack);
                preFixIterator++;
            }
        }
    }
    while (!isStackEmpty(stack)) {
        prefixExp[preFixIterator] = popFromTheStack(stack);
        preFixIterator++;
    }
    prefixExp[preFixIterator] = '\0';

    int start = 0;
    int end = preFixIterator - 1;
    while (start < end) {
        char temp = prefixExp[start];
        prefixExp[start] = prefixExp[end];
        prefixExp[end] = temp;
        start++;
        end--;
    }
    return prefixExp;
}

void main() {
    printf("%s", infixToPrefix("(A-B/C)*(A/K-L)"));
    //      *-A/BC-/AKL
}