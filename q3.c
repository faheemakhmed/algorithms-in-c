//program to delete an element at the begining,end,anywhere in an 1-D array
#include <stdio.h>

int main() {
    int arr[100], n, i, pos, choice;

    // Input original array size and elements
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Menu for deletion
    printf("\n\nWhere do you want to delete an element from?\n");
    printf("1. From beginning\n2. From end\n3. From specific position\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Delete from beginning
            for(i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        case 2:
            // Delete from end
            n--;
            break;

        case 3:
            // Delete from specific position
            printf("Enter position to delete (1 to %d): ", n);
            scanf("%d", &pos);
            if(pos < 1 || pos > n) {
                printf("Invalid position!\n");
                return 1;
            }
            for(i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display updated array
    printf("\nArray after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
