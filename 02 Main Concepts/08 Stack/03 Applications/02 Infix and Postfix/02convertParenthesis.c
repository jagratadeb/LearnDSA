#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure for characters
struct Stack
{
    int size;
    int top;
    char *s;
};

// Push a character onto the stack
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

// Pop a character from the stack
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

// Return precedence of operators
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0; // For non-operators (including parenthesis)
}

// Check if character is an operand (letter or digit)
int isOperand(char x)
{
    // Return 1 for alphabets and digits only
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
        return 1;
    else
        return 0;
}

// Convert infix expression to postfix (supports parenthesis)
char *InfixToPostfix(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    struct Stack st;
    st.size = len + 2; // Stack size: input length + sentinel + safety
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    char *postfix = (char *)malloc((len + 2) * sizeof(char));

    push(&st, '#'); // Sentinel to mark bottom of stack

    // Scan each character in the infix expression
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i])) // If operand, add to postfix
            postfix[j++] = infix[i++];
        else if (infix[i] == '(') // If '(', push to stack
        {
            push(&st, infix[i++]);
        }
        else if (infix[i] == ')') // If ')', pop until '(' is found
        {
            while (st.s[st.top] != '(' && st.s[st.top] != '#')
                postfix[j++] = pop(&st);
            if (st.s[st.top] == '(')
                pop(&st); // Remove '(' from stack
            i++;
        }
        else // Operator: pop higher/equal precedence (left-associative), then push
        {
            // Pop from stack while precedence is greater or equal (left-associative)
            while (pre(infix[i]) <= pre(st.s[st.top]) && st.s[st.top] != '#')
                postfix[j++] = pop(&st);
            push(&st, infix[i++]);
        }
    }
    // Pop any remaining operators from stack
    while (st.s[st.top] != '#')
        postfix[j++] = pop(&st);
    postfix[j] = '\0'; // Null-terminate postfix string
    free(st.s);
    return postfix;
}

int main()
{
    char *infix = "A+B*(C+D)/F+D*E";
    char *postfix = InfixToPostfix(infix);
    printf("Infix Expression   : %s\n", infix);
    printf("Postfix Expression : %s\n", postfix);
    free(postfix);
    return 0;
}