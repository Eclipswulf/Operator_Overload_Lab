//
// Created by Dominic Moore on 2/8/2026.
//

#ifndef N_BANKACCOUNT_H
#define N_BANKACCOUNT_H

#include <string>
#include <iostream>

class BankAccount {
private:
    std::string* accountHolder;
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string name, std::string accNum, double initBalance);
    ~BankAccount();
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);


     BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;
static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
    double getBalance() const { return balance; }
    std::string getHolder() const { return *accountHolder; }
};
#endif //N_BANKACCOUNT_H