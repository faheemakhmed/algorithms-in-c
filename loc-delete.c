// Delete from a particular position in linked list (Improved Version)
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { // check malloc success
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Create linked list from user input
struct Node* createList(int n) {
    if (n <= 0) {
        printf("List size must be greater than 0!\n");
        return NULL;
    }

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

// Display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    if (!head) {
        printf("EMPTY\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Get length of linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Delete node from a given position (1-based index)
struct Node* deleteFromPosition(struct Node* head, int position) {
    int length = getLength(head);
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    if (position < 1 || position > length) {
        printf("Invalid position! Valid range: 1 to %d\n", length);
        return head;
    }

    // Case 1: Delete first node
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
        return head;
    }

    // Traverse to node just before target position
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    // Delete target node
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted: %d\n", nodeToDelete->data);
    free(nodeToDelete);

    return head;
}

// Free entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter position to delete (1-based index): ");
    scanf("%d", &pos);

    head = deleteFromPosition(head, pos);

    printf("\nAfter Deletion ");
    displayList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
