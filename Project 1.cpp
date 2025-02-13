#include <iostream>
#include <iomanip>
using namespace std;
void showBalance(double balance);
double deposit();
double withdraw(double balance);



int main() {
    int balance = 0;
    int choice = 0;

    do {
        std::cout << "Welcome to the bank" << std::endl;
        std::cout << "Please enter your choice" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice) {
        case 1:showBalance(balance);
            break;
        case 2:balance += deposit();
            showBalance(balance);
            break;
        case 3:balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:std::cout << "thanks for visiting the bank" << std::endl;
            break;
        default:std::cout << "Invalid choice" << std::endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
void showBalance(double balance) {
    std::cout << "your balance is : " << fixed << setprecision(2) << balance << "$" << std::endl;
}
double deposit() {
   double amount = 0;
   std::cout << "Enter the amount to be deposited" << std::endl;
   std::cin >> amount;
   if (amount > 0)
   {
       return amount;
   }
   else {
       std::cout << "not a valid amount." << std::endl;
       return 0;
   }
}
double withdraw(double balance) {
    double amount = 0;

    std::cout << "Enter the amount to be withdrawn :";
    std::cin >> amount;
    if (amount > balance)
    {
        std::cout << "insufficient funds" << std::endl;
        return 0;
    }
    else if (amount < 0) {
        std::cout << "invalid amount" << std::endl;
        return 0;
    }
    else {
        return amount;
    }

}