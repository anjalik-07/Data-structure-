#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enQueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue elements:\n");
        i = front;
        while (1) {
            printf("%d ", items[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\nFront -> %d\n", front);
        printf("Rear -> %d\n", rear);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
