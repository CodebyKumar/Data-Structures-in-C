#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
int count;

typedef struct {
    int items[MAXSIZE];
    int f, r;
} QUEUE;

int isfull(QUEUE q) {
    if (q.f == (q.r + 1) % MAXSIZE)
        return 1;
    return 0;
}

int isempty(QUEUE q) {
    if (q.f == -1)
        return 1;
    return 0;
}

void INSERT(QUEUE *q, int data) {
    q->r = (q->r + 1) % MAXSIZE;
    q->items[q->r] = data;
    printf("\n%d is inserted into circular queue", data);
    count++;
    if (q->f == -1)
        q->f = 0;
}

int DELETE(QUEUE *q) {
    int data;
    data = q->items[q->f];
    count--;
    if (q->f == q->r)
        q->f = q->r = -1;
    else
        q->f = (q->f + 1) % MAXSIZE;
    return data;
}

void DISPLAY(QUEUE q) {
    int i;
    printf("\nQUEUE CONTENTS:\nFRONT->");
    for (i = 1; i <= count; i++) {
        printf("%d->", q.items[q.f]);
        q.f = (q.f + 1) % MAXSIZE;
    }
    printf("REAR");
}

int main() {
    QUEUE q;
    int choice;
    int data;
    q.f = q.r = -1;
    while (1) {
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isfull(q))
                    printf("\nCircular Queue Overflow !!!");
                else {
                    printf("\nEnter the data to be inserted: ");
                    scanf("%d", &data);
                    INSERT(&q, data);
                }
                break;
            case 2:
                if (isempty(q))
                    printf("\nCircular Queue Underflow !!!");
                else
                    printf("\n%d is deleted from queue", DELETE(&q));
                break;
            case 3:
                if (isempty(q))
                    printf("\nCircular Queue is Empty !!!");
                else
                    DISPLAY(q);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}