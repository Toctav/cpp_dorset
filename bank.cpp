#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNo, string name, double initialDeposit)
        : accountNumber(accNo), accountHolder(name), balance(initialDeposit) {}

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Your new balance is " << fixed << setprecision(2) << balance << "EUR" << endl;
        } else {
            cout << "Oops! That doesn't seem like a valid deposit amount" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Your remaining balance is " << fixed << setprecision(2) << balance << "EUR" << endl;
            return true;
        } else {
            cout << "Sorry, you don't have enough funds or the amount is invalid!" << endl;
            return false;
        }
    }

    void displayAccount() const {
        cout << "Account Number: " << accountNumber << " | Holder: " << accountHolder
             << " | Balance: " << fixed << setprecision(2) << balance << "EUR" << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    bool createAccount(int accNo, string name, double initialDeposit) {
        if (accNo < 0) {
            cout << "Account number cannot be negative! Please enter a valid number" << endl;
            return false;
        }
        if (findAccount(accNo) != nullptr) {
            cout << "Oops! This account number already exists. Try another one" << endl;
            return false;
        }
        accounts.push_back(Account(accNo, name, initialDeposit));
        cout << "Great! Your account has been created successfully" << endl;
        return true;
    }

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo)
                return &acc;
        }
        return nullptr;
    }

    void depositMoney(int accNo, double amount) {
        Account* acc = findAccount(accNo);
        if (acc) {
            acc->deposit(amount);
        } else {
            cout << "Oops! We couldn't find an account with that number" << endl;
        }
    }

    void withdrawMoney(int accNo, double amount) {
        Account* acc = findAccount(accNo);
        if (acc) {
            acc->withdraw(amount);
        } else {
            cout << "That account doesn't seem to exist" << endl;
        }
    }

    void transferMoney(int fromAccNo, int toAccNo, double amount) {
        if (fromAccNo == toAccNo) {
            cout << "You can't transfer money to the same account!" << endl;
            return;
        }
        Account* fromAcc = findAccount(fromAccNo);
        Account* toAcc = findAccount(toAccNo);
        if (fromAcc && toAcc) {
            if (fromAcc->withdraw(amount)) {
                toAcc->deposit(amount);
                cout << "Transfer completed successfully!" << endl;
            }
        } else {
            cout << "One or both accounts were not found" << endl;
        }
    }

    void displayAllAccounts() {
        cout << "\nHere are all the accounts in the bank:" << endl;
        for (const auto& acc : accounts) {
            acc.displayAccount();
        }
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template <typename T>
void getValidInput(T& input, const string& prompt) {
    while (true) {
        cout << prompt;
        if (cin >> input) {
            break;
        } else {
            cout << "That doesn't seem right. Please enter a valid value" << endl;
            clearInput();
        }
    }
}

int main() {
    Bank bank;
    int choice;
    while (true) {
        cout << "\nWhat would you like to do today?" << endl;
        cout << "1. Open a new account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Transfer money" << endl;
        cout << "5. Show all accounts" << endl;
        cout << "6. Exit" << endl;
        getValidInput(choice, "Enter your choice: ");

        if (choice == 6) break;

        int accNo, toAccNo;
        string name;
        double amount;

        switch (choice) {
            case 1:
                getValidInput(accNo, "Enter a new account number: ");
                cout << "Enter the account holder's name: ";
                cin.ignore();
                getline(cin, name);
                getValidInput(amount, "How much would you like to deposit initially? ");
                bank.createAccount(accNo, name, amount);
                break;
            case 2:
                getValidInput(accNo, "Enter your account number: ");
                getValidInput(amount, "How much do you want to deposit? ");
                bank.depositMoney(accNo, amount);
                break;
            case 3:
                getValidInput(accNo, "Enter your account number: ");
                getValidInput(amount, "How much do you want to withdraw? ");
                bank.withdrawMoney(accNo, amount);
                break;
            case 4:
                getValidInput(accNo, "Enter your account number: ");
                getValidInput(toAccNo, "Enter the recipient's account number: ");
                getValidInput(amount, "How much do you want to transfer? ");
                bank.transferMoney(accNo, toAccNo, amount);
                break;
            case 5:
                bank.displayAllAccounts();
                break;
            default:
                cout << "That doesn't seem like a valid choice. Try again!" << endl;
        }
    }
    cout << "Thank you for using our banking system! Have a great day!" << endl;
    return 0;
}
