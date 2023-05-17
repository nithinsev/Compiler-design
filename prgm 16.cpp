#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp_count = 1;

typedef struct node {
    char data[100];
    struct node* left;
    struct node* right;
} node;

node* create_node(char* data, node* left, node* right) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

char* new_temp() {
    char* temp = (char*) malloc(sizeof(char) * 10);
    sprintf(temp, "t%d", temp_count);
    temp_count++;
    return temp;
}

void print_code(node* tree) {
    if (tree == NULL) {
        return;
    }
    if (strcmp(tree->data, "+") == 0) {
        char* temp = new_temp();
        printf("%s = %s + %s\n", temp, tree->left->data, tree->right->data);
        print_code(tree->left);
        print_code(tree->right);
    } else if (strcmp(tree->data, "-") == 0) {
        char* temp = new_temp();
        printf("%s = %s - %s\n", temp, tree->left->data, tree->right->data);
        print_code(tree->left);
        print_code(tree->right);
    } else if (strcmp(tree->data, "*") == 0) {
        char* temp = new_temp();
        printf("%s = %s * %s\n", temp, tree->left->data, tree->right->data);
        print_code(tree->left);
        print_code(tree->right);
    } else if (strcmp(tree->data, "/") == 0) {
        char* temp = new_temp();
        printf("%s = %s / %s\n", temp, tree->left->data, tree->right->data);
        print_code(tree->left);
        print_code(tree->right);
    } else {
        printf("%s = %s\n", tree->data, tree->data);
    }
}

int main() {
    node* tree = create_node("+", create_node("a", NULL, NULL), create_node("*", create_node("b", NULL, NULL), create_node("c", NULL, NULL)));
    print_code(tree);
    return 0;
}

