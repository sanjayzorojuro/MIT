//program to find the remaning balance and thn display the amount to be paid back.

#include <iostream>
using namespace std;

int main() {
    int bill, paid, bal;

    cout << "Enter the total bill and cash paid: ";
    cin >> bill >> paid;

    bal = paid - bill;

    if (bal < 0) {
        cout << "Insufficient amount paid.";
        return 0;
    }

    int note500 = bal / 500;
    bal %= 500;

    int note200 = bal / 200;
    bal %= 200;

    int note100 = bal / 100;
    bal %= 100;

    int note50 = bal / 50;
    bal %= 50;

    int note20 = bal / 20;
    bal %= 20;

    int note10 = bal / 10;
    bal %= 10;

    int coins = bal;

    if (paid == bill) {
        cout << "No amount to be paid.";
    } else {
        cout << "Total payable:\n";
        cout << "500: " << note500 << '\n';
        cout << "200: " << note200 << '\n';
        cout << "100: " << note100 << '\n';
        cout << "50: " << note50 << '\n';
        cout << "20: " << note20 << '\n';
        cout << "10: " << note10 << '\n';
        cout << "Coins: " << coins << '\n';
    }

    return 0;
}