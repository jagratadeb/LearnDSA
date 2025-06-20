#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *s;
};

char *isEmpty(struct Stack st) {
    if (st.top == -1) {
        return "Yes";
    } else {
        return "No";
    }
}

char *isFull(struct Stack st) {
    if (st.top == st.size - 1) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    struct Stack st;
    st.top = -1;
    printf("Enter the stack size: ");
    scanf("%d", &st.size);
    st.s = (int *)malloc(st.size * sizeof(int));

    // Example: push 3 elements
    for (int i = 0; i < 3; i++) {
        int val;
        printf("Enter value to push: ");
        scanf("%d", &val);
        st.top++;
        st.s[st.top] = val;
    }

    printf("Is Empty: %s\n", isEmpty(st));
    printf("Is Full: %s\n", isFull(st));

    free(st.s);
    return 0;
}
