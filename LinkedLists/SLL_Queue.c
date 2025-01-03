#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} NODE;

// ins_last() function
NODE *ins_last(NODE *first, int data) {
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = NULL;
    if (first == NULL) {
        first = newnode;
    } else {
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\n%d is inserted into Queue", data);
    return first;
}

// del_first() function
NODE *del_first(NODE *first) {
    NODE *temp;
    if (first == NULL) {
        printf("\nQueue underflow");
    } else {
        temp = first;
        first = first->next;
        printf("\n%d is deleted from the queue", temp->info);
        free(temp);
    }
    return first;
}

// display() function
void display(NODE *first) {
    if (first == NULL) {
        printf("\nEmpty Queue");
        return;
    } else {
        printf("\nQueue Contents:\nFront->");
        while (first != NULL) {
            printf("%d->", first->info);
            first = first->next;
        }
        printf("Rear");
    }
}

int main() {
    NODE *first = NULL;
    int choice, data;

    while (1) {
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &data);
                first = ins_last(first, data);
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
