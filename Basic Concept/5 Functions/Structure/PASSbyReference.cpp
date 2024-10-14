#include <stdio.h>
#include <iostream>

struct Rectangle{
    int length;
    int breadth;
};

int area(struct Rectangle &rr){
    return rr.length * rr.breadth;
}

int main(){
    struct Rectangle r = {10,5};
    printf("%d\n", area(r));
    return 0;
}