#include <iostream>
using namespace std;
void printEven(int n)
{
    if (!n)
        return;
    printEven(n - 2);
    cout << n << " ";
}
int main()
{
    int n = 10;
    printEven(n);
    return 0;
}