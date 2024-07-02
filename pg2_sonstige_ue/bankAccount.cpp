#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNumber) : accountNumber(accNumber), balance(0.0) {}
    void deposit(double amount) {  
        if (amount < 0)
            throw ( invalid_argument("Betrag muss positiv sein"));
        balance += amount; 
    }
    void withdraw(double amount) { 
        if (amount <= balance)
            throw (logic_error("Nicht genügend Geld auf Konto"));
        balance -= amount;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount hanness_BankAccount(232);
    try {
    hanness_BankAccount.deposit(32.43);
    } catch(const invalid_argument &e) {
        cout << "Fehler: " << e.what() << endl;
    }
    try {
    hanness_BankAccount.withdraw(20.12);
    } catch(const logic_error &e)  {
        cout << "Fehler: " << e.what() << endl;
    }
    cout << hanness_BankAccount.getBalance() << endl;
    try {
    hanness_BankAccount.withdraw(232.2);
    } catch(const logic_error &e) {
        cout << "Fehler: " << e.what() << endl;
    }
    cout << hanness_BankAccount.getBalance() << endl;


    cout << "End of program reached" << endl;
    return 0;
}