#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insertAtMiddle(int x, int value, struct node *root)
{
    if (!root)
    {
        root = new struct node(value);
        return;
    }
    struct node *temp = root;
    while (--x)
    {
        if (!temp->next)
        {
            temp->next = new struct node(value);
            return;
        }
        temp = temp->next;
    }
    struct node *nn = new struct node(value);
    nn->next = temp->next;
    temp->next = nn;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    struct node *head = NULL;
    for (int i = 0; i < 5; i++)
        insertAtMiddle(10, arr[i], head);
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}