#include <iostream>
using namespace std;
int longestPalindrome(string s)
{
    int small[26] = {0}, big[26] = {0};

    for (char i : s)
    {
        if (i >= 'a' && i <= 'z')
            small[i - 'a']++;
        else if (i >= 'A' && i <= 'Z')
            big[i - 'A']++;
    }

    int sum = 0;
    bool odds;
    for (int i = 0; i < 26; i++)
    {
        if (small[i])
        {
            if (small[i] & 1)
            {
                sum += (small[i] - 1);
                odds = true;
            }
            else
                sum += small[i];
        }
        if (big[i])
        {
            if (big[i] & 1)
            {
                sum += (big[i] - 1);
                odds = true;
            }
            else
                sum += big[i];
        }
    }
    if (odds)
        sum++;
    return sum;
}
int main()
{
    string s;
    cout << "Enter the string:";
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}