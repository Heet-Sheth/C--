//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;
    void insertHeap(int &x)
    {
        cout << "insert" << endl;
        second.push(x);
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        int x = second.top();
        while (first.top() < x)
        {
            second.push(first.top());
            first.pop();
        }
        int n = second.size() / 2;
        while (n--)
        {
            first.push(second.top());
            second.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (second.size() > first.size())
            return second.top();
        else
            return ((double)(first.top() + second.top()) / 2.0);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends