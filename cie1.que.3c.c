#include <stdio.h>

int Queue[100];

void initialize() {
    Queue[0] = 2;
    Queue[1] = 1;
}

void enqueue(int x) {
    if (Queue[1] == 99) {
        printf("Queue Overflow!\n");
        return;
    }
    Queue[1]++;
    Queue[Queue[1]] = x;
    printf("Inserted %d\n", x);
}

int dequeue() {
    if (Queue[0] > Queue[1]) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = Queue[Queue[0]];
    Queue[0]++; // move front
    printf("Removed %d\n", value);
    return value;
}

void display() {
    if (Queue[0] > Queue[1]) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = Queue[0]; i <= Queue[1]; i++)
        printf("%d ", Queue[i]);
    printf("\n");
}

int main() {
    initialize();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}
