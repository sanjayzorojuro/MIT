#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    int emp_code;
    string emp_name;

public:
    void getEmployee() {
        cout << "Enter Employee Code: ";
        cin >> emp_code;

        cout << "Enter Employee Name: ";
        cin >> emp_name;
    }

    void displayEmployee() {
        cout << "\nEmployee Code: " << emp_code;
        cout << "\nEmployee Name: " << emp_name;
    }
};


// Derived class from Employee
class Faculty : public Employee {
protected:
    string qualification;
    int experience;

public:
    void getFaculty() {
        cout << "Enter Qualification: ";
        cin >> qualification;

        cout << "Enter Years of Experience: ";
        cin >> experience;
    }

    void displayFaculty() {
        displayEmployee();
        cout << "\nQualification: " << qualification;
        cout << "\nYears of Experience: " << experience;
    }
};


// Derived class from Employee
class NonTeaching : public Employee {
private:
    string grade;

public:
    void getNonTeaching() {
        cout << "Enter Grade: ";
        cin >> grade;
    }

    void displayNonTeaching() {
        displayEmployee();
        cout << "\nGrade: " << grade;
    }
};


// Derived class from Faculty
class Permanent : public Faculty {
private:
    float basicPay;
    float academicAllowance;

public:
    void getPermanent() {
        cout << "Enter Basic Pay: ";
        cin >> basicPay;

        cout << "Enter Academic Allowance: ";
        cin >> academicAllowance;
    }

    void displayPermanent() {
        displayFaculty();
        cout << "\nBasic Pay: " << basicPay;
        cout << "\nAcademic Allowance: " << academicAllowance;
    }
};


// Derived class from Faculty
class Contract : public Faculty {
private:
    int probationYears;

public:
    void getContract() {
        cout << "Enter Probation Years: ";
        cin >> probationYears;
    }

    void displayContract() {
        displayFaculty();
        cout << "\nProbation Years: " << probationYears;
    }
};


int main() {

    // Permanent Faculty
    Permanent p;

    cout << "\n--- Enter Permanent Faculty Details ---\n";
    p.getEmployee();
    p.getFaculty();
    p.getPermanent();

    cout << "\n\n--- Permanent Faculty Details ---";
    p.displayPermanent();


    // Contract Faculty
    Contract c;

    cout << "\n\n--- Enter Contract Faculty Details ---\n";
    c.getEmployee();
    c.getFaculty();
    c.getContract();

    cout << "\n\n--- Contract Faculty Details ---";
    c.displayContract();


    // Non-teaching Employee
    NonTeaching n;

    cout << "\n\n--- Enter Non-Teaching Employee Details ---\n";
    n.getEmployee();
    n.getNonTeaching();

    cout << "\n\n--- Non-Teaching Employee Details ---";
    n.displayNonTeaching();

    return 0;
}

