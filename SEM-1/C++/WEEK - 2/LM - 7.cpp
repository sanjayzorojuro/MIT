#include <iostream>
using namespace std;

struct BankAccount {
    string customerName;
    int accountNumber;
    string accountType;
    float balance;
};

void deposit(BankAccount &account, float amount) {
    account.balance += amount;
    cout << "Amount deposited successfully.\n";
    cout << "Current balance: " << account.balance << endl;
}

void withdraw(BankAccount &account, float amount) {
    if (amount <= account.balance) {
        account.balance -= amount;
        cout << "Amount withdrawn successfully.\n";
        cout << "Current balance: " << account.balance << endl;
    } 
    else {
        cout << "Insufficient balance.\n";
    }
}

int main() {
    BankAccount account;

    cout << "Enter customer name: ";
    cin >> account.customerName;

    cout << "Enter account number: ";
    cin >> account.accountNumber;

    cout << "Enter account type (Savings/Fixed/Current): ";
    cin >> account.accountType;

    cout << "Enter balance amount: ";
    cin >> account.balance;

    float amount;

    // Deposit
    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    deposit(account, amount);

    // Withdrawal
    cout << "\nEnter amount to withdraw: ";
    cin >> amount;
    withdraw(account, amount);

    return 0;
}