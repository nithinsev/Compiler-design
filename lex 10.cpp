#include <stdio.h>
#include <string.h>
#define MAX_RULES 10
#define MAX_RULE_LEN 10
int main() {
    char non_terminal, production[MAX_RULES][MAX_RULE_LEN], new_production[MAX_RULES][MAX_RULE_LEN];
    int i, j, k, n;
    printf("Enter the production rules:\n");
    scanf("%c", &non_terminal);
    scanf("%s", production[0]);
    for (i = 1; i < MAX_RULES; i++) {
        printf("Enter the next production rule (or enter '0' to stop):\n");
        scanf("%s", production[i]);
        if (production[i][0] == '0') {
            break;
        }
    }
    n = i; 
    for (i = 0; i < n; i++) {
        if (production[i][0] == non_terminal) {
            printf("Common prefix found in rule %d: %c", i+1, non_terminal);
            int prefix_len = 1;
            while (production[i][prefix_len] == production[0][prefix_len]) {
                prefix_len++;
            }
            printf("\nPrefix length: %d\n", prefix_len);
            char new_non_terminal = 'A';
            while (1) {
                int new_non_terminal_exists = 0;
                for (j = 0; j < n; j++) {
                    if (production[j][0] == new_non_terminal) {
                        new_non_terminal++;
                        new_non_terminal_exists = 1;
                        break;
                    }
                }
                if (!new_non_terminal_exists) {
                    break;
                }
            }
            printf("New non-terminal symbol: %c\n", new_non_terminal);
            for (j = 0, k = 0; j < n; j++) {
                if (j != i && production[j][0] == non_terminal) {
                    if (production[j][prefix_len] == '\0') {
                        strcpy(new_production[k++], "e");
                    } else {
                        sprintf(new_production[k++], "%c%s", new_non_terminal, &production[j][prefix_len]);
                    }
                } else {
                    strcpy(new_production[k++], production[j]);
                }
            }
            printf("New production rules:\n");
            for (j = 0; j < k; j++) {
                printf("%c%s\n", non_terminal, new_production[j]);
            }
            for (j = 0; j < k; j++) {
                strcpy(production[j], new_production[j]);
            }
            n = k;
        }
    }
    printf("The modified production rules are:\n");
    for (i = 0; i < n; i++) {
        printf("%c%s\n", non_terminal, production[i]);
    }
    return 0;
}

