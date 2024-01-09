// Exp:1,2,3,4,5,6,9(i)

// 4(1), 4 (2), 5

// 4(1) infix to postfix using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack {
    int topOfTheStack;
    int capacity;
    char *arr;
};

bool isOperator(char value) {
    if (value == '+' || value == '-' || value == '*' || value == '/') return true; else return false;
}

bool isOpeningParenthesis(char value) {
    return value == '(';
}

bool isClosingParenthesis(char value) {
    return value == ')';
}

void pushIntoTheStack(struct Stack *stack, char newValue) {
    stack->arr[++stack->topOfTheStack] = newValue;
}

char popFromTheStack(struct Stack *stack) {
    char tempValue = stack->arr[stack->topOfTheStack];
    stack->topOfTheStack--;
    return tempValue;
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

bool isStackEmpty(struct Stack *stack) {
    return stack->topOfTheStack == -1;
}

char *infixToPostfix(char *infixExp) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    char *postFixExp = (char *) malloc((strlen(infixExp) + 1) * sizeof(char));
    int infixIterator = 0;
    int postfixIterator = 0;
    stack->capacity = 25;
    stack->topOfTheStack = -1;
    stack->arr = (char *) malloc(stack->capacity * sizeof(char));
    while (infixExp[infixIterator] != '\0') {
        if (!isOperator(infixExp[infixIterator]) && !isOpeningParenthesis(infixExp[infixIterator]) &&
            !isClosingParenthesis(infixExp[infixIterator])) {
            postFixExp[postfixIterator] = infixExp[infixIterator];
            infixIterator++;
            postfixIterator++;
        } else if (isOpeningParenthesis(infixExp[infixIterator])) {
            pushIntoTheStack(stack, infixExp[infixIterator]);
            infixIterator++;
        } else if (isClosingParenthesis(infixExp[infixIterator])) {
            while ((!isStackEmpty(stack)) && !isOpeningParenthesis(stack->arr[stack->topOfTheStack])) {
                postFixExp[postfixIterator] = popFromTheStack(stack);
                postfixIterator++;
            }
            popFromTheStack(stack);
            infixIterator++;
        } else {
            if (precedence(infixExp[infixIterator]) > precedence(stack->arr[stack->topOfTheStack])) {
                pushIntoTheStack(stack, infixExp[infixIterator]);
                infixIterator++;
            } else {
                postFixExp[postfixIterator] = popFromTheStack(stack);
                postfixIterator++;
            }
        }
    }
    while (!isStackEmpty(stack)) {
        postFixExp[postfixIterator] = popFromTheStack(stack);
        postfixIterator++;
    }
    postFixExp[postfixIterator] = '\0';
    return postFixExp;
}

void main() {
    printf("%s", infixToPostfix("((A+B)-C*(D/E))+F"));
    // AB+CDE/*-F+
}