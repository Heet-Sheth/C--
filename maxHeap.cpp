#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class maxHeap
{
private:
    struct node
    {
        int data;
        node *next;
        node(int key)
        {
            data = key;
            next = NULL;
        }
    };
    node *headTop;
    int size = 0;

public:
    maxHeap()
    {
        headTop = new node(-1);
    }
    void push(int data)
    {
        size++;
        if (headTop->data <= data)
        {
            node *root = new node(data);
            root->next = headTop;
            headTop = root;
            return;
        }
        node *root = headTop, *pre = NULL;
        while (root->data > data)
        {
            pre = root;
            root = root->next;
        }
        pre->next = new node(data);
        pre->next->next = root;
    }
    int pop()
    {
        int x = -1;
        if (headTop->data != -1)
        {
            x = headTop->data;
            size--;
            headTop = headTop->next;
        }
        return x;
    }
    int sizeOfHead()
    {
        if (size <= 0)
            return 0;
        else
            return size;
    }
    bool isEmpty()
    {
        return size <= 0;
    }
    int top()
    {
        return headTop->data;
    }
};
int main()
{
    bool choice = true;
    maxHeap ob;
    while (choice)
    {
        cout << "Enter\n1. push\n2. pop\n3. size\n4. empty\n5 size:\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            int n;
            cout << "enter a no.";
            cin >> n;
            ob.push(n);
            cout << endl;
            break;
        case 2:
            cout << ob.pop();
            cout << endl;
            break;
        case 3:
            cout << "is empty?" << ob.isEmpty();
            cout << endl;
            break;
        case 4:
            cout << "size:" << ob.sizeOfHead();
            cout << endl;
            break;
        case 5:
            cout << ob.top() << endl;
            break;
        case 6:
            cout << "Exit";
            choice = false;
            cout << endl;
            break;

        default:
            break;
        }
    }
}