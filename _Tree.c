#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* children[10];
    int childCount;
};

// Create a new node
struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->childCount = 0;
    for(int i = 0; i < 10; i++)
        n->children[i] = NULL;
    return n;
}

// Add a child
void addChild(struct Node* parent, struct Node* child) {
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

// Print parents of each node
void printParents(struct Node* node, struct Node* parent) {
    if (parent == NULL)
        printf("%d -> NULL\n", node->data);
    else
        printf("%d -> %d\n", node->data, parent->data);

    for (int i = 0; i < node->childCount; i++)
        printParents(node->children[i], node);
}

// Print children of each node
void printChildren(struct Node* node) {
    printf("%d -> ", node->data);

    for (int i = 0; i < node->childCount; i++)
        printf("%d ", node->children[i]->data);

    printf("\n");

    for (int i = 0; i < node->childCount; i++)
        printChildren(node->children[i]);
}

// Print leaf nodes
void printLeafNodes(struct Node* node) {
    if (node->childCount == 0) {
        printf("%d ", node->data);
        return;
    }

    for (int i = 0; i < node->childCount; i++)
        printLeafNodes(node->children[i]);
}

// Print degrees (correct definition: only children)
void printDegrees(struct Node* node) {
    printf("%d -> %d\n", node->data, node->childCount);

    for (int i = 0; i < node->childCount; i++)
        printDegrees(node->children[i]);
}

int main() {
    struct Node* root = createNode(1);
    struct Node* n2 = createNode(2);
    struct Node* n3 = createNode(3);
    struct Node* n4 = createNode(4);
    struct Node* n5 = createNode(5);

    addChild(root, n2);
    addChild(root, n3);
    addChild(n2, n4);
    addChild(n2, n5);

    printf("Parents:\n");
    printParents(root, NULL);

    printf("Children:\n");
    printChildren(root);

    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");

    printf("Degrees:\n");
    printDegrees(root);

    return 0;
}
