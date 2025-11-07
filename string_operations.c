/*
#include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;
    
    // Nested loop to check all pairs (i,j) where i < j
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            
            // Calculate bitwise operations
            int and_result = i & j;
            int or_result = i | j;
            int xor_result = i ^ j;
            
            // Update maximums if result < k
            if (and_result < k && and_result > max_and) {
                max_and = and_result;
            }
            if (or_result < k && or_result > max_or) {
                max_or = or_result;
            }  
            if (xor_result < k && xor_result > max_xor) {
                max_xor = xor_result;
            }
        }
    }
    
    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}
int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10];
    printf("Size of static array: %lu bytes\n", sizeof(arr));

    printf("Enter the n value: ");
    int n;
    scanf("%d", &n);

    int *dynArr = (int*)malloc(n * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Size of dynamic array: %lu bytes\n", n * sizeof(int));

    free(dynArr); // Always free allocated memory
    return 0;
}