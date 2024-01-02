#include <iostream>
using namespace std;
void printSum(int *arr, int n)
{
    if (n == -1)
        return;
    printSum(arr, n - 1);
    cout << arr[n] << "-";
}
int main()
{
    int arr[] = {2, 6, 4, 7, 4, 7, 7, 3, 2, 56, 67, 8, 8, 4, 23, 2, 56, 78, 8};
    printSum(arr, 18);
    return 0;
}