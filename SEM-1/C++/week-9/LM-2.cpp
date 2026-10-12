#include <iostream>
using namespace std;

// Base class
class Shape
{
protected:
    double x, y;

public:
    void get_data()
    {
        cout << "Enter first value: ";
        cin >> x;

        cout << "Enter second value: ";
        cin >> y;
    }

    virtual void display_area()
    {
        cout << "Area of Shape = " << x * y;
    }
};


// Derived class: Triangle
class Triangle : public Shape
{
public:
    void display_area()
    {
        cout << "Area of Triangle = " << 0.5 * x * y;
    }
};


// Derived class: Rectangle
class Rectangle : public Shape
{
public:
    void display_area()
    {
        cout << "Area of Rectangle = " << x * y;
    }
};


int main()
{
    Triangle t;
    Rectangle r;

    cout << "\n--- Triangle ---\n";
    t.get_data();
    t.display_area();

    cout << "\n\n--- Rectangle ---\n";
    r.get_data();
    r.display_area();

    return 0;
}
