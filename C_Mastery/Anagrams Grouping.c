#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len-1; i++) {
        for(int j = i+1; j < len; j++) {
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void findAnagramGroups(char words[][50], int n) {
    char sorted[n][50];  // Store sorted versions
    int grouped[n];      // Track which words are grouped

    // Step 1: Sort all words and initialize tracking
    for(int i = 0; i < n; i++) {
        strcpy(sorted[i], words[i]);  // Copy original
        sortString(sorted[i]);        // Sort the copy
        grouped[i] = 0;              // Not grouped yet
    }

    printf("\nAnagram Groups:\n");
    int groupNum = 1;

    // Step 2: Find groups
    for(int i = 0; i < n; i++) {
        if(grouped[i]) continue;  // Already processed

        printf("Group %d: %s", groupNum, words[i]);
        grouped[i] = 1;  // Mark as grouped

        // Step 3: Find all anagrams of current word
        for(int j = i+1; j < n; j++) {
            if(!grouped[j] && strcmp(sorted[i], sorted[j]) == 0) {
                printf(" %s", words[j]);
                grouped[j] = 1;  // Mark as grouped
            }
        }
        printf("\n");
        groupNum++;
    }
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][50];
    printf("Enter %d words:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    findAnagramGroups(words, n);
    return 0;
}
