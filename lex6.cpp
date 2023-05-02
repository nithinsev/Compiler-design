#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char input[50];
    printf("Enter an identifier: ");
    scanf("%s", input);
    if (!isalpha(input[0]) && input[0] != '_') {
        printf("Invalid identifier!\n");
        return 0;
    }
    for (int i = 1; i < strlen(input); i++) {
        if (!isalnum(input[i]) && input[i] != '_') {
            printf("Invalid identifier!\n");
            return 0;
        }
    }
    printf("Valid identifier!\n");
    return 0;
}

