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
struct Node *insertAtLast(struct Node *root, vector<int> &v, int index)
{
    if (index == v.size())
        return NULL;
    struct Node *temp = new struct Node(v[index]);
    temp->prev = root;
    temp->next = insertAtLast(temp, v, index + 1);
    return temp;
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
    head = insertAtLast(NULL, v, 0);
    display(head);
    return 0;
}