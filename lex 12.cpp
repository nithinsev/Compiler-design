#include <stdio.h>
#include <ctype.h>

void E();
void E_prime();
void T();
void T_prime();
void F();
char lookahead;

int main() {
    printf("Enter an expression: ");
    lookahead = getchar();
    E();
    if (lookahead != '\n' && lookahead != EOF) {
        printf("Invalid expression\n");
    }
    return 0;
}

void E() {
    T();
    E_prime();
}

void E_prime() {
    if (lookahead == '+') {
        lookahead = getchar();
        T();
        E_prime();
    }
}

void T() {
    F();
    T_prime();
}

void T_prime() {
    if (lookahead == '*') {
        lookahead = getchar();
        F();
        T_prime();
    }
}

void F() {
    if (isdigit(lookahead)) {
        // Parse a number
        while (isdigit(lookahead)) {
            lookahead = getchar();
        }
    } else if (lookahead == '(') {
        // Parse an expression in parentheses
        lookahead = getchar();
        E();
        if (lookahead != ')') {
            printf("Missing closing parenthesis\n");
        }
        lookahead = getchar();
    } else {
        printf("Invalid expression\n");
    }
}

