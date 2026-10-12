#include <iostream>
#include <string>
using namespace std;


// Base class
class Employee {
protected:
    int empId;
    string name;
    float salary;

public:
    void getEmployee() {
        cout << "\nEnter Employee ID: ";
        cin >> empId;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployee() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nSalary: " << salary;
    }
};


// Education class
class Education {
protected:
    string qualification;
    string specialization;

public:
    void getEducation() {
        cout << "\nEnter Qualification: ";
        cin >> qualification;

        cout << "Enter Specialization: ";
        cin >> specialization;
    }

    void displayEducation() {
        cout << "\nQualification: " << qualification;
        cout << "\nSpecialization: " << specialization;
    }
};


// Laborer derives from Employee
class Laborer : public Employee {
private:
    string skill;
    int workingHours;

public:
    void getLaborer() {
        getEmployee();

        cout << "\nEnter Skill: ";
        cin >> skill;

        cout << "Enter Working Hours: ";
        cin >> workingHours;
    }

    void displayLaborer() {
        displayEmployee();

        cout << "\nSkill: " << skill;
        cout << "\nWorking Hours: " << workingHours;
    }
};


// Scientist derives from Employee and Education
class Scientist : public Employee, public Education {
private:
    string researchArea;

public:
    void getScientist() {
        getEmployee();
        getEducation();

        cout << "\nEnter Research Area: ";
        cin >> researchArea;
    }

    void displayScientist() {
        displayEmployee();
        displayEducation();

        cout << "\nResearch Area: " << researchArea;
    }
};


// Manager derives from Employee and Education
class Manager : public Employee, public Education {
private:
    string department;
    int teamSize;

public:
    void getManager() {
        getEmployee();
        getEducation();

        cout << "\nEnter Department: ";
        cin >> department;

        cout << "Enter Team Size: ";
        cin >> teamSize;
    }

    void displayManager() {
        displayEmployee();
        displayEducation();

        cout << "\nDepartment: " << department;
        cout << "\nTeam Size: " << teamSize;
    }
};


int main() {

    int choice;

    Laborer l;
    Scientist s;
    Manager m;

    do {
        cout << "\n\n========== EMPLOYEE DATABASE ==========";
        cout << "\n1. Enter Laborer Details";
        cout << "\n2. Display Laborer Details";
        cout << "\n3. Enter Scientist Details";
        cout << "\n4. Display Scientist Details";
        cout << "\n5. Enter Manager Details";
        cout << "\n6. Display Manager Details";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            l.getLaborer();
            break;

        case 2:
            cout << "\n\n----- LABORER DETAILS -----";
            l.displayLaborer();
            break;

        case 3:
            s.getScientist();
            break;

        case 4:
            cout << "\n\n----- SCIENTIST DETAILS -----";
            s.displayScientist();
            break;

        case 5:
            m.getManager();
            break;

        case 6:
            cout << "\n\n----- MANAGER DETAILS -----";
            m.displayManager();
            break;

        case 7:
            cout << "\nExiting program...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 7);

    return 0;
}

