#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int isComment(char *line) {
    int len = strlen(line);
    int i = 0;
    
    // Check for single-line comment
    if (len >= 2 && line[0] == '/' && line[1] == '/') {
        return 1;
    }
    
    // Check for multi-line comment
    while (i < len - 1) {
        if (line[i] == '/' && line[i+1] == '*') {
            i += 2;
            while (i < len - 1 && !(line[i] == '*' && line[i+1] == '/')) {
                i++;
            }
            if (i == len - 1) {
                return 0; // Unterminated multi-line comment
            }
            return 1;
        }
        i++;
    }
    
    return 0; // Not a comment
}

int main() {
    char line[MAX_LEN];
    printf("Enter a line of code: ");
    fgets(line, MAX_LEN, stdin);
    if (isComment(line)) {
        printf("This is a comment.\n");
    } else {
        printf("This is not a comment.\n");
    }
    return 0;
}

