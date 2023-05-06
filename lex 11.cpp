#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char name[20];
    int address;
} Symbol;

Symbol symbol_table[MAX_SYMBOLS];
int num_symbols = 0;

void insert(char* name, int address);
int search(char* name);
void print_table();

int main() {
    insert("x", 100);
    insert("y", 200);
    insert("z", 300);

    int addr = search("y");
    if (addr == -1) {
        printf("Symbol not found\n");
    } else {
        printf("Symbol found at address %d\n", addr);
    }

    print_table();
    return 0;
}

void insert(char* name, int address) {
    if (num_symbols >= MAX_SYMBOLS) {
        printf("Symbol table full\n");
        return;
    }

    // Check if symbol already exists
    int existing_index = search(name);
    if (existing_index != -1) {
        printf("Symbol already exists\n");
        return;
    }

    // Insert new symbol
    Symbol s;
    strcpy(s.name, name);
    s.address = address;
    symbol_table[num_symbols] = s;
    num_symbols++;
}

int search(char* name) {
    for (int i = 0; i < num_symbols; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].address;
        }
    }
    return -1;
}

void print_table() {
    printf("Symbol table contents:\n");
    printf("Name\tAddress\n");
    for (int i = 0; i < num_symbols; i++) {
        printf("%s\t%d\n", symbol_table[i].name, symbol_table[i].address);
    }
}

