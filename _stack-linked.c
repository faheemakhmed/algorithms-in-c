#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push element
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d onto stack.\n", value);
}

// Pop element
void pop() {
    if (top == NULL) {
        printf("Stack Underflow.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped %d from stack.\n", temp->data);

    top = top->next;
    free(temp);
}

// Peek (Top element)
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// Display stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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
