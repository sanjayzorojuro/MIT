#include <iostream>
using namespace std;

class person
{
protected:
    int id;
    string name;

public:
    void accept()
    {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;
    }

    void display()
    {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
    }
};


class teaching : public person
{
private:
    string subject;

public:
    void accept()
    {
        person::accept();

        cout << "Enter Subject: ";
        cin >> subject;
    }

    void display()
    {
        person::display();

        cout << "\nSubject: " << subject;
    }
};


class nonteaching : public person
{
private:
    string dept;

public:
    void accept()
    {
        person::accept();

        cout << "Enter Department: ";
        cin >> dept;
    }

    void display()
    {
        person::display();

        cout << "\nDepartment: " << dept;
    }
};


class instructor : public person
{
    // Instructor has only id and name
};


int main()
{
 // Objects of all classes
    person p;
    teaching t;
    nonteaching nt;

    int n;

    cout << "===== PERSON =====\n";
    p.accept();

    cout << "\n===== TEACHING =====\n";
    t.accept();

    cout << "\n===== NON-TEACHING =====\n";
    nt.accept();


    // n instructor objects
    cout << "\n\nEnter number of instructors: ";
    cin >> n;

    instructor inst[n];

    // Accept instructor details
    for(int i = 0; i < n; i++)
    {
        cout << "\n--- Enter Instructor " << i + 1 << " Details ---\n";
        inst[i].accept();
    }


    // Display person
    cout << "\n\n===== PERSON DETAILS =====";
    p.display();


    // Display teaching
    cout << "\n\n===== TEACHING DETAILS =====";
    t.display();


    // Display non-teaching
    cout << "\n\n===== NON-TEACHING DETAILS =====";
    nt.display();


    // Display instructors
    cout << "\n\n===== INSTRUCTOR DETAILS =====";

    for(int i = 0; i < n; i++)
    {
        cout << "\n\n--- Instructor " << i + 1 << " ---";
        inst[i].display();
    }

    return 0;
}

