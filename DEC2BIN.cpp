#include <iostream>
#include <math.h>
using namespace std;
void d2b(int n)
{
    if (n)
    {
        d2b(n >> 1);
        cout << char((n & 1) + '0');
    }
}
int b2d(string s)
{
    int n = s.length(), po = 1, sum = 0;
    while (n--)
    {
        if (s[n] == '1')
            sum += po;
        po <<= 1;
    }
    return sum;
}
int main()
{
    // int n;
    // cout << "Enter decimal number: ";
    // cin >> n;
    // d2b(n);
    cout << b2d("11111111");
    return 0;
}