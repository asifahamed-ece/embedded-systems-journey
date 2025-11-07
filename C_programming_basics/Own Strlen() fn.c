#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *string){
    const char *start = string;

    while(*string != '\0'){
        string++;
    }
    return string - start;
}

int main(){

    int length = 100;
    char *string = (char*)malloc(length * sizeof(char));
    if(string == NULL){ printf("Memory Allocation Failed! \n"); return 1;}

    printf("Enter Your String : ");
    if(fgets(string, length ,stdin) != NULL){
        //Remove NewLine Character
        string[strcspn(string,"\n")] = '\0';
        printf("String : %s \n", string);
        printf("Length : %d", my_strlen(string));
    }



    free(string);
    string = NULL;
}
