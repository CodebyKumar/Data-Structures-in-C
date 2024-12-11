#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    char usn[20];
    char branch[20];
    int year;
    struct node *lptr, *rptr;
} NODE;

void ins_first(NODE *head) {
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the details of the student...\n");
    printf("Name: "); scanf("%s", newnode->name);
    printf("USN: "); scanf("%s", newnode->usn);
    printf("Branch: "); scanf("%s", newnode->branch);
    printf("Year of admission: "); scanf("%d", &newnode->year);
    newnode->lptr = head;
    newnode->rptr = head->rptr;
    if (head->rptr != NULL)
        head->rptr->lptr = newnode;
    head->rptr = newnode;
    printf("\nStudent is added successfully to the list");
    head->year++;
}

void display1(NODE *head) {
    NODE *first;
    char branch[20];
    int flag = 0;
    if (head->rptr == NULL) {
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter the branch: ");
    scanf("%s", branch);
    first = head->rptr;
    while (first != NULL) {
        if (strcmp(first->branch, branch) == 0) {
            if (flag == 0) {
                printf("\nList of students belonging to branch %s\n", branch);
                printf("\n\nName\tUSN\tYear of admission\n");
                flag = 1;
            }
            printf("%s\t%s\t%d\n", first->name, first->usn, first->year);
        }
        first = first->rptr;
    }
    if (flag == 0)
        printf("\nFailure, no student from branch %s", branch);
}

void display2(NODE *head) {
    NODE *first;
    if (head->rptr == NULL) {
        printf("\nEmpty list");
        return;
    }
    printf("\nName\tUSN\tBranch\tYear of admission\n");
    first = head->rptr;
    while (first != NULL) {
        printf("%s\t%s\t%s\t%d\n", first->name, first->usn, first->branch, first->year);
        first = first->rptr;
    }
    printf("\nTotal number of students = %d", head->year);
}

int main() {
    NODE *head;
    int choice;
    head = (NODE*)malloc(sizeof(NODE));
    head->lptr = head->rptr = NULL;
    head->year = 0;
    while (1) {
        printf("\n1: Add student\n2: Display based on branch\n3: Display all\n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: ins_first(head); break;
            case 2: display1(head); break;
            case 3: display2(head); break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}
