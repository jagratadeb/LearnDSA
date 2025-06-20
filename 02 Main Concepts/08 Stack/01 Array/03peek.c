#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

int peek(struct Stack st)
{
    int pos = 0;
    int data = -1;
    printf("\nEnter position to peek: ");
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

    printf("Stack contents: ");
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");

    printf("Peeked value: %d\n", peek(st));

    free(st.s);
    return 0;
}
