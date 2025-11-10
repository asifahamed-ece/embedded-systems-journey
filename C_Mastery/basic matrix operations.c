#include <stdio.h>

void added_matrix( int row, int col, int arr1[row][col], int arr2[row][col]){
    printf("\nAdded Matrix :\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
                printf("%d ",(arr1[i][j]+arr2[i][j]));
        }printf("\n");
    }
}
void subtracted_matrix( int row, int col, int arr1[row][col], int arr2[row][col]){
    printf("\nSubtracted Matrix :\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
                printf("%d ",(arr1[i][j]-arr2[i][j]));
        }printf("\n");
    }
}


int main(){
    int row;
    int col;

    printf("Enter Row and Col size: ");
    scanf("%d %d",&row, &col);
    int arr1[row][col];
    int arr2[row][col];

    printf("\nEnter Matrix 1: ");
    for (int i=0; i<row;i++){
            for(int j=0; j<col; j++){
                printf("Enter element at position (%d, %d): ", i + 1, j + 1);
                scanf("%d",&arr1[i][j]);
            }
        }

        printf("\nMatrix 1:\n");
        for (int i=0; i<row;i++){
            for(int j=0; j<col; j++){
                printf("%d ",arr1[i][j]);
            }printf("\n");
        }
    printf("\nEnter Matrix 2: ");
    for (int i=0; i<row;i++){
            for(int j=0; j<col; j++){
                printf("Enter element at position (%d, %d): ", i + 1, j + 1);
                scanf("%d",&arr2[i][j]);
            }
        }

        printf("\nMatrix 2:\n");
        for (int i=0; i<row;i++){
            for(int j=0; j<col; j++){
                printf("%d ",arr2[i][j]);
            }printf("\n");
        }

        added_matrix( row, col, arr1, arr2);
        subtracted_matrix(row, col, arr1, arr2);
return 0;

}
