#include <iostream>
using namespace std;
bool isConsonent(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return false;
    return true;
}
int noOfCons(string s, int n)
{
    if (n == s.length())
        return 0;
    return noOfCons(s, n + 1) + int(isConsonent(s[n]));
}
int main()
{
    string str = "abcdefghijklmnopqrstuvwxyz";
    cout << noOfCons(str, 0);
    return 0;
}