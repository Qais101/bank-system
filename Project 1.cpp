#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);
bool authenticate();

int main() {
    cout << "Welcome to Secure Bank" << endl;
    cout << "Please authenticate to continue." << endl;

    if (!authenticate()) {
        cout << "Access denied, Exiting program." << endl;
        return 0;
    }

    double balance = 0.0;
    int choice = 0;

    do {
        cout << "\n--- Bank Menu ---" << endl;
        cout << "1. Show Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            cout << "Thanks for visiting the bank!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select 1-4." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

bool authenticate() {
    const string correctPIN = "1234";
    string enteredPIN;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == correctPIN) {
            cout << "Access granted." << endl;
            return true;
        }
        else {
            attempts--;
            cout << "Incorrect PIN. Attempts Left: " << attempts << endl;
        }
    }
    return false;
}

void showBalance(double balance) {
    cout << "Your balance is: $" << fixed << setprecision(2) << balance << endl;
}

double deposit() {
    double amount = 0;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Deposit amount must be greater than zero." << endl;
        return 0;
    }
    return amount;
}

double withdraw(double balance) {
    double amount = 0;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
        return 0;
    }
    else if (amount > balance) {
        cout << "Insufficient funds." << endl;
        return 0;
    }
    return amount;
}
