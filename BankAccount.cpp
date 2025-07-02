#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private: // Date Members of Class
    string depositorName;
    string accountNumber;
    string accountType;
    double balance;

public:
   BankAccount(string name, string accNumber, string accType, double initialBalance) // Constructor 
   {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }
   
    void deposit(double amount) // Amt Deposit Function
     {
        if (amount > 0) {
            balance += amount;
            cout<<"Deposited "<<amount<<". New balance:"<<balance;
        } else {
            cout<<"Deposit amount must be positive."<<endl;
        }
     }

    void withdraw(double amount) { // Amt Withdraw Function
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout<<"Withdrew "<<amount<<" New balance: "<<balance;
            } else {
                cout<<"Insufficient balance."<<endl;
            }
        } else {
            cout<<"Withdrawal amount must be positive."<<endl;
        }
    }

    
    void displayInfo() const // Output Display
   {
        cout<<"Depositor Name: "<<depositorName<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Type: "<<accountType<<endl;
        cout<<"Balance: Rs"<<balance<<endl;
    }
};

int main() {

    string name, accNumber, accType;
    double initialBalance;
    int choice;
    double amount;

    // User Input
    cout<<"Enter depositor name: ";
    getline(cin, name);

    cout<<"Enter account number: ";
    getline(cin, accNumber);

    cout<<"Enter account type: ";
    getline(cin, accType);

    cout<<"Enter initial balance: ";
    cin>>initialBalance;

    // Create bank account with user input
    BankAccount account(name, accNumber, accType, initialBalance);

    // Menu-driven 

    while (true) {

        cout<<"\n=== Bank Account ===\n";
        cout<<"1. Deposit Money\n";
        cout<<"2. Withdraw Money\n";
        cout<<"3. Display Account Info\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice (1-4): ";
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter amount to deposit: ";
            cin>>amount;
            account.deposit(amount);
        } 

        else if (choice == 2) {
            cout<<"Enter amount to withdraw: ";
            cin>>amount;
            account.withdraw(amount);
        } 

        else if (choice == 3) {
            cout<<"\nAccount Details:\n";
            account.displayInfo();
        } 

        else if (choice == 4) {
            cout<<"Exiting program. Thank you!\n";
            break;
        } 

        else {            
            cout<<"Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}