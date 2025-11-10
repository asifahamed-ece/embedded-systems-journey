#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter number of Readings? ");
    scanf("%d", &n);

    float *Readings = (float*)malloc(n * sizeof(float));

    if(Readings == NULL){
        printf("\nMemmory Allocation Failed! \n");
        return 1;
    }
    else{
        printf("Memory Allocation Successful! \n");
    }

    float total = 0;

    for(int i=0; i<n; i++){
        printf("Enter %d value: ",i+1);
        scanf("%f",&Readings[i]);
        total += Readings[i];
    }
    float average = total/n;

    printf("Total Value : %6.2f\n", total);
    printf("Average Readings : %6.2f\n", average);

    FILE *fptr = fopen("Sensor Mem Allocation.txt", "w");
    if(fptr == NULL){
        printf("File Open Failed!\n");
        exit(1);
    }

    fprintf(fptr, "...Sensor Data Logging...\n============================\n\n");
    for(int i=0; i<n; i++){
        fprintf(fptr,"Sensor %d Value: %6.2f\n", i+1, Readings[i]);
    }
    fprintf(fptr, "Log Report:\n");
    fprintf(fptr, "Average Reading: %6.2f\n", average);
    fprintf(fptr, " Data Logging Completed! ");

    fclose(fptr);
    printf("File Closed Successfully! ");

    free(Readings);

    return 0;
}
