#include <iostream>
using namespace std;

class stringop
{
private:
    char str[100];

public:

    void getstring()
    {
        cout << "Enter a string: ";
      	cin.getline(str, 100);
    }

    void display()
    {
        cout << str;
    }

    // Prefix ++ operator to convert lowercase to uppercase
    stringop operator++()
    {
        int i = 0;

        while (str[i] != '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
            i++;
        }

        return *this;
    }

    // Postfix -- operator to convert uppercase to lowercase
    friend stringop operator--(stringop &s, int)
    {
        int i = 0;

        while (s.str[i] != '\0')
        {
            if (s.str[i] >= 'A' && s.str[i] <= 'Z')
            {
                s.str[i] = s.str[i] + 32;
            }
            i++;
        }

        return s;
    }
};

int main()
{
    stringop s1;

    s1.getstring();

    cout << "\nOutput for overloaded ++ prefix operator: ";
    ++s1;
    s1.display();

    cout << "\nOutput for overloaded -- postfix operator: ";
    s1--;
    s1.display();

    return 0;
}

