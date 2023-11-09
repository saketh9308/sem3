#include <stdio.h>

#define MAX_ARRAY_SIZE 6
int arr[MAX_ARRAY_SIZE];
int front = -1;
int rear = -1;

void insertInNode() {
    int i = 0;
    while (i < MAX_ARRAY_SIZE) {
        if (front > MAX_ARRAY_SIZE) {
            printf("stackover flow");
            break;
        } else if (front > 0) {
            arr[front] = front;
            front--;
        } else if (front && rear == -1) {
            front++;
            rear++;
            arr[front]=i;
        }else{
            arr[rear]=i;
            rear++;
        }
        i++;
    }
}