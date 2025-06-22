#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        printf("Stack is full\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

char pop(struct Stack *st)
{
    char x = -1;
    if (st->top == -1)
        printf("Stack is Empty\n");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

// Function to return precedence of operators
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to check if character is operand (not operator)
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

// Function to convert infix to postfix (no parenthesis)
char *InfixToPostfix(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    struct Stack st;
    st.size = len + 2;
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    char *postfix = (char *)malloc((len + 2) * sizeof(char));

    // Push sentinel to stack
    push(&st, '#');

    // Main conversion loop
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(st.s[st.top]))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        }
    }
    // Pop remaining operators from stack
    while (st.s[st.top] != '#')
        postfix[j++] = pop(&st);
    postfix[j] = '\0';
    free(st.s);
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = InfixToPostfix(infix);
    printf("Infix Expression   : %s\n", infix);
    printf("Postfix Expression : %s\n", postfix);
    free(postfix);
    return 0;
}