#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
int main()
{
    Node *arbPTR[10] = {new Node(0)};
    cout << arbPTR[5]->data << endl;
    return 1;
}