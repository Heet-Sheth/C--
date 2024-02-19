#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;

    int n = name.length();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << name[j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 0; j < n - i; j++)
            cout << name[j] << " ";
        cout << endl;
    }
    return 0;
}