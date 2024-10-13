#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};

int main(){
    struct Rectangle r = {10,20};
    printf("\n%d X %d\n",r.length,r.breadth);


    r.length = 15;
    r.breadth = 25;
    printf("\n%d X %d\n",r.length,r.breadth);


    struct Rectangle *p = &r;
    (*p).length = 20;    
    p->breadth = 100;
    printf("\n%d X %d\n",r.length,r.breadth);
    printf("\n%d X %d\n",p->length,p->breadth);
    return 0;
}