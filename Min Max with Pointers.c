#include <stdio.h>
#include <stdlib.h>

int min(int *arr, int n){
    int min =arr[0];
    for(int i=1; i<n; i++){
        if(min > arr[i])
        min = arr[i];
    }
    return min;
}

int max(int *arr, int n){
    int max = *arr;
    for(int j=0; j<n; j++){
        if(max < *(arr+j)){
            max = *(arr+j);
            }
    }return max;
}


int main(){

    int n;printf("Enter no. of Elem: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));

    printf("Enter Array Elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    int minimum = min(arr,n);
    printf("The Minimum Value : %d\n", minimum);
    int maximum = max(arr,n);
    printf("The Maximum Value : %d", maximum);

    free(arr);
    arr = NULL;
    return 0;
}
