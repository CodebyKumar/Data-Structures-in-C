#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node {
    char info;
    struct node *lchild, *rchild;
} NODE;

NODE *create_tree(char postfix[]) {
    NODE *newnode, *stack[20];
    int i = 0, top = -1;
    char ch;
    
    while ((ch = postfix[i++]) != '\0') {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->info = ch;
        newnode->lchild = newnode->rchild = NULL;
        
        if (isalnum(ch)) {
            stack[++top] = newnode;
        } else {
            newnode->rchild = stack[top--];
            newnode->lchild = stack[top--];
            stack[++top] = newnode;
        }
    }
    return stack[top--];
}

float eval(NODE *root) {
    float num;
    
    switch (root->info) {
        case '+':
            return eval(root->lchild) + eval(root->rchild);
        case '-':
            return eval(root->lchild) - eval(root->rchild);
        case '*':
            return eval(root->lchild) * eval(root->rchild);
        case '/':
            return eval(root->lchild) / eval(root->rchild);
        case '^':
            return pow(eval(root->lchild), eval(root->rchild));
        default:
            if (isalpha(root->info)) {
                printf("\n%c = ", root->info);
                scanf("%f", &num);
                return num;
            } else {
                return root->info - '0';
            }
    }
}

int main() {
    char postfix[30];
    float res;
    NODE *root = NULL;
    
    printf("\nEnter a valid Postfix expression\n");
    scanf("%s", postfix);
    
    root = create_tree(postfix);
    res = eval(root);
    
    printf("\nResult = %f", res);
    return 0;
}