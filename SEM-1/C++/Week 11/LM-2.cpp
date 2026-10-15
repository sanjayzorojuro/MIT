#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct Item {
    int code;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, code;
    Item item;

    do {
        cout << "\n1. Add New Item\n";
        cout << "2. Modify Existing Item\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Generate item code automatically
      		int newCode = 1;

			ifstream fin("items.dat", ios::binary);

			if (fin) {
    			fin.seekg(0, ios::end);
    			streampos size = fin.tellg();

   				if (size >= 0) {
        			newCode = static_cast<int>(size / sizeof(Item)) + 1;
    			}

    			fin.close();
			}
            item.code = newCode;

            cout << "Item Code: " << item.code << '\n';

            cout << "Enter item name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(item.name, 50);

            cout << "Enter unit price: ";
            cin >> item.price;

            cout << "Enter quantity: ";
            cin >> item.quantity;

            ofstream fout("items.dat",
                          ios::binary | ios::app);
            fout.write((char*)&item, sizeof(item));
            fout.close();

            cout << "Item added successfully.\n";
        }

        else if (choice == 2) {
            cout << "Enter item code to modify: ";
            cin >> code;

            fstream file("items.dat",
                         ios::in | ios::out | ios::binary);

            if (!file) {
                cout << "Item database does not exist.\n";
                continue;
            }

            // Directly access the required record
            file.seekg((code - 1) * sizeof(Item), ios::beg);
            file.read((char*)&item, sizeof(item));

            if (!file || code <= 0 || item.code != code) {
                cout << "Item not found.\n";
                file.close();
                continue;
            }

            cout << "Current item: " << item.name << '\n';
            cout << "Enter new item name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(item.name, 50);

            cout << "Enter new unit price: ";
            cin >> item.price;

            cout << "Enter new quantity: ";
            cin >> item.quantity;

            // Move back to the beginning of this record
            file.clear();
            file.seekp((code - 1) * sizeof(Item), ios::beg);
            file.write((char*)&item, sizeof(item));
            file.close();

            cout << "Item modified successfully.\n";
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
