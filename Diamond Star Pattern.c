#include <stdio.h>


int main(){

    int n;printf("Enter Row Value : ");
    scanf("%d", &n);

    //Outer(Row) Loop
    for(int i=0; i<n; i++){

        //Print Leading spaces
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        //Print Stars
        for(int j=0; j<2*i+1;j++){
            printf("*");
        }printf("\n");
    }
    //Lower Part
        for(int k=n-2; k>=0;k--){
            //spaces
            for(int j=0; j< n-k-1; j++){
                printf(" ");
            }
            for( int j=0; j< 2*k+1; j++){
                printf("*");
            }printf("\n");
        }


return 0;
}
