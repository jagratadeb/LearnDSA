#include <stdio.h>

struct Test{
    int arr[5];
    int n;
};

void fun(struct Test t1){
    t1.arr[0] = 100;
    t1.arr[1] = 99;
}

int print(struct Test Tprint){
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",Tprint.arr[i]);
    }
    printf("\n%d\n", Tprint.n);
}

int main(){
    struct Test t = {{2,4,6,8,10},5};
    print(t);
    fun(t);
    return 0;
}