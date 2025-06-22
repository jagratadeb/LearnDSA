#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int eval(char *postfix)
{
    struct Stack st;
    int i, x1, x2, r;
    st.size = strlen(postfix);
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(&st, postfix[i] - '0');
        }
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(&st, r);
                break;
            case '-':
                r = x1 - x2;
                push(&st, r);
                break;
            case '*':
                r = x1 * x2;
                push(&st, r);
                break;
            case '/':
                r = x1 / x2;
                push(&st, r);
                break;
            default:
                break;
            }
        }
    }
    r = pop(&st);
    free(st.s);
    return r;
}

int main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = eval(postfix);
    printf("Result: %d\n", result);
    return 0;
}
