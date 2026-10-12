#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int code;

public:
    void createEmployee() {
        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Employee Code: ";
        cin >> code;
    }

    void updateEmployee() {
        cout << "\nEnter New Employee Name: ";
        cin >> name;

        cout << "Enter New Employee Code: ";
        cin >> code;
    }

    void displayEmployee() {
        cout << "\nName: " << name;
        cout << "\nCode: " << code;
    }
};


// Account derives virtually from Employee
class Account : virtual public Employee {
protected:
    float pay;

public:
    void createAccount() {
        cout << "Enter Pay: ";
        cin >> pay;
    }

    void updateAccount() {
        cout << "\nEnter New Pay: ";
        cin >> pay;
    }

    void displayAccount() {
        cout << "\nPay: " << pay;
    }
};


// Admin derives virtually from Employee
class Admin : virtual public Employee {
protected:
    int experience;

public:
    void createAdmin() {
        cout << "Enter Experience (years): ";
        cin >> experience;
    }

    void updateAdmin() {
        cout << "\nEnter New Experience: ";
        cin >> experience;
    }

    void displayAdmin() {
        cout << "\nExperience: " << experience << " years";
    }
};


// Master derives from Account and Admin
class Master : public Account, public Admin {
public:
    void create() {
        createEmployee();
        createAccount();
        createAdmin();
    }

    void update() {
        updateEmployee();
        updateAccount();
        updateAdmin();
    }

    void display() {
        cout << "\n\n===== MASTER EMPLOYEE DETAILS =====";
        displayEmployee();
        displayAccount();
        displayAdmin();
    }
};


int main() {

    Master m;

    // Create
    cout << "===== CREATE MASTER OBJECT =====\n";
    m.create();

    // Display
    cout << "\n\n===== BEFORE UPDATE =====";
    m.display();

    // Update
    cout << "\n\n===== UPDATE MASTER OBJECT =====\n";
    m.update();

    // Display updated information
    cout << "\n\n===== AFTER UPDATE =====";
    m.display();

    return 0;
}
