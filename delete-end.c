//delete from the end of a linked list

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
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Create linked list from user input
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

// Display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }

    // If only one node exists
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }

    // Traverse to second last node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return head;
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    head = deleteFromEnd(head);

    printf("\nAfter Deletion ");
    displayList(head);

    return 0;
}
