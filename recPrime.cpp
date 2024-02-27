#include <iostream>
using namespace std;
bool prime(int num, int x)
{
    if (x == 2)
        return (num % 2) ? true : false;
    if (x < 2)
        return false;
    if (num % x == 0)
        return false;
    return prime(num, x - 1);
}
int main()
{
    int n = 10;
    cout << prime(n, n - 1) << endl;
    return 0;
}