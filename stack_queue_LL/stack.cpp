#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void push1(Node *&top1, int element)
{
    top1->prev = new Node(element);
    top1 = top1->prev;
}
void push2(Node *&top2, int element)
{
    top2->next = new Node(element);
    top2 = top2->next;
}
void pop1(Node *&base, Node *&top1)
{
    if (top1 == base)
    {
        cout << "Error! Stack 1 is empty";
        return;
    }
    Node *temp = top1;
    top1 = top1->next;
    if (top1)
        top1->prev = NULL;
    cout << "Pop " << temp->data;
    delete temp;
}
void pop2(Node *&base, Node *&top2)
{
    if (top2 == base)
    {
        cout << "Error! Stack 2 is empty";
        return;
    }
    Node *temp = top2;
    top2 = top2->prev;
    if (top2)
        top2->next = NULL;
    cout << "Pop " << temp->data;
    delete temp;
}
void display(Node *head)
{
    Node *root = head;
    cout << "1:";
    while (root)
    {
        cout << root->data << ",";
        root = root->prev;
    }
    cout << endl;
    root = head;
    cout << "2:";
    while (root)
    {
        cout << root->data << ",";
        root = root->next;
    }
    cout << endl;
}
int main()
{
    int userChoice = 0, element;
    Node *basePointer = new Node(-1), *top1 = basePointer, *top2 = basePointer;
    while (userChoice == 0)
    {
        display(basePointer);
        cout << "1. Push stack 1" << endl
             << "2. Push stack 2" << endl
             << "3. Pop stack 1" << endl
             << "4. Pop stack 2" << endl
             << "5. exit" << endl
             << "Enter choice(1-5):";
        cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            cout << "Enter an element:";
            cin >> element;
            push1(top1, element);
            break;
        case 2:
            cout << "Enter an element:";
            cin >> element;
            push2(top2, element);
            break;
        case 3:
            pop1(basePointer, top1);
            break;
        case 4:
            pop2(basePointer, top2);
            break;
        case 5:
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