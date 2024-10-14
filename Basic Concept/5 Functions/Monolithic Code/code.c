#include <stdio.h>

int main()
{
    int length = 0, breadth = 0, area = 0, perimeter = 0;
    printf("Enter the length and breadth of the rectangle:\n");
    scanf("%d %d",&length, &breadth);

    area = length * breadth;
    perimeter = 2 * (length + breadth);

    printf("Area:%d\nPerimeter:%d\n", area, perimeter);
    return 0;
}