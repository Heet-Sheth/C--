#include <iostream>
using namespace std;
int main()
{
    char arr[5] = "1234";
    void *ptr = arr;
    for (int i = 0; i < 5; i++)
        cout << i + char(ptr);
    cout << endl;
    return 0;
}