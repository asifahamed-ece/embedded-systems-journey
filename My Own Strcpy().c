#include <stdio.h>
#include "

char* my_strcpy(const char* src, char *dest){
    char *dest_start = dest;

    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return dest_start;
}


int main(){
    char source[20] = {"I am Asif"};
    char destination[20];

    char* result = my_strcpy(source, destination);

    printf("Source : %s\nDestination : %s \n", source, result);

    return 0;
}
