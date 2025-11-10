// Print the Pallindrome, Without Vowels, Character Frequencies...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_palindrome(char *string, char *rev_str){
    if(!strcmp(string, rev_str)){
        printf("\n%s is Palindrome!",string);
    }
    else{
        printf("\n%s is Not Palindrome!",string);
    }
}

void same_case(char* some_str){
        int i=0;
        while(some_str[i]!='\0'){
            some_str[i]= toupper(some_str[i]);
            i++;
        }
}
bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main(){

    char string[100];
    char rev_str[100];
    int len;
    int frequencies;
    char input[100];
    char out[100];

 {
     {
        printf("Enter a String: ");
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0'; //Remove NewLine and Replace it with Null if present
        len = strlen(string);
        strcpy(input, string);
    }

    { same_case(string);  same_case(rev_str);}
    {
         printf("\nOriginal String: %s",string);
         for(int i=0; i<len; i++){
            rev_str[i] = string[len-i-1];
    }       rev_str[len]='\0';
            printf("\nReversed String: %s",rev_str);
    }
    check_palindrome(string,rev_str);
}

    //Remove Vowels and Print rest of string...
    int j=0;
    for (int i=0; input[i]!='\0'; i++){
        if(!isVowel(input[i])){
            out[j]=input[i];
            j++;
        }
    }out[j]='\0';

printf("\nWithout Vowels: %s",out);


int m=0;
while(string[m]!='\0'){
    int target =string[m];
    int count = 0;
    for(int k=0; string[k]!='\0';k++){
        if(target==string[k]){
            count++;
        }
    }m++;
printf("\n %c : %d", target, count);
}

}

