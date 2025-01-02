#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
 // TODO
 private: 
 string accountNumber;
 string accountholder;
 float balance;

public: BankAccount(string accountNum,string accounthold, float bal){
       this->accountNumber = accountNum;
       this->accountholder = accounthold;
       this->balance = bal;
};
 public: void deposit(float amount){
    balance+= amount;
 };
 public: bool withdraw(float amount){
    if (amount > balance){
        cout << "There are not enough fund in your acount \n";
        return false;
    }else {
        cout << "Transaction complete";
        balance -= amount;
        return true;
    }
 };
    string toString() {
        // Create a string stream to format the output
        stringstream ss;
        ss << fixed << setprecision(2);  // Ensure 2 decimal places
        ss << "Number: " << accountNumber << " Holder: " << accountholder << " Balance: " << balance;
        return ss.str();  // Return the formatted string
    }
};

int main() {

    // Create an account with 0$
    BankAccount myAccount("ABC", "ronan", 0);
    cout<< myAccount.toString() << endl;

    // Deposite 100$
    myAccount.deposit(100);
    cout<< myAccount.toString() << endl;

    // Withdraw 80$ - Should success
    myAccount.withdraw(80);
    cout<< myAccount.toString() << endl;

    // Withdraw 30$ - Should fail
    myAccount.withdraw(30);
    cout<< myAccount.toString() << endl;

    return 0;
}