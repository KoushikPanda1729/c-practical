#include <iostream>
#include <string>

using namespace std;

// Base class Account
class Account {
protected:
    string customerName;
    int accountNumber;
    float balance;

public:
    // Constructor
    Account(const string& name, int number, float initialBalance)
        : customerName(name), accountNumber(number), balance(initialBalance) {}

    // Virtual functions to be overridden by derived classes
    virtual void deposit(float amount) = 0;
    virtual void displayBalance() const = 0;
    virtual void withdraw(float amount) = 0;
};

// Derived class SavingsAccount
class SavingsAccount : public Account {
private:
    float interestRate;

public:
    // Constructor
    SavingsAccount(const string& name, int number, float initialBalance, float rate)
        : Account(name, number, initialBalance), interestRate(rate) {}

    // Deposit function
    void deposit(float amount) override {
        balance += amount;
        cout << "Deposit of ₹" << amount << " successful." << endl;
    }

    // Display balance function
    void displayBalance() const override {
        cout << "Account Balance: ₹" << balance << endl;
    }

    // Withdraw function
    void withdraw(float amount) override {
        if (amount > balance) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of ₹" << amount << " successful." << endl;
        }
    }
};

// Derived class CurrentAccount
class CurrentAccount : public Account {
private:
    float minimumBalance;
    float serviceCharge;

public:
    // Constructor
    CurrentAccount(const string& name, int number, float initialBalance, float minBalance, float charge)
        : Account(name, number, initialBalance), minimumBalance(minBalance), serviceCharge(charge) {}

    // Deposit function
    void deposit(float amount) override {
        balance += amount;
        cout << "Deposit of ₹" << amount << " successful." << endl;
    }

    // Display balance function
    void displayBalance() const override {
        cout << "Account Balance: ₹" << balance << endl;
    }

    // Withdraw function
    void withdraw(float amount) override {
        if (amount > balance) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of ₹" << amount << " successful." << endl;
        }
    }

    // Function to check minimum balance and impose penalty if necessary
    void checkMinimumBalance() {
        if (balance < minimumBalance) {
            balance -= serviceCharge;
            cout << "Balance fell below minimum. Penalty of ₹" << serviceCharge << " imposed." << endl;
        }
    }
};

int main() {
    // Variables to store user input
    string name;
    int accountNumber;
    float initialBalance;

    // Prompt user to enter account details
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create objects of SavingsAccount and CurrentAccount classes with user input
    SavingsAccount savings(name, accountNumber, initialBalance, 4.5);
    CurrentAccount current(name, accountNumber, initialBalance, 2000, 50);

    // Variables to store deposit and withdrawal amounts
    float depositAmount, withdrawAmount;

    // Prompt user to deposit and display balance for savings account
    cout << "\nEnter deposit amount for Savings Account: ₹";
    cin >> depositAmount;
    savings.deposit(depositAmount);
    cout << "Savings Account Balance after deposit: ";
    savings.displayBalance();

    // Prompt user to withdraw and display balance for savings account
    cout << "\nEnter withdrawal amount for Savings Account: ₹";
    cin >> withdrawAmount;
    savings.withdraw(withdrawAmount);
    cout << "Savings Account Balance after withdrawal: ";
    savings.displayBalance();

    // Prompt user to deposit and display balance for current account
    cout << "\nEnter deposit amount for Current Account: ₹";
    cin >> depositAmount;
    current.deposit(depositAmount);
    cout << "Current Account Balance after deposit: ";
    current.displayBalance();

    // Prompt user to withdraw and display balance for current account
    cout << "\nEnter withdrawal amount for Current Account: ₹";
    cin >> withdrawAmount;
    current.withdraw(withdrawAmount);
    cout << "Current Account Balance after withdrawal: ";
    current.displayBalance();

    // Check minimum balance and display balance for current account
    current.checkMinimumBalance();
    cout << "Current Account Balance after minimum balance check: ";
    current.displayBalance();

    return 0;
}
