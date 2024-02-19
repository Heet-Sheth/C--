#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int perfG = 0, perfR = 0;
// PRNG generator
int pRandom(int n)
{
    return rand() % n;
}
bool comparator(pair<int, int> a, pair<int, int> b)
{
    int x = a.second / a.first;
    int y = b.second / b.first;
    return x < y;
}
// Greedy Approach
int greedy(vector<pair<int, int>> v, int cap, int n)
{
    sort(v.begin(), v.end(), comparator);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        perfG++;
        if (cap >= v[i].first)
        {
            cap -= v[i].first;
            sum += v[i].second;
        }
        else
            return sum;
    }
    return sum;
}
// Randomized Approach
int randomize(vector<pair<int, int>> v, int cap, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (rand() & 1)
        {
            perfR++;
            if (cap >= v[i].first)
            {
                cap -= v[i].first;
                sum += v[i].second;
            }
        }
    }
    return sum;
}
// Driver Code
int main()
{
    int n = 100, capacity = 0;
    srand(0);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x = pRandom(1000);
        capacity += x;
        v.push_back(make_pair(pRandom(1000), x));
    }

    capacity *= 0.75;

    int randomP = randomize(v, capacity, n);
    int greedyP = greedy(v, capacity, n);

    cout << "Total Profit for 100 items is, Greedy: " << greedyP << " and Randomized: " << randomP << endl;
    cout << "No. of comparisons between Greedy Knapsack Algorithm and Randomized Knapsack Algorithm is :" << perfG << " and " << perfR << endl;
    return 0;
}