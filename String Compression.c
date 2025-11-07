#include <stdio.h>
#include <string.h>

int main(){

    char str[50];
    char result[50];

    printf("Enter the String:");
    scanf("%s", str);

    int j=0;
    int len = strlen(str);
    for(int i=0; i<len; i++){
        char current = str[i];
        int count = 1;

        while(i+1 < len && str[i] == str[i+1]){
            count++;
            i++;
        }
     result[j++] = current;
     result[j++] = count + '0';
    }
    result[j] = '\0';  // Null terminate
    printf("RLE: %s\n", result);
    return 0;
}




