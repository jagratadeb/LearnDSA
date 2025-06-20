#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
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

    displayStack(st);

    free(st.s);
    return 0;
}
