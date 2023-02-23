#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ACCOUNTS = 100;
const int ID_LENGTH = 4;

struct Account {
    string id;
    double balance;
};

Account accounts[MAX_ACCOUNTS];

int findAccountIndex(string id) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].id == id) {
            return i;
        }
    }
    return -1;
}

void login() {
    string id;
    cout << "Please enter your ID: ";
    cin >> id;

    int index = findAccountIndex(id.substr(id.length() - ID_LENGTH));
    if (index == -1) {
        cout << "Account not found." << endl;
    }
    else {
        cout << "Welcome, " << id << "." << endl;

        while (true) {
            int choice;
            cout << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check balance" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (choice == 1) {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accounts[index].balance += amount;
                cout << "Deposit successful. Current balance is " << fixed << setprecision(2) << accounts[index].balance << endl;
            }
            else if (choice == 2) {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > accounts[index].balance) {
                    cout << "Insufficient funds." << endl;
                }
                else {
                    accounts[index].balance -= amount;
                    cout << "Withdrawal successful. Current balance is " << fixed << setprecision(2) << accounts[index].balance << endl;
                }
            }
            else if (choice == 3) {
                cout << "Current balance is " << fixed << setprecision(2) << accounts[index].balance << endl;
            }
            else if (choice == 4) {
                cout << "Logging out." << endl;
                break;
            }
            else {
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
            }
        }
    }
}

int main() {
    // Initialize accounts
    accounts[0] = { "12345678", 100.00 };
    accounts[1] = { "98765432", 50.00 };
    accounts[2] = { "24681357", 200.00 };

    login();

    return 0;
}
