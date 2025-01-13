#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name;
    struct node* left;
    struct node* right;
} node;

node* new_node(char name, int* count, node* arr[]) {
    for(int i = 0; i < *count; i++) {
        if(arr[i]->name == name) return arr[i];
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->name = name;
    new_node->left = NULL;
    new_node->right = NULL;
    arr[(*count)++] = new_node;
    return new_node;
}

void print_pre(node* root) {
    if(root == NULL) return;
    printf("%c", root->name);
    print_pre(root->left);
    print_pre(root->right);
}

void print_in(node* root) {
    if(root == NULL) return;
    print_in(root->left);
    printf("%c", root->name);
    print_in(root->right);
}

void print_post(node* root) {
    if(root == NULL) return;
    print_post(root->left);
    print_post(root->right);
    printf("%c", root->name);
}

int main() {
    int n;
    scanf("%d", &n);

    node* arr[26];
    int count = 0;

    for(int i = 0; i < n; i++) {
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);

        node* parent = new_node(a, &count, arr);
        if(b != '.') {
            parent->left = new_node(b, &count, arr);
        }
        if(c != '.') {
            parent->right = new_node(c, &count, arr);
        }
    }

    print_pre(arr[0]);
    printf("\n");
    print_in(arr[0]);
    printf("\n");
    print_post(arr[0]);
    printf("\n");

    for(int i = 0; i < count; i++) free(arr[i]);
    return 0;
}
