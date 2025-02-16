/*
Create a class for a bank account with methods for deposit, withdrawal, and balance inquiry.
The deposit method should add the amount to the balance.
The withdrawal method should deduct the amount from the balance.
The balance inquiry method should return the current balance.
*/

#include <iostream>
using namespace std;

class BankAccount
{
public:
    double balance = 0.0;
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds" << endl;
            return;
        }
        balance -= amount;
    }
    double getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount account;
    account.deposit(1000.0);
    account.withdraw(500.0);
    cout << "Current balance: $" << account.getBalance() << endl;
    return 0;
}
