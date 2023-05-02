#include <stdio.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 100

int main() {
    char c;
    char identifier[MAX_IDENTIFIER_LENGTH];
    int i = 0;
    int is_comment = 0;

    while ((c = getchar()) != EOF) {
        if (is_comment) {
            if (c == '*' && (c = getchar()) == '/') {
                is_comment = 0;
            }
        } else if (isspace(c)) {
            continue;
        } else if (c == '/' && (c = getchar()) == '*') {
            is_comment = 1;
        } else if (isalpha(c)) {
            identifier[i++] = c;
            while (isalnum(c = getchar()) || c == '_') {
                if (i < MAX_IDENTIFIER_LENGTH) {
                    identifier[i++] = c;
                }
            }
            identifier[i] = '\0';
            i = 0;
            printf("identifier: %s\n", identifier);
            ungetc(c, stdin);
        }
    }

    return 0;
}
y
