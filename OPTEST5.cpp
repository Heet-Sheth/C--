#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A() : x(-1) { cout << "default constructer" << endl; }
    A(int x) : x(x) { cout << "A called for " << x << endl; }
    ~A() { cout << "A destroyed for " << x << endl; }
};

class B : public virtual A
{
public:
    B(int x) : A(x) { cout << "B called for " << x << endl; }
    ~B() { cout << "B destroyed " << endl; }
};

class C : public virtual A
{
public:
    C(int x) : A(69) { cout << "C called" << endl; }
    ~C() { cout << "C destriyed" << endl; }
};

class D : public B, public C
{
public:
    D(int x) : B(x), C(x + 5){};
};

int main()
{
    D d(56);
    return 0;
}
