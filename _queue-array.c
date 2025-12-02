#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow.\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Enqueued %d.\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Dequeued %d.\n", queue[front++]);

    if (front > rear) { 
        front = rear = -1; // reset queue
    }
}

// Peek
void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Array ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
