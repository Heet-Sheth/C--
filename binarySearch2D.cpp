#include <iostream>
using namespace std;
int main()
{
    int arr[2][2] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
        cout << *int(arr + i) << endl;
    return 0;
}