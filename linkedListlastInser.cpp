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
struct node *insertLast(struct node *root, int value)
{
    if (!root)
        return new struct node(value);
    root->next = insertLast(root->next, value);
    return root;
}
struct node *createLinkedList(int index, int size, int *arr)
{
    if (index == size)
        return NULL;
    struct node *temp = new node(arr[index]);
    temp->next = createLinkedList(index + 1, size, arr);
    return temp;
}
int main()
{
    struct node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        head = insertLast(head, arr[i]);
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;

    struct node *h1 = createLinkedList(0, 5, arr);
    temp = h1;
    while (temp)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}