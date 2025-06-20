#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

void push(struct Stack *st);
int pop(struct Stack *st);
int peek(struct Stack st);
char *isEmpty(struct Stack st);
char *isFull(struct Stack st);
void displayStack(struct Stack st);

int main()
{
    struct Stack st;
    st.top = -1;
    printf("Enter the stack size:\n");
    scanf("%d", &st.size);
    st.s = (int *)malloc(st.size * sizeof(int));

    push(&st);
    push(&st);
    push(&st);
    push(&st);
    push(&st);
    displayStack(st);
    printf("Popped item: %d\n", pop(&st));
    printf("Popped item: %d\n", pop(&st));
    displayStack(st);
    printf("Peek item: %d\n", peek(st));
    printf("Peek item: %d\n", peek(st));
    printf("Is Empty: %s\n", isEmpty(st));
    printf("Is Full: %s\n", isFull(st));

    return 0;
}

void push(struct Stack *st)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int data = 0;
        st->top++;
        printf("Data to push:");
        scanf("%d", &data);
        st->s[st->top] = data;
    }
}

int pop(struct Stack *st)
{
    int data = -1;
    if (st->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        data = st->s[st->top];
        st->top--;
    }
    return data;
}

int peek(struct Stack st)
{
    int pos = 0;
    int data = -1;

    printf("\nEnter position to peek:");
    scanf("%d", &pos);

    if (pos < 1 || pos > st.top + 1)
    {
        printf("Invalid Position!\n");
        return data;
    }
    else
    {
        data = st.s[st.top - pos + 1];
    }
    return data;
};

char *isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
};

char *isFull(struct Stack st)
{
    if (st.top == st.size)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
};

void displayStack(struct Stack st)
{
    printf("Displaying the stack:\n");
    if (st.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}