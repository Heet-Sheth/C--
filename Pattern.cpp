#include <iostream>
using namespace std;
int main()
{
    int N = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; i < i + 1; j++)
            cout << "*";
        if (i + 1 != N)
            cout << "@";
    }
    return 0;
}