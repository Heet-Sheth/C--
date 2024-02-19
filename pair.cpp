#include <iostream>
#include <utility>
using namespace std;
int main()
{
    pair<int, int> pair1(3, 4);
    pair<int, int> pair2(3, 4);

    cout << (pair1 >= pair2);
    return 0;
}