#include <iostream>
using namespace std;
class a
{
protected:
    string name;
};
class b : protected a
{
protected:
    int x;
};
class c : protected b
{
protected:
    int y;
};
class d : protected c
{
private:
    int z;

public:
    d(int a, int b, int c, string d)
    {
        name = d;
        x = a;
        y = b;
        z = c;
    }
    ~d()
    {
        cout << "Values are:" << x << "," << y << "," << z << "," << name << endl;
    }
};
int main()
{
    d d1(5, 10, 15, "heet");
    return 0;
}