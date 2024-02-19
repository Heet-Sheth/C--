#include <iostream>
#include <vector>
using namespace std;
vector<int> rotate(int n, int d)
{
    int max = INT_MAX;
    max = max - (max >> 1);
    int nl = n, nr = n;
    for (int i = 0; i < d; i++)
    {
        int left = max & nl;
        nl <<= 1;
        if (left)
            nl += 1;

        int right = nr & 1;
        nr >>= 1;
        if (right)
            nr += max;

        cout << i << "." << nr << endl;
    }
    vector<int> ans;
    ans.push_back(nl);
    ans.push_back(nr);
    return ans;
}
int main()
{
    int n = 34, d = 2;
    vector abc = rotate(n, d);
    cout << abc[0] << "," << abc[1];
    return 0;
}