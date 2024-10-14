#include <stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

int changeLength(struct Rectangle *p, int l){
    p->length = l;
}

int main(){
    struct Rectangle r = {10, 5};
    changeLength(&r,20);
    printf("L = %d\nB = %d\n", r.length ,r.breadth);
    return 0;
}