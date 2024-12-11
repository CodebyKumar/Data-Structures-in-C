/* C program to implement Josephus Problem */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    struct node *next;
} NODE;

/* C function to insert a node at the end of the CSLL */
NODE *ins_last(NODE *last, char name[]) {
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    strcpy(newnode->name, name);
    if (last == NULL) {
        last = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
    return last;
}

/* C function to delete a node from the CSLL */
NODE *del_node(NODE *last) {
    NODE *temp;
    temp = last->next;
    printf("%s ", temp->name);
    last->next = temp->next;
    free(temp);
    return last;
}

int main() {
    NODE *last = NULL;
    char name[20];
    int i, n;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    printf("\nEnter the names of the soldiers, type end to terminate:\n");
    scanf("%s", name);
    while (strcmp(name, "end") != 0) {
        last = ins_last(last, name);
        scanf("%s", name);
    }
    if (last == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\n\nThe order in which soldiers are eliminated: ");
        while (last->next != last) {
            for (i = 1; i < n; i++) {
                last = last->next;
            }
            last = del_node(last);
        }
        printf("\n\nThe soldier who escapes: %s\n", last->name);
    }
    return 0;
}