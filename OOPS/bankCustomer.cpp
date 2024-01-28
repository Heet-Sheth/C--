#include <bits/stdc++.h>
using namespace std;
class Customer
{
    string name, accountNo, password;
    int balance;
    bool isAuthenticated;

public:
    Customer(string name, string accountNo, int balance, bool authentication = false)
    {
        this->accountNo = accountNo;
        this->balance = balance;
        this->name = name;
        isAuthenticated = authentication;
        if (authentication)
        {
            cout << "Enter a password to lock the account:";
            cin >> password;
        }
    }

    void deposit(int amount)
    {
        if (isAuthenticated)
        {
            cout << "Enter your password:";
            string password;
            cin >> password;
            if (this->password != password)
                throw "Invalid Password";
        }
        if (amount > 0)
        {
            balance += amount;
            cout << "Credited successfully" << endl;
        }
        else
            throw "Invalid Balance";
    }

    void withdraw(int amount)
    {
        if (isAuthenticated)
        {
            cout << "Enter your password:";
            string password;
            cin >> password;
            if (this->password != password)
                throw "Invalid Password";
        }
        if (amount < 0)
            throw "Can't withdraw negative amount";
        if (amount > balance)
            throw "Insufficient balance";
        balance -= amount;
        cout << "Debited successfully" << endl;
    }

    void transfer(int amount, Customer c)
    {
        if (isAuthenticated)
        {
            cout << "Enter your password:";
            string password;
            cin >> password;
            if (this->password != password)
                throw "Invalid Password";
        }
        if (amount < 0)
            throw "Can't transfer negative amount";
        if (amount > balance)
            throw "Insufficient balance";
        this->balance -= amount;
        c.balance += amount;
        cout << "Transfered successfully" << endl;
    }

    void printDetails()
    {
        if (isAuthenticated)
        {
            cout << "Enter your password:";
            string password;
            cin >> password;
            if (this->password != password)
                throw "Invalid Password";
        }
        cout << "Name:" << name << endl
             << "Account number:" << accountNo << endl
             << "Balance:" << balance << endl;
    }
};
int main()
{
    Customer c1("Heet", "123", 500, true), c2("Abc", "450", 1000, false);
    try
    {
        c1.deposit(1000);
        // c1.withdraw(-10);
        // c1.deposit(-50);
        c1.withdraw(300);
    }
    catch (const char *e)
    {
        std::cerr << e << endl;
    }

    return 0;
}