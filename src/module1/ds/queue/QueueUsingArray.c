#include <stdio.h>

#define MAX_SIZE_OF_ARRAY 5

int front = -1;
int rear = -1;
int arr[MAX_SIZE_OF_ARRAY];

void insertionInQueue() {
    int i = 0;
    while (i < MAX_SIZE_OF_ARRAY) {
        if (front > MAX_SIZE_OF_ARRAY) {
            printf("Stack overflow");
            break;
        }
        if (rear == -1 && front == -1) {
            front++;
            rear++;
            arr[front] = i;
        } else {
            rear++;
            arr[rear] = i;
        }
        i++;
    }
}

void deleteFromQueue() {
    arr[front] = (int) NULL;
    front++;
}

int main() {
    insertionInQueue();
    for (int i = 0; i < MAX_SIZE_OF_ARRAY; i++) {
        printf("%d\n", arr[i]);
    }
    /*
    0
    1
    2
    3
    4
     * */
    deleteFromQueue();
    deleteFromQueue();
    for (int i = 0; i < MAX_SIZE_OF_ARRAY; i++) {
        printf("%d\n", arr[i]);
    }
    /*
     0
     0
     2
     3
     4
     * */
}