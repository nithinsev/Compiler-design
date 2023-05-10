#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int i = 0;  // global variable to keep track of current position in input string

int is_terminal(char c) {
    return (c == 'a' || c == 'b');
}

int match(char expected, char *input) {
    if (input[i] == expected) {
        i++;
        return 1;
    }
    return 0;
}

int A(char *input) {
    if (match('a', input) && A(input) && match('b', input)) {
        return 1;
    }
    i--;  // backtrack if A() failed
    return 1;
}

int S(char *input) {
    return A(input) && i == strlen(input);
}

int main() {
    char input[MAX_LEN];

    printf("Enter input string: ");
    scanf("%s", input);

    if (S(input)) {
        printf("Input string is valid!\n");
    } else {
        printf("Input string is not valid.\n");
    }

    return 0;
}

