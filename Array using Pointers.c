// Printing a Matrix using pointers
#include <stdlib.h>
#include <stdio.h>

int main(){
    int n;
    printf("Enter No. Of Elem. : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the Array Elem :\n");
    for(int i=0; i<n; i++){
        scanf("%d", (arr+i));
        }
    printf("memory usage : %p", *arr);

    printf("\nThe Number Array is :\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(arr+i));
    }
    free(arr);printf("\nMemory After free() : %p", *arr);

    arr = NULL;printf("\nNulled Array : %p", arr);
}
