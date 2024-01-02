#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addEdje(int x, int y, vector<vector<int>> &v)
{
    v[x - 1].push_back(y);
    v[y - 1].push_back(x);
}
void printChildren(int root, vector<vector<int>> &v)
{
    queue<int> q;
    bool vis[v.size()] = {false};
    q.push(root);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vis[node - 1] = true;
        cout << node << "->";
        for (auto i : v[node - 1])
        {
            if (!vis[i - 1])
            {
                q.push(i);
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
void printLeafs(int root, vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].size() == 1 && i != root - 1)
            cout << i + 1 << " ";

    cout << endl;
}
void printEdgeCount(vector<vector<int>> &v, int root)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << "->";
        if (i == root - 1)
            cout << v[i].size();
        else
            cout << v[i].size() - 1;
        cout << endl;
    }
}
void printParents(int node, vector<vector<int>> &v, int parent)
{
    cout << node << "->";
    if (!parent)
        cout << "root";
    else
        cout << parent;
    cout << endl;
    for (auto cur : v[node - 1])
    {
        if (cur != parent)
            printParents(cur, v, node);
    }
}
int main()
{
    int n = 7, root = 1;
    vector<vector<int>> v(n);
    addEdje(1, 2, v);
    addEdje(1, 3, v);
    addEdje(1, 4, v);
    addEdje(2, 5, v);
    addEdje(4, 6, v);
    addEdje(2, 7, v);
    cout << endl
         << "Children of all nodes in the tree" << endl;
    printChildren(root, v);
    cout << endl
         << "All leaf nodes" << endl;
    printLeafs(root, v);
    cout << endl
         << "Count of child nodes of all nodes" << endl;
    printEdgeCount(v, root);
    cout << endl
         << "Parents of all nodes of tree" << endl;
    printParents(root, v, 0);
    return 0;
}