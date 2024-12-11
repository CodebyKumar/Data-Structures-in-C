#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char player[20];
    char team[20];
    float bavg;
    struct node *next;
} NODE;

NODE *addPlayer(NODE *first) {
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    printf("\nEnter the player details.....\n");
    printf("Name: ");
    scanf("%s", newnode->player);
    printf("Team: ");
    scanf("%s", newnode->team);
    printf("Batting Average: ");
    scanf("%f", &newnode->bavg);
    if (first == NULL) {
        first = newnode;
    } else {
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nPlayer %s is added at the end of the list", newnode->player);
    return first;
}

void display(NODE *first) {
    if (first == NULL) {
        printf("\nEmpty list");
        return;
    }
    printf("\nPlayer Details........\n");
    printf("\nNAME\tTEAM\tBATTING AVERAGE\n");
    while (first != NULL) {
        printf("%s\t%s\t%f\n", first->player, first->team, first->bavg);
        first = first->next;
    }
}

NODE *searchPlayer(NODE *first) {
    NODE *temp;
    char player[20];
    if (first == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\nEnter the player name to search: ");
        scanf("%s", player);
        temp = first;
        while (temp != NULL && strcmp(temp->player, player) != 0) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\nPlayer %s not existing in the list", player);
        } else {
            printf("\nPlayer %s is existing in the list", player);
            printf("\nCurrent batting average: %f", temp->bavg);
            printf("\nEnter new value for batting average: ");
            scanf("%f", &temp->bavg);
            printf("\nBatting average of player %s is updated successfully ", player);
        }
    }
    return first;
}

int main() {
    NODE *first = NULL;
    int choice;
    while (1) {
        printf("\n1:ADD PLAYER\n2:SEARCH PLAYER\n3:DISPLAY PLAYER\n4:EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                first = addPlayer(first);
                break;
            case 2:
                first = searchPlayer(first);
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