#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} NODE;

// ins_first() function
NODE *ins_first(NODE *first, int data) {
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = first;
    printf("\n%d is pushed on to the stack", data);
    return newnode;
}

// del_first() function
NODE *del_first(NODE *first) {
    NODE *temp;
    if (first == NULL) {
        printf("\nStack underflow");
        return NULL;
    } else {
        temp = first;
        first = first->next;
        printf("\n%d is popped from the stack", temp->info);
        free(temp);
        return first;
    }
}

// display() function
void display(NODE *first) {
    if (first == NULL) {
        printf("\nEmpty Stack");
        return;
    }
    printf("\nStack Contents:\nTop->");
    while (first != NULL) {
        printf("%d->", first->info);
        first = first->next;
    }
    printf("Bottom");
}

int main() {
    NODE *first = NULL;
    int choice, data;

    while (1) {
        printf("\n\n1: PUSH\n2: POP\n3: Display\n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the data to be pushed: ");
                scanf("%d", &data);
                first = ins_first(first, data);
                break;
            case 2:
                first = del_first(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}
