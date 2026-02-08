#include <iostream>
#include <vector>
#include "BankAccount.h"

void printMenu() {
    std::cout << "\n--- Welcome to the bank of Eclipsia! What would you like to do? ---\n"
              << "1. Create an Account (Static)\n"
              << "2. Print your Account (Static)\n"
              << "3. Make a Deposit (+=)\n"
              << "4. Make a Withdraw (-=)\n"
              << "5. Compare Balances between Accounts (<, >)\n"
              << "6. Exit\n"
              << "Choice: ";
}
int main() {
    std::vector<BankAccount> accounts;
    int choice;

    accounts.push_back(BankAccount("Lady Odelia", "5202", 428.0));
    \
do {
    printMenu();
    switch (choice) {
            case 1:
                accounts.push_back(BankAccount::createAccountFromInput());
                break;
            case 2:
                for(const auto& acc : accounts) BankAccount::printAccount(acc);
                break;
            case 3: {
                double amt;
                std::cout << "How much do you wish to deposit?: ";
                std::cin >> amt;
                accounts[0] += amt;
                break;
            }
            case 4: {
                double amt;
                std::cout << "How much do you wish to withdraw?: ";
                std::cin >> amt;
                accounts[0] -= amt;
                break;
            }
            case 5:
                if (accounts.size() >= 2) {
                    if (accounts[0] < accounts[1]) std::cout << "Acc 1 has less.\n";
                    if (accounts[0] > accounts[1]) std::cout << "Acc 1 has more.\n";
                    if (accounts[0] == accounts[1]) std::cout << "Same account.\n";
                } else std::cout << "Need at least 2 accounts.\n";
                break;
            case 6: std::cout << "Farewell...\n"; break;
            default: std::cout << "I cannot assist you with that. Please try again.\n";
}
} while (choice !=6);
    return 0;
    }