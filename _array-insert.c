//program to insert an element at the begining,end,anywhere in an 1-D array
#include <stdio.h>

int main() {
    int arr[100], n, i, pos, element, choice;

    // Input original array size and elements
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Menu for insertion
    printf("\n\nWhere do you want to insert?\n");
    printf("1. At beginning\n2. At end\n3. At specific position\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Input the element to insert
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    switch(choice) {
        case 1:
            // Insert at beginning
            for(i = n; i > 0; i--) {
                arr[i] = arr[i-1];
            }
            arr[0] = element;
            n++;
            break;

        case 2:
            // Insert at end
            arr[n] = element;
            n++;
            break;

        case 3:
            // Insert at specific position
            printf("Enter position (1 to %d): ", n + 1);
            scanf("%d", &pos);
            if(pos < 1 || pos > n + 1) {
                printf("Invalid position!\n");
                return 1;
            }
            for(i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = element;
            n++;
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display updated array
    printf("\nArray after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
