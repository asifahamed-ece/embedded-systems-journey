#include <stdio.h>
#include <string.h>


void sortString(char word[]){
    int len = strlen(word);
    for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            if(word[i]>word[j]){ // If Current > next
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}


// Main Function Starts here

int main(){
    int n;
    printf("Enter No. of Words: ");
    scanf("%d", &n);

    char words[n][50];
    char sorted[n][50];

    printf("Enter %d of Word(s): \n",n);// Storing Words
    for(int i=0; i<n; i++){
        scanf("%s", words[i]);
        strcpy(sorted[i],words[i]);
        sortString(sorted[i]);
    }

    printf("\nAnagram Groups:\n");

    // For each unique signature, print all words with that signature
    for(int i = 0; i < n; i++) {
        // Skip if we already printed this signature
        int alreadyPrinted = 0;
        for(int k = 0; k < i; k++) {
            if(strcmp(sorted[k], sorted[i]) == 0) {
                alreadyPrinted = 1;
                break;
            }
        }

        if(alreadyPrinted) continue;

        // Print all words with this signature
        printf("Group: ");
        for(int j = 0; j < n; j++) {
            if(strcmp(sorted[i], sorted[j]) == 0) {
                printf("%s ", words[j]);
            }
        }
        printf("\n");
    }

    return 0;
}


