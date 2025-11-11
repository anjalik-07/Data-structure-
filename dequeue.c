#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertLeft(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert from left.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

void insertRight(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert from right.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

void deleteLeft() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from left.\n");
        return;
    }
    printf("Deleted %d from left.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRight() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from right.\n");
        return;
    }
    printf("Deleted %d from right.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Deque Menu ---\n");
        printf("1. Insert from Left\n");
        printf("2. Insert from Right\n");
        printf("3. Delete from Left\n");
        printf("4. Delete from Right\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert from left: ");
                scanf("%d", &value);
                insertLeft(value);
                break;
            case 2:
                printf("Enter value to insert from right: ");
                scanf("%d", &value);
                insertRight(value);
                break;
            case 3:
                deleteLeft();
                break;
            case 4:
                deleteRight();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
