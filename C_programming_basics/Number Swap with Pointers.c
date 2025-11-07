// Swap 2 numbers using Pointers

# include <stdio.h>

void swap(int *x, int *y){

    if(x == NULL || y == NULL){
        printf(" Error: Null Pointer! ");
        return;
    }

    if(x == y){
        printf("Both Values are Same, No Swaps Needed! ");
        return;
    }

    int temp = *x;
    *x = *y;
    *y = temp;
    printf("Values Swapped !\n");
}

int main(){

    int a; int b;
    printf("Enter 2 Values: ");
    scanf("%d %d",&a, &b);
    printf("Before Swapping: a=%d, b=%d\n",a,b);
    swap(&a, &b);
    printf("After Swapping : a=%d, b=%d\n",a,b);

    return 0;
}
