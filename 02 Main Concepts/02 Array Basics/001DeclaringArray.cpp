#include <iostream>
using namespace std;

int main()
{
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[10] = {2,4,6};
    int D[5] = {0};
    int E[] = {1,2,3,4,5,6};

    for(int ele: A){
        cout << ele << " ";
    }
    cout << endl;

    for(int ele: B){
        cout << ele << " ";
    }
    cout << endl;

    for(int ele: C){
        cout << ele << " ";
    }
    cout << endl;

    for(int ele: D){
        cout << ele << " ";
    }
    cout << endl;

    for(int ele: E){
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}