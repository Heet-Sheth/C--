#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
struct NodeHeader
{
    int data;
    NodeHeader *next;
    Node *bottom;
    Node *tail;
    NodeHeader(int val)
    {
        data = val;
        next = NULL;
        bottom = NULL;
        tail = NULL;
    }
};
int priority(int n)
{
    if (n > 89)
        return 1;
    else if (n > 79)
        return 2;
    else if (n > 69)
        return 3;
    else if (n > 59)
        return 4;
    else
        return 5;
}
void enque(int n, NodeHeader *head)
{
    NodeHeader *root = head;
    int pr = priority(n);
    while (root->data != pr)
        root = root->next;
    if (!root->tail)
    {
        root->tail = new Node(n);
        root->bottom = root->tail;
    }
    else
    {
        root->tail->next = new Node(n);
        root->tail = root->tail->next;
    }
}
void deque(NodeHeader *head)
{
    NodeHeader *root = head;
    while (root && !root->bottom)
        root = root->next;
    if (!root)
    {
        cout << "Error! queue is empty";
        return;
    }
    Node *temp = root->bottom;
    root->bottom = root->bottom->next;
    cout << "Dequeued " << temp->data;
    delete temp;
    if (!root->bottom)
        root->tail = NULL;
}
int main()
{
    int userChoice = 0;
    NodeHeader *listRoot = new NodeHeader(1), *temp = listRoot;
    for (int i = 2; i < 6; i++)
    {
        temp->next = new NodeHeader(i);
        temp = temp->next;
    }
    while (userChoice == 0)
    {
        cout << "1. Enque" << endl
             << "2. Deque" << endl
             << "3. exit" << endl
             << "Enter choice(1-3):";
        cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            cout << "Enter an element between [50-100](including both):";
            int element;
            cin >> element;
            if (element >= 50 && element <= 100)
                enque(element, listRoot);
            else
                cout << "Invalid number entered";
            break;
        case 2:
            deque(listRoot);
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        userChoice = 0;
        cout << endl
             << endl;
    }
    return 0;
}