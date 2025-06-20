#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

// Function to check if stack is empty
int isEmpty(struct Stack *st)
{
    return st->top == -1;
}

// Push function
void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

// Pop function
char pop(struct Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char x = st->s[st->top];
        st->top--;
        return x;
    }
}

int isBalanced(char *exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    int balanced = 1;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&st, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(&st))
            {
                balanced = 0;
                break;
            }
            pop(&st);
        }
    }

    if (!isEmpty(&st))
        balanced = 0;

    free(st.s);

    return balanced;
}

int main()
{
    char *exp = "((x+y)*(z/(a-b)))";
    printf("The expression: %s \n\nIs Balanced: %d\n", exp, isBalanced(exp));
    return 0;
}
