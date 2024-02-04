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
struct node *insertAtBegining(int *arr, int index, int size, struct node *root)
{
    if (index == size)
        return root;
    struct node *temp = new struct node(arr[index]);
    temp->next = root;
    return insertAtBegining(arr, index + 1, size, temp);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    struct node *head = insertAtBegining(arr, 0, 5, NULL);
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}