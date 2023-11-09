#include <stdio.h>

#define MAX_SIZE 6

int front = -1;
int arr[MAX_SIZE];

void pushIntoStack() {
    int i = 0;
    while (i < MAX_SIZE) {
        if (front > MAX_SIZE) {
            printf("Stack is overflowed");
            break;
        } else {
            front++;
            arr[front] = i;
        }
        i++;
    }
}

void popFromStack() {
    if (front == -1) {
        printf("Stack is underflow");
    } else {
        arr[front] = (int) NULL;
        front--;
    }
}

int main() {
    pushIntoStack();
    for (int i = 0; i<MAX_SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    popFromStack();
    popFromStack();
    printf("%d\n", arr[front]);
    for (int i = 0; i<MAX_SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    /*
    0
    1
    2
    3
    0
    0
     * */
}