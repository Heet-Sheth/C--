//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;
        while (n--)
            v.push_back(make_pair(start[n], end[n]));
        sort(v.begin(), v.end());
        int st = 0, ed = 0, count = 0;
        for (auto i : v)
        {
            if (i.first > ed)
            {
                count++;
                st = i.first;
                ed = i.second;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    // testcases
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        cout << "->" << n << endl;

        // adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        // function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends