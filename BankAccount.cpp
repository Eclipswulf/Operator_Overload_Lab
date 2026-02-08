//
// Created by Dominic Moore on 2/8/2026.
//
#include "BankAccount.h"
#include <iostream>
#include <string>

BankAccount::BankAccount(std::string name, std::string accNum, double initBalance)
    : accountNumber(accNum), balance(initBalance) {
    accountHolder = new std::string(name);
}

BankAccount::~BankAccount() {
    delete accountHolder;
}

BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    balance = other.balance;
    accountHolder = new std::string(*(other.accountHolder));
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        delete accountHolder;
        accountNumber = other.accountNumber;
        balance = other.balance;
        accountHolder = new std::string(*(other.accountHolder));
    }
    return *this;
}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "You can't withdraw what you don't Have." << std::endl;
    }
    return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return this->accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return this->balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return this->balance > other.balance;
}

void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "Account Holder: " << *(account.accountHolder)
              << " | Account #: " << account.accountNumber
              << " | Balance: $" << account.balance << std::endl;
}

BankAccount BankAccount::createAccountFromInput() {
    std::string name, accNum;
    double bal;
    std::cout << "Please enter the account holder name.: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Please enter the account number.: ";
    std::cin >> accNum;
    std::cout << "Enter the Initial Balance: ";
    std::cin >> bal;
    return BankAccount(name, accNum, bal);
}