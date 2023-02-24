#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Account {
  int id;
  float balance;
};

// read data from file and populate array of structures
void readData(Account accounts[], int& numAccounts) {
  // code to read data from file and populate accounts array
}

// write data from array of structures to file
void writeData(Account accounts[], int numAccounts) {
  // code to write data from accounts array to file
}

// function to calculate deposit
void deposit(Account accounts[], int numAccounts, int loggedInIndex, float amount) {
  accounts[loggedInIndex].balance += amount;
  writeData(accounts, numAccounts);
}

// function to calculate withdrawal
void withdraw(Account accounts[], int numAccounts, int loggedInIndex, float amount) {
  accounts[loggedInIndex].balance -= amount;
  writeData(accounts, numAccounts);
}

// function to check balance
float checkBalance(Account accounts[], int numAccounts, int loggedInIndex) {
  return accounts[loggedInIndex].balance;
}

int main() {
  Account accounts[100];
  int numAccounts = 0;
  readData(accounts, numAccounts);

  // code to handle login
  int loggedInIndex = 0; // assume logged in as first account in array

  // code to handle deposit, withdrawal, and checking balance
  deposit(accounts, numAccounts, loggedInIndex, 100);
  withdraw(accounts, numAccounts, loggedInIndex, 50);
  float balance = checkBalance(accounts, numAccounts, loggedInIndex);
  return 0;
}
