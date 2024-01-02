#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {4, 34, -1, 5, 4, 2, -5, 8, 7, -7, 7, 2, -6, 9, -5}, n = sizeof(arr) / sizeof(arr[0]);
    map<int, int> start, stop;
    for (int i = 0; i < n; i++)
    {
        if (start.find(arr[i]) == start.end())
        {
            start.insert(make_pair(arr[i], i));
        }
        stop.insert(make_pair(arr[i], i));
    }
    map<int, int>::iterator x = start.begin(), y = stop.begin();
    int max = INT_MIN;
    for (int i = 0; i < start.size(); i++)
    {
        advance(x, 1);
        advance(y, 1);

        cout << x->first << " " << x->second << " " << y->second << endl;

        int num = abs(x->second - y->second);
        if (num > max)
            max = num;
    }
    cout << max;
    return 0;
}