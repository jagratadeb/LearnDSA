#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

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

int main()
{
    struct Stack st;
    st.top = -1;
    printf("Enter the stack size: ");
    scanf("%d", &st.size);
    st.s = (int *)malloc(st.size * sizeof(int));

    // Example: push 3 elements
    for (int i = 0; i < 3; i++)
    {
        int val;
        printf("Enter value to push: ");
        scanf("%d", &val);
        st.top++;
        st.s[st.top] = val;
    }

    printf("Popping two elements...\n");
    printf("Popped: %d\n", pop(&st));
    printf("Popped: %d\n", pop(&st));

    printf("Stack contents: ");
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");

    free(st.s);
    return 0;
}
