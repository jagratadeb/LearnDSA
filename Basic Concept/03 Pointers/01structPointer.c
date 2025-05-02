#include <stdio.h>

// Define a structure named 'Rectangle'
struct Rectangle {
    int length;   // Integer to hold the length of the rectangle
    int breadth;  // Integer to hold the breadth of the rectangle
};

int main(){
    // Declare a variable 'r' of type 'Rectangle' and initialize it
    struct Rectangle r = {20, 10};
    // Print the initial dimensions of the rectangle
    printf("\n%d X %d\n", r.length, r.breadth);

    // Modify the dimensions of the rectangle
    r.length = 25;
    r.breadth = 15;
    // Print the updated dimensions of the rectangle
    printf("\n%d X %d\n", r.length, r.breadth);

    // Declare a pointer 'p' to the structure 'Rectangle' and point it to 'r'
    struct Rectangle *p = &r;
    // Modify the dimensions using the pointer
    (*p).length = 100;  // Alternatively, can use p->length
    p->breadth = 20;
    // Print the modified dimensions of the rectangle
    printf("\n%d X %d\n", r.length, r.breadth);
    printf("\n%d X %d\n", p->length, p->breadth);

    return 0;
}
