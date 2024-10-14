#include <stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

int area(struct Rectangle rr){
    return rr.length * rr.breadth;
}

int main(){
    struct Rectangle r = {10,5};
    printf("The area is: %d", area(r));
    return 0;
}