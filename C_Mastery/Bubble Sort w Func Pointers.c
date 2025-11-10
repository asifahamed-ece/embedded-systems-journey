#include <stdio.h>
#include <stdlib.h>

// Comparison functions
int ascending(int a, int b) {
    return a > b;  // Return 1 if a should come after b
}

int descending(int a, int b) {
    return a < b;  // Return 1 if a should come before b
}

// Generic bubble sort using function pointer
void bubbleSort(int arr[], int n, int (*compare)(int, int)) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(compare(arr[j], arr[j+1])) {  // Use custom comparison
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n; printf("Enter no. of Elem: ");
    scanf("%d", &n);

    int *numbers = (int*)malloc(n * sizeof(numbers));
    printf("Enter the Elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d", (numbers+i));
    }

    if(numbers != NULL){
        printf("Original: ");
        printArray(numbers, n);

        // Sort ascending
        bubbleSort(numbers, n, ascending);
        printf("Ascending: ");
        printArray(numbers, n);

        // Sort descending
        bubbleSort(numbers, n, descending);
        printf("Descending: ");
        printArray(numbers, n);
    }
    else{
        printf("Memory Allocation Failed! \n");
    }

    free(numbers);
    numbers = NULL;
    return 0;
}
