#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

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
        printf("Data to push: ");
        scanf("%d", &data);
        st->s[st->top] = data;
    }
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
        push(&st);
    }

    printf("Stack contents: ");
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");

    free(st.s);
    return 0;
}
