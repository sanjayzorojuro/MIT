#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    int choice;
    char ch;
    int count = 0;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Create a text file\n";
        cout << "2. Convert case of letters\n";
        cout << "3. Display file contents\n";
        cout << "4. Count occurrences of 'a'\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                ofstream fout("text.txt");
                string text;

                cout << "Enter a single line of text: ";
                cin.ignore();   //used to remove the leftover from the buffer (in this from the choice \n
                getline(cin, text);

                fout << text;
                fout.close();

                cout << "File created successfully.\n";
                break;
            }

            case 2: {
                ifstream fin("text.txt");
                ofstream fout("temp.txt");
                bool found = false;

                if (!fin || !fout) {
                    cout << "Error opening file.\n";
                    break;
                }

                while (fin.get(ch)) {
                    found = true;

                    if (islower(ch))
                        ch = toupper(ch);
                    else if (isupper(ch))
                        ch = tolower(ch);

                    fout.put(ch);
                }

                fin.close();
                fout.close();

                if (!found) {
                    cout << "File is empty or does not exist.\n";
                    remove("temp.txt");
                    break;
                }

                remove("text.txt");
                rename("temp.txt", "text.txt");

                cout << "Case converted successfully.\n";
                break;
            }

            case 3: {
                ifstream fin("text.txt");

                if (!fin) {
                    cout << "File does not exist.\n";
                    break;
                }

                cout << "File contents:\n";
                while (fin.get(ch))
                    cout << ch;

                cout << '\n';
                fin.close();
                break;
            }

            case 4: {
                ifstream fin("text.txt");

                if (!fin) {
                    cout << "File does not exist.\n";
                    break;
                }

                count = 0;

                while (fin.get(ch)) {
                    if (ch == 'a' || ch == 'A')
                        count++;
                }

                cout << "Number of occurrences of 'a' (case-insensitive): "
                     << count << '\n';

                fin.close();
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
