#include <iostream>
using namespace std;
int countEven(int *arr, int n)
{
    if (n == -1)
        return 0;
    return countEven(arr, n - 1) + !(arr[n] & 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "No. of even elemenets in list is:" << countEven(arr, 8);
    return 0;
}