# include <stdio.h>
# include <stdlib.h>

void reverse(int *arr, int n){
    int *start = arr;
    int *end = arr+n-1;

    while(start < end){
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(){

    int n;
    printf("Enter no. of Elements: ");
    scanf("%d", &n);

    int *arr = (int*)calloc(n, sizeof(int));
    printf("Enter %d Elements: \n",n);
    for(int i=0; i<n; i++){
        scanf("%d", (arr+i));
        }

    printf("\nOriginal Array :\n");
    for(int k=0; k<n; k++){
        printf("%d  ",*(arr+k));
    }

    reverse(arr, n);
    printf("\nReversed Array :\n");
    for(int j=0; j<n; j++){
        printf("%d  ", *(arr+j));
    }
}
