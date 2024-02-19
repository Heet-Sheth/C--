#include <iostream>
using namespace std;
int main()
{
    int a[] = {0, 1, 5, 6, 4, 7, 2, 2}, x = 0;
    for (int i = 0; i < 8; i++)
        x ^= a[i];
    cout << x;
    return 0;
}