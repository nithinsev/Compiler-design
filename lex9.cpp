#include <stdio.h>
#include <string.h>

#define MAX_LEN 100


int has_left_recursion(char non_term, char rules[][MAX_LEN], int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        if (rules[i][0] == non_term && rules[i][2] == non_term) {
            return 1;
        }
    }
    return 0;
}


void remove_left_recursion(char non_term, char rules[][MAX_LEN], int num_rules) {
    char new_non_term = non_term + 1;
    printf("%c -> ", non_term);
    int first_rule_printed = 0;
    for (int i = 0; i < num_rules; i++) {
        if (rules[i][0] == non_term && rules[i][2] != non_term) {
 
            if (first_rule_printed) {
                printf(" | ");
            }
            printf("%s%c\'", &rules[i][2], new_non_term);
            first_rule_printed = 1;
        }
    }
    printf("\n%c\' -> ", new_non_term);
    first_rule_printed = 0;
    for (int i = 0; i < num_rules; i++) {
        if (rules[i][0] == non_term && rules[i][2] == non_term) {
            
            if (first_rule_printed) {
                printf(" | ");
            }
            printf("%s%c\'", &rules[i][3], new_non_term);
            first_rule_printed = 1;
        }
    }
    printf(" | epsilon\n");
}

int main() {
    char start = 'S';
    char rules[][MAX_LEN] = {
        "S -> (L)",
        "S -> a",
        "L -> L,S",
        "L -> S"
    };
    int num_rules = sizeof(rules) / sizeof(rules[0]);
    int has_recursion[num_rules]; 
    memset(has_recursion, 0, num_rules * sizeof(int));
  
    for (int i = 0; i < num_rules; i++) {
        if (has_left_recursion(rules[i][0], rules, num_rules)) {
            has_recursion[i] = 1;
        }
    }

    for (int i = 0; i < num_rules; i++) {
        if (!has_recursion[i]) {
            printf("%s\n", rules[i]);
        } else {
            remove_left_recursion(rules[i][0], rules, num_rules);
        }
    }
    return 0;
}

