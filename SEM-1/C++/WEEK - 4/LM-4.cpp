#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:

    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex add(int s1, Complex s2)
    {
        Complex temp;
        temp.real = s1 + s2.real;
        temp.imag = s2.imag;
        return temp;
    }

    Complex add(Complex s1, Complex s2)
    {
        Complex temp;
        temp.real = s1.real + s2.real;
        temp.imag = s1.imag + s2.imag;
        return temp;
    }

    void display()
    {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(5, 7);
    Complex result;


    result = result.add(10, c1);

    cout << "Addition of integer and complex number: ";
    result.display();

    result = result.add(c1, c2);

    cout << "Addition of two complex numbers: ";
    result.display();

    return 0;
}

