#include <bits/stdc++.h>
using namespace std;
class Car
{
    string model, year;
    double fuelLevel;
    int speed;
    bool isRunning;

public:
    Car(string model, string year)
    {
        this->model = model;
        this->year = year;
    }
    void startEngine()
    {
        isRunning = true;
        cout << "Car Started!!!";
    }
    void stopEngine()
    {
        isRunning = false;
        cout << "Car Stpped!!!";
    }
    void accelerate(int amount)
    {
        if (!isRunning)
        {
            cout << "Car is not started";
            return;
        }
        if (fuelLevel <= 0.0)
        {
            cout << "No fuel";
            return;
        }
        speed += amount;
    }
    void brake(int amount)
    {
        if (speed - amount < 0)
        {
            cout << "Can't apply more brake then applied accelaration";
            return;
        }
        speed -= amount;
    }
    void refuel(float amount)
    {
        fuelLevel += amount;
    }
    void printStatus()
    {
        cout << "Car" << endl
             << "--------" << endl
             << "model:" << model << endl
             << "Year:" << year << endl
             << "Speed:" << speed << endl
             << "Fuel:" << fuelLevel << endl
             << "is Running:" << isRunning << endl;
    }
};
int main()
{
    return 0;
}