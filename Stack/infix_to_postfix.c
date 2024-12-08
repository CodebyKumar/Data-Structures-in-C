#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 25

typedef struct {
    char items[MAXSIZE];
    int top;
} STACK;

void PUSH(STACK *s, char data) {
    s->items[++s->top] = data;
}

char POP(STACK *s) {
    return s->items[s->top--];
}

char PEEK(STACK s) {
    return s.items[s.top];
}

int preced(char symb) {
    switch (symb) {
        case '#':
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '$':
        case '^': return 3;
        default: return -1;
    }
}

int main() {
    STACK s;
    char infix[30], postfix[30], symb, ch;
    int i, j = 0;
    s.top = -1;

    printf("\nEnter a valid infix expression:\n");
    scanf("%s", infix);

    PUSH(&s, '#');

    for (i = 0; infix[i] != '\0'; i++) {
        symb = infix[i];
        if (isalnum(symb)) {
            postfix[j++] = symb;
        } else {
            switch (symb) {
                case '(': 
                    PUSH(&s, '(');
                    break;
                case ')': 
                    while ((ch = POP(&s)) != '(') {
                        postfix[j++] = ch;
                    }
                    break;
                default: 
                    while (preced(symb) <= preced(PEEK(s))) {
                        if (symb == PEEK(s) && preced(symb) == 3) {
                            break;
                        }
                        postfix[j++] = POP(&s);
                    }
                    PUSH(&s, symb);
                    break;
            }
        }
    }

    while (PEEK(s) != '#') {
        postfix[j++] = POP(&s);
    }
    postfix[j] = '\0';

    printf("\nResultant Postfix Expression:\n");
    printf("%s", postfix);

    return 0;
}