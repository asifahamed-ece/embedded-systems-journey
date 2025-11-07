#include <stdio.h>
#include <stdlib.h>

int find_max(int n,int arr[]){
    int max = arr[0];
    for (int k=1;k<n;k++){
        if(arr[k]>arr[k+1]){
            max = arr[k];
        }
    }
    return max;
}

int find_min(int n, int arr){
    int min = arr[n-1];
    for (k=sizeof(arr); k>n;--k){
        if(arr[k]<arr[k-1]){
            min = arr[k];
        }
    }return min;
}

int main(){
    int n;
    int arr[10];
    printf("Enter the Value of n: \t");
    scanf("%d", &n);

    printf("Enter %d Values for Array: \t",n);
    for (int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    int min_elem = find_min(n,arr);
    int max_elem = find_max(n,arr);
    printf("The Maximum Element is %d\n",max_elem);
    printf("The Minimum Element is %d\n",min_elem);
    return 0;
}

