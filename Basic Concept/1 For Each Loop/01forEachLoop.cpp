#include <iostream>
using namespace std;

int main(){
    int n; 
    // Prompt the user for the number of elements in the array
    cout << "How many numbers to insert in array:";
    cin >> n;

    // Declare an array of size n
    int arr[n];
    
    // Input n elements into the array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Output all elements of the array
    for(int element : arr){
        cout << element << " ";
    }

    // Return 0 to indicate successful execution
    return 0;
}
