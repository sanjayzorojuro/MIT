#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Employee {
    int id;
    char name[50];
    char department[30];
    char designation[30];
    float basic;
};

int main() {
    int choice, id;
    Employee e;

    do {
        cout << "\n1. Add Employee\n";
        cout << "2. Generate Salary Slip\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Generate ID automatically
  			int newID = 1;

			ifstream fin("employee.dat", ios::binary);

			if (fin) {
    			fin.seekg(0, ios::end);
    			streampos size = fin.tellg();

    			if (size >= 0) {
        			newID = static_cast<int>(size / sizeof(Employee)) + 1;
    			}

    			fin.close();
			}

			e.id = newID;

            cout << "Employee ID: " << e.id << '\n';

            cout << "Enter name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(e.name, 50);

            cout << "Enter department: ";
            cin.getline(e.department, 30);

            cout << "Enter designation: ";
            cin.getline(e.designation, 30);

            cout << "Enter basic salary: ";
            cin >> e.basic;

            ofstream fout("employee.dat",
                          ios::binary | ios::app);
            fout.write((char*)&e, sizeof(e));
            fout.close();

            cout << "Employee record saved.\n";
        }

        else if (choice == 2) {
            cout << "Enter employee ID: ";
            cin >> id;

            ifstream fin("employee.dat", ios::binary);

            // Directly access the required record
            fin.seekg((id - 1) * sizeof(Employee), ios::beg);
            fin.read((char*)&e, sizeof(e));

            if (!fin || id <= 0 || e.id != id) {
                cout << "Employee not found.\n";
            }
            else {
                float da = e.basic * 0.20;
                float hra = e.basic * 0.10;
                float gross = e.basic + da + hra;
                float tax = gross * 0.05;
                float net = gross - tax;

                cout << "\n------ SALARY SLIP ------\n";
                cout << "Employee ID : " << e.id << '\n';
                cout << "Name        : " << e.name << '\n';
                cout << "Department  : " << e.department << '\n';
                cout << "Designation : " << e.designation << '\n';
                cout << fixed << setprecision(2);
                cout << "Basic Salary: " << e.basic << '\n';
                cout << "DA          : " << da << '\n';
                cout << "HRA         : " << hra << '\n';
                cout << "Gross Pay   : " << gross << '\n';
                cout << "Income Tax  : " << tax << '\n';
                cout << "Net Pay     : " << net << '\n';
                cout << "-------------------------\n";
            }

            fin.close();
        }

        else if (choice == 3) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}

