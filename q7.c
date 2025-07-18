// Write a program that uses functions and without function to perform the following operations on singly
//linked List (i) Creation (ii) Displays the element.

//using functions
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create the linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int i, value;

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory not allocated.\n");
            return;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to display the list
void displayList() {
    struct Node* temp = head;
    if(temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    return 0;
}


//without using functions
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node *head = NULL, *temp, *newNode;
    int n, value, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Creation of list
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display the list
    printf("Linked List elements: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
