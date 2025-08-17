//insert at a specific location in linked list

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with user input
struct Node* createList(int n) {
    struct Node* head = NULL, *temp = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Function to display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at specific location (1-based index)
// Example: position=1 means insert at beginning
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);

    // Case 1: insert at beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is beyond list length
    if (temp == NULL) {
        printf("Invalid position! Insertion failed.\n");
        free(newNode);
        return head;
    }

    // Insert in middle or end
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert at (1-based index): ");
    scanf("%d", &pos);

    head = insertAtPosition(head, value, pos);

    printf("\nAfter Insertion ");
    displayList(head);

    return 0;
}
