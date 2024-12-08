#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXSIZE 25

typedef struct {
    float items[MAXSIZE];
    int top;
} STACK;

void PUSH(STACK *s, float data) {
    s->items[++s->top] = data;
}

float POP(STACK *s) {
    return (s->items[s->top--]);
}

float compute(float op1, char symb, float op2) {
    switch (symb) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '$':
        case '^': return pow(op1, op2);
        default: return 0;
    }
}

int main() {
    STACK s;
    char postfix[30], symb;
    float n1, n2, res, data;
    int i;
    s.top = -1;

    printf("\nEnter a valid postfix expression:\n");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        symb = postfix[i];
        if (isdigit(symb)) {
            PUSH(&s, symb - '0');
        } else if (isalpha(symb)) {
            printf("\n%c = ", symb);
            scanf("%f", &data);
            PUSH(&s, data);
        } else {
            n2 = POP(&s);
            n1 = POP(&s);
            res = compute(n1, symb, n2);
            PUSH(&s, res);
        }
    }

    printf("\nResult of evaluation: %f", POP(&s));
    return 0;
}
