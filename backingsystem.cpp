#include <iostream>
#include <vector>
using namespace std;
class Customer {
    string name, address;
    int customerID;

public:
    Customer(string name, string address, int id) : name(name), address(address), customerID(id) {}

    void displayCustomerInfo() {
        cout << "Customer ID: " << customerID << "\nName: " << name << "\nAddress: " << address << endl;
    }
};

// Account Class
class Account {
    int accountNumber;
    double balance;
    string accountType;

public:
    Account(int accNum, string type) : accountNumber(accNum), accountType(type), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account. Current balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn " << amount << ". Current balance: " << balance << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << "\nAccount Type: " << accountType << "\nBalance: " << balance << endl;
    }
};

// Transaction Class
class Transaction {
    int transactionID;
    double amount;
    string transactionType;

public:
    Transaction(int id, double amount, string type) : transactionID(id), amount(amount), transactionType(type) {}

    void displayTransaction() {
        cout << "Transaction ID: " << transactionID << "\nAmount: " << amount << "\nType: " << transactionType << endl;
    }
};


class BankingServices {
public:
    static void transferFunds(Account &from, Account &to, double amount) {
        if (from.getBalance() >= amount) {  // Using the getter method
            from.withdraw(amount);
            to.deposit(amount);
            cout << "Transfer successful!" << endl;
        } else {
            cout << "Insufficient balance for transfer!" << endl;
        }
    }
};
int main() {
    Customer customer1("John Doe", "123 Main St", 1);
    Account account1(1001, "Savings");
    Account account2(1002, "Current");

    customer1.displayCustomerInfo();
    account1.deposit(500);
    account1.withdraw(100);
    account1.displayAccountInfo();

    // Transfer Example
    BankingServices::transferFunds(account1, account2, 200);

    return 0;
}
