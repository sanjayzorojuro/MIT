#include <iostream>
using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;
    }

    void displayStudent() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
    }
};


// Derived class 1
class Exam : virtual public Student {
protected:
    int marks1, marks2, marks3;

public:
    void getExam() {
        cout << "\nEnter marks in Subject 1: ";
        cin >> marks1;

        cout << "Enter marks in Subject 2: ";
        cin >> marks2;

        cout << "Enter marks in Subject 3: ";
        cin >> marks3;
    }

    void displayExam() {
        cout << "\nSubject 1 Marks: " << marks1;
        cout << "\nSubject 2 Marks: " << marks2;
        cout << "\nSubject 3 Marks: " << marks3;
    }
};


// Derived class 2
class Sports : virtual public Student {
protected:
    int sportsMarks;

public:
    void getSports() {
        cout << "\nEnter Sports Marks: ";
        cin >> sportsMarks;
    }

    void displaySports() {
        cout << "\nSports Marks: " << sportsMarks;
    }
};


// Derived class from Exam and Sports
class Result : public Exam, public Sports {
private:
    int total;

public:
    void calculate() {
        total = marks1 + marks2 + marks3 + sportsMarks;
    }

    void displayResult() {
        displayStudent();
        displayExam();
        displaySports();

        cout << "\nTotal Marks: " << total;
    }
};


int main() {

    Result r;

    cout << "----- Enter Student Details -----\n";
    r.getStudent();

    cout << "\n----- Enter Exam Details -----\n";
    r.getExam();

    cout << "\n----- Enter Sports Details -----\n";
    r.getSports();

    r.calculate();

    cout << "\n\n===== STUDENT RESULT =====";
    r.displayResult();

    return 0;
}

