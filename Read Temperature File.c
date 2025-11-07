#include <stdio.h>
#include <stdlib.h>

void main(){
    FILE *fptr;
    char onechar;
    printf("Reading in 'r' mode. \n\n");

    fptr = fopen("Temperature Logging.txt", "r");

    if(fptr == NULL){
        printf("Error: File Cannot be Opened\n");
        exit(1);
    }

    while((onechar = getc(fptr))!= EOF){
        printf("%c",onechar);
    }
    printf("\nFile Read Completed");
    fclose(fptr);

    printf("\nTemperature Logging.txt is Read and Closed \n");
}
