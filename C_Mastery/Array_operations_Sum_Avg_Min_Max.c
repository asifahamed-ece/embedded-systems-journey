// Program to Find the Sum, Max, Min, Avg of an User defined Array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int n, int *arr){
    int min=arr[0];
    for (int k=1;k<n;k++){
        if(arr[k]<min){
            min = arr[k];
        }
    }return min;
}

int max(int n, int *arr){
    int max=arr[0];
    for (int k=1;k<n;k++){
        if(arr[k]>max){
            max = arr[k];
        }
    }return max;
}

void sorted_arr(int n, int *arr){
    for (int l=0; l<n-1;l++){
        for (int j=1;j<n;j++){
        if(arr[j] < arr[j-1]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            }
        }
    }
    printf("\nSorted Array: [");
    for (int k=0;k<n;k++){
    printf("%d  ",arr[k]);
    }printf("]");
}
int sec_large(int n, int arr2[]){
    int sec_lar;
    for (int a=n-1; a>=0; --a){
            if(arr2[a-1]<arr2[a]){
                sec_lar = arr2[a-1];
                break;
            }
    }return sec_lar;
}

int count_above_avg(int n, int avg, int *arr){
    int count=0;
    for (int m=0; m<n; m++){
        if(arr[m]> avg){
            count++;
        }
    }return count;
}

int main(){
    int n;
    printf("Enter Array size: ");
    scanf("%d",&n);
    int arr[n];
    int sum = 0;
    int arr2[n];

    printf("Enter Array Elements: ");
    for (int i=0; i<n;i++){
            scanf("%d", &arr[i]);
            sum += arr[i];
            }

    printf("The Input Array: [");
        //Displaying the Array
    for (int i=0; i<n;i++){
            printf(" %d ",arr[i]);
            }
            printf("]");

    //Displaying the Results ( Sum, Average, Min and Max Values)
    printf("\nSum : %d",sum);int avg = sum/n;
    printf("\nAverage : %d",avg);
    printf("\nMinimum : %d",min(n, arr));
    printf("\nMaximum : %d",max(n, arr));
    sorted_arr(n, arr);
    printf("\nSecond Largest : %d",sec_large(n, arr));
    printf("\nAbove Average : %d",count_above_avg(n, avg, arr));

}
