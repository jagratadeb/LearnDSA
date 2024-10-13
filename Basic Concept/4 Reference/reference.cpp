#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int &r = a;
    cout<<a<<endl;
    cout<<r<<endl;
    r++;
    a = 100;
    cout<<a<<endl;
    cout<<r<<endl;
    return 0;
}