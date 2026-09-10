#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string custname;
    int accno;
    char accType;
    float bal;

public:
	//constructor
    BankAccount(string name, int accNo, char type)
    {
        custname = name;
        accno = accNo;
        accType = type;
        bal = 500;
    }

    // function to deposite money
    void deposit(float amt)
    {
        bal += amt;
        cout<<"Rs. "<<amt<<" deposited successfully.\n";
    }

    // Friend function declaration
    friend void withdraw(BankAccount &account, float amt);

    // Function to display account details
    void display()
    {
        cout<<"\n--- Account Details ---\n";
        cout<<"Customer Name : " <<custname<<endl;
        cout<<"Account Number : " <<accno<<endl;
        cout<<"Account Type : " <<accType<<endl;
        cout<<"Balance : Rs. "<<bal<<endl;
    } 
};

// Friend function to withdraw money
void withdraw(BankAccount &account, float amt)
{
    if (amt <= account.bal)
    {
        account.bal -= amt;
        cout<<"Rs. "<<amt<<" withdrawn successfully.\n";
    }
    else
    {
        cout<<"Insufficient balance!\n";
    }
}

int main()
{
    BankAccount a1("Adithya", 101, 'S');
    BankAccount a2("Nishan", 102, 'C');

    a1.deposit(1000);
    withdraw(a1, 300);
    a1.display();
	cout<<"--------------------------------------------"<<endl;
    a2.deposit(2000);
    withdraw(a2, 1000);
    a2.display();

    return 0;
}

