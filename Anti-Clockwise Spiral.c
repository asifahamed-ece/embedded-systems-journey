#include <stdio.h>

void SpiralTraversal(int rows, int cols, int matrix[rows][cols]){
    int top=0;int bottom=rows-1;
    int left=0;int right=cols-1;

    printf("\nAnt-Clockwise Spiral Order: \n");

while(top <= bottom && left <= right) {

        // 1. Top row: RIGHT to LEFT
        for(int i = right; i >= left; i--){
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Left column: TOP to BOTTOM
        for(int i = top; i <= bottom; i++){
            printf("%d ", matrix[i][left]);
        }
        left++;

        // 3. Bottom row: LEFT to RIGHT (if row exists)
        if(top <= bottom){
            for(int i = left; i <= right; i++){
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Right column: BOTTOM to TOP (if column exists)
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                printf("%d ", matrix[i][right]);
            }
            right--;
        }
    }
    printf("\n");

}


int main(){

    int rows, cols;
    printf("Enter Row and Col Value: \n");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];

    printf("Enter Matrix Elements: \n");
    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix: \n");
    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }printf("\n");
    }
    SpiralTraversal(rows, cols, matrix);

}
