// BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance; // Keep balance private for encapsulation

public:
    // Constructor
    BankAccount();

    // Method to deposit money
    void deposit(double amount);

    // Method to withdraw money
    void withdraw(double amount);

    // Method to get the balance
    double getBalance() const;
};

#endif // BANKACCOUNT_H
