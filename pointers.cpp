#include <iostream>
using namespace std;
int main()
{
    char arr[] = "Heet", x = 'c';
    string str = "Heet";
    cout << &arr << "," << (void *)&x << "," << &str << endl;
    return 0;
}