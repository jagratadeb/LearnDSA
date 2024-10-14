#include <stdio.h>

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p = 2*(length + breadth);
    return p;
}

int main()
{
    int length = 0, breadth = 0, A = 0, P = 0;
    printf("Enter the length and breadth of the rectangle:\n");
    scanf("%d %d", &length, &breadth);

    A = area(length, breadth);
    P = perimeter(length, breadth);

    printf("Area:%d\nPerimeter:%d\n", A, P);
    return 0;
}