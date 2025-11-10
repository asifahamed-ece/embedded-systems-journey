#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *arr;
    printf("Enter the n Values: ");
    scanf("%d\n", &n);
    printf("Enter Array Values: \n");
    
    arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    // Adding the Array Elements and Average calculation.
    int sum=0, avg=0;
    for (int k=0; k<n; k++){
        sum += arr[k];
        printf("Sum iteration %d: %d\t",k+1,sum);
        avg = sum/n;
        printf("Avg iteration %d: %d\n",k+1,avg);
    }
    printf("Average Value: %d\n",avg);
    printf("Sum of Array Elem: %d",sum);
}
