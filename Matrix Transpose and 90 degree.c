// Find the Transpose of a Matrix

#include <stdio.h>

void Matrix_Transpose(int rows,int cols,int mat[rows][cols]){

    printf("Transposed Matrix: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", mat[j][i]);
        }printf("\n");
    }
}

void Matrix_Rotate(int rows,int cols,int mat[rows][cols]){

    printf("Clock-wise Rotated Matrix: \n");
    for(int j=0; j<=cols-1; j++){
        for(int i=rows-1; i>=0; i--){
            printf("%d ", mat[i][j]);
        }printf("\n");
    }

}


int main(){

    int rows, cols;
    printf("Enter Rows and Column Value: ");
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols];

    printf("Enter the Matrix: ");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Original Matrix: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", mat[i][j]);
        }printf("\n");
    }
    // Transpose the Matrix
    Matrix_Transpose(rows, cols, mat);


    //Rotate 90 degree
    Matrix_Rotate(rows, cols, mat);
}

