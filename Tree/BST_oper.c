#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *lchild, *rchild;
} NODE;

NODE *insert(NODE *root, int data) {
    NODE *newnode, *temp, *parent;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->lchild = newnode->rchild = NULL;
    newnode->info = data;
    if (root == NULL) {
        root = newnode;
    } else {
        temp = root;
        while (temp != NULL) {
            parent = temp;
            if (data > temp->info) {
                temp = temp->rchild;
            } else if (data < temp->info) {
                temp = temp->lchild;
            } else {
                printf("\nData %d is already existing in the BST", data);
                return root;
            }
        }
        if (data > parent->info) {
            parent->rchild = newnode;
        } else {
            parent->lchild = newnode;
        }
    }
    printf("\n%d is inserted into BST", data);
    return root;
}

void inorder(NODE *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->info);
    inorder(root->rchild);
}

NODE *del_key(NODE *root, int key) {
    NODE *cur, *q, *parent, *successor;
    parent = NULL;
    cur = root;
    while (cur != NULL) {
        if (cur->info == key) {
            break;
        }
        parent = cur;
        cur = (key < cur->info) ? cur->lchild : cur->rchild;
    }
    if (cur == NULL) {
        printf("\nKey %d is not found", key);
        return root;
    }
    if (cur->lchild == NULL) {
        q = cur->rchild;
    } else if (cur->rchild == NULL) {
        q = cur->lchild;
    } else {
        successor = cur->rchild;
        while (successor->lchild != NULL) {
            successor = successor->lchild;
        }
        successor->lchild = cur->lchild;
        q = cur->rchild;
    }
    if (parent == NULL) {
        printf("\n%d is deleted from BST", key);
        free(cur);
        return q;
    }
    if (cur == parent->lchild) {
        parent->lchild = q;
    } else {
        parent->rchild = q;
    }
    printf("\n%d is deleted from BST", key);
    free(cur);
    return root;
}

int main() {
    int choice, data, key;
    NODE *root = NULL;
    while (1) {
        printf("\n1:Insert 2:Inorder 3:Delete 4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                if (root == NULL) {
                    printf("\nEmpty Tree");
                } else {
                    printf("\nInorder Traversal: ");
                    inorder(root);
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("\nEmpty Tree");
                } else {
                    printf("\nEnter the key to delete: ");
                    scanf("%d", &key);
                    root = del_key(root, key);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}