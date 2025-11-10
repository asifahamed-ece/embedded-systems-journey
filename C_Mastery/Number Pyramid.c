#include <stdio.h>

int main(){
    int n;
    printf("Enter n Value: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
       //Print the Spaces
        for (int j=0; j<n-i-1; j++){
            printf(" ");
        }
        //Print the Ascending Numbers
        for(int j=0; j<i+1; j++){
            printf("%d",j+1);
        }
        for(int j=i; j>=1; j--){
                printf("%d",j);
        }
        printf("\n");
    }
}
