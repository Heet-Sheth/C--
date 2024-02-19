#include <iostream>
using namespace std;
int main()
{
    int arr[3][4];
    cout << arr << "," << arr[0] << "," << &arr[0][0] << endl;
    // int rows, cols;
    // cout << "Enter rows and cols no.:";
    // cin >> rows >> cols;
    // int **ptr = new int *[rows];
    // for (int i = 0; i < rows; i++)
    //     *(ptr + i) = new int[cols];

    // int arr[rows][cols];

    // arr[0][0] = -1;
    // ptr[0][0] = -1;

    // cout << ptr << "," << arr << endl
    //      << ptr[0] << "," << arr[0] << endl
    //      << ptr[0][0] << "," << arr[0][0] << endl;
    return 0;
}