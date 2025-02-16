// BankAccount.cpp
#include "BankAccount.h"

// Constructor initializes balance to 0.0
BankAccount::BankAccount() : balance(0.0) {}

// Method to deposit money
void BankAccount::deposit(double amount)
{
    balance += amount;
}

// Method to withdraw money (with insufficient funds check)
void BankAccount::withdraw(double amount)
{
    if (amount > balance)
    {
        cout << "Insufficient funds" << endl;
        return;
    }
    balance -= amount;
}

// Method to get the current balance
double BankAccount::getBalance() const
{
    return balance;
}
