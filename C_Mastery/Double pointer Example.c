#include <stdio.h>
#include <stdlib.h>

// Function that changes WHERE a pointer points
void allocateMemory(int **ptr, int size) {
    *ptr = malloc(size * sizeof(int));  // Changes the pointer itself
    if (*ptr != NULL) {
        for(int i = 0; i < size; i++) {
            (*ptr)[i] = i + 1;  // Fill with values
        }
    }
}

int main() {
    int *array = NULL;  // Initially points to nothing
    
    printf("Before: array = %p\n", (void*)array);
    
    allocateMemory(&array, 5);  // Pass address of pointer
    
    printf("After: array = %p\n", (void*)array);
    
    if (array != NULL) {
        for(int i = 0; i < 5; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        free(array);
    }
    
    return 0;
}
