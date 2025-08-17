//insert at end
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

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

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter value to insert at end: ");
    scanf("%d", &value);

    head = insertAtEnd(head, value);

    printf("\nAfter Insertion at End ");
    displayList(head);

    return 0;
}
