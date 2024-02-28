#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node *insertAtStart(vector<int> &v, int index, Node *root)
{
    if (index == v.size())
        return root;
    Node *temp = new Node(v[index]);
    temp->next = root;
    if (root)
        root->prev = temp;
    return insertAtStart(v, index + 1, temp);
}
void display(struct Node *head)
{
    struct Node *root = head;
    while (root)
    {
        cout << root->data << ",";
        root = root->next;
    }
    cout << endl;
}
int main()
{
    vector<int> v = {34, 5, 6, 4, 4, 6, 56, 5, 7, 7, 44, 345, 6, 46, 34, 7, 54, 7, 54, 67};
    Node *head = NULL;
    head = insertAtStart(v, 0, NULL);
    display(head);
    return 0;
}