#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reversed_array(int *arr, int n){

    for(int i=0; i< n/2; i++){
        swap((arr+i), (arr+(n-i-1)));
    }
}

int main(){
    int n;
    printf("Enter no. of Elem :");
    scanf("%d", &n);

    printf("Enter the Array Elem: \n");
    int *array = (int *)calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", array+i);
    }

    printf("Original Array: \n");
    for(int j=0; j<n; j++){
        printf("%d  ",*(array+j));
    }

    reversed_array(array, n);
    printf("\nReversed Array: \n");
    for(int j=0; j<n; j++){
        printf("%d  ",*(array+j));
    }

    free(array);
    array = NULL;
    return 0;
}
