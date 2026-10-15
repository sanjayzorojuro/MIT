#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ofstream fout("multiline.txt");
    string line;
    int characters = 0;
    int letters = 0;
    int digits = 0;
    int lines = 0;
    int spaces = 0;
    char ch;

    cout << "Enter text (type END on a new line to finish):\n";

    while (true) {
        getline(cin, line);

        if (line == "END")
            break;

        fout << line << '\n';
    }

    fout.close();

    ifstream fin("multiline.txt");

    while (fin.get(ch)) {
        characters++;

        if (isalpha(ch))
            letters++;

        if (isdigit(ch))
            digits++;

        if (ch == ' ')
            spaces++;

        if (ch == '\n')
            lines++;
    }

    fin.close();

    cout << "\n--- FILE STATISTICS ---\n";
    cout << "Total characters: " << characters << '\n';
    cout << "Total alphabet letters: " << letters << '\n';
    cout << "Total digits: " << digits << '\n';
    cout << "Total lines: " << lines << '\n';
    cout << "Total spaces: " << spaces << '\n';

    return 0;
}
