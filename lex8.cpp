#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char productions[MAX][MAX];
int n;

char* follow(char c);

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }
    printf("\nFOLLOW( ) for the given grammar:\n");
    printf("S: %s\n", follow('S'));
    printf("A: %s\n", follow('A'));
    printf("B: %s\n", follow('B'));
    return 0;
}

char* follow(char c) {
    static char result[MAX];
    int len = strlen(productions[0]);
    int i, j;
    if (c == productions[0][0]) {
        result[0] = '$';
        result[1] = '\0';
    }
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (c == productions[i][j]) {
                if (j == strlen(productions[i])-1) {
                    if (c != productions[i][0]) {
                        char* temp = follow(productions[i][0]);
                        strcat(result, temp);
                    }
                } else {
                    int k;
                    for (k = j+1; k < strlen(productions[i]); k++) {
                        if (productions[i][k] != 'e') {
                            strncat(result, &productions[i][k], 1);
                            break;
                        }
                    }
                    if (k == strlen(productions[i])) {
                        if (c != productions[i][0]) {
                            char* temp = follow(productions[i][0]);
                            strcat(result, temp);
                        }
                    }
                }
            }
        }
    }
    return result;
}

