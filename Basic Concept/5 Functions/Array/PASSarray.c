#include <stdio.h>

void func(int arr[]){
    for(int i = 0; i < 5; i++){
        arr[i] = arr[i] + 1;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i < 5;i++){
        printf("%d\n",arr[i]);
    }
    func(arr);
    printf("\n");
    for(int i = 0; i < 5;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}