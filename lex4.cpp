#include <stdio.h>
#include <ctype.h>

int main() {
    char oper;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &oper);

    if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
        printf("Valid operator\n");
    }
    else {
        printf("Invalid operator\n");
    }

    return 0;
}

