#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter a string:";
    cin >> s;

    int start = 0, end = s.size() - 1;
    while (start < end)
        swap(s[start++], s[end--]);

    cout << s;
    return 0;
}