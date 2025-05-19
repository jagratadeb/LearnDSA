#include <iostream>
using namespace std;

int main()
{
    char string[] = "programming";
    int H = 0, X = 0;

    for(int i = 0; string[i] != '\0'; i++){
        X = 1;
        X = X << (string[i] - 97);

        if((X & H)>0){
            cout << "Duplicate found: " << string[i] << endl;
        }else{
            H = (H | X);
        }
    }
    return 0;
}