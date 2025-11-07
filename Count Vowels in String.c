#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    printf("Enter the String to Extract Vowels: ");
    scanf("%s",str);
    int count=0;

    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='a'|| str[i]=='e' || str[i]=='i' || str[i]=='o' ||str[i]=='u'){
            count++;
        }
        i++;
    }

    printf("Number of Vowels is : %d", count);
    return 0;
}
