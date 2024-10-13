#include <iostream>
using namespace std;

int main()
{
  int n;
  printf("Enter the value of n:\n");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << endl;
  for (int x : arr)
  {
    cout << x << " ";
  }
  return 0;
}