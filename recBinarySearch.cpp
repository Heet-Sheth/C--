#include <iostream>
using namespace std;
int search(int *arr, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] < x)
        return search(arr, mid + 1, high, x);
    else if (arr[mid] > x)
        return search(arr, low, mid - 1, x);
    else
        return mid;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, n = 15;
    cout << search(arr, 0, 14, 65);
    return 0;
}