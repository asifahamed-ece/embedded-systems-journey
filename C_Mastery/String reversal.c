#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int len = 100;
    char *str = malloc(len * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter a line: ");
    if (fgets(str, len, stdin) != NULL) {
        // Remove newline if present
        str[strcspn(str, "\n")] = '\0';
        printf("You entered: %s\n", str);
        printf("Reversed String is %s",strrev(str));
    }
    free(str);
    return 0;
}
/*
void main(){
    char str[50];
    printf("Enter the String to Reverse: ");
    fgets(str, sizeof(str), stdin);
    printf("String length is %d\n " ,strlen(str));
    int i=0; int j = strlen(str)-1;
    while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++; --j;
    }

    printf("Reversed String is : %s",str);
}
*/
