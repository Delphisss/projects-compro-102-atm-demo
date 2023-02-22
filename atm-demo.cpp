#include <iostream>
#include <conio.h> // for getch() function
#include <iomanip>

using namespace std;

float balance = 2000; //ลบออก

void highlight(int index, bool selected) { 
    int l = 0 ;
    
    if (selected) {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index) {
        case 1:
            l = 29 ;
            cout << "Deposit";
            break;
        case 2:
            l = 28 ;
            cout << "Withdraw";
            break;
        case 3:
            l = 21 ;
            cout << "Balance Inquiry";
            break;
        case 4:
            l = 32 ;
            cout << "Exit";
            break;
        default:
            break;
    }

    cout << "\033[0m"  << setw(l)<<" | \n"; // window
}

int main() {
    //login
    int id, password;
    char ch;

    // Display login window frame
    cout << "+-------------------------------------+\n" ;
    cout << "|               Login ATM             |\n" ;
    cout << "+-------------------------------------+\n" ;

    // Display prompts for ID and password
    cout << "\nEnter your ID: ";
    cin >> id;
    
    cout << "Enter your password: ";

    // Read in password character by character without displaying on screen
    password = 0;
    while ((ch = _getch()) != '\r') {  // Stop reading when user presses Enter key
        if (ch == '\b') {  // Handle backspace character
            if (password > 0) {
                password /= 10;
                cout << "\b \b";  // Move cursor back and overwrite character with space
            }
        } else if (isdigit(ch)) {  // Handle numeric characters
            password = password * 10 + (ch - '0');
            cout << "*";
        }
    }    
    
    if (id-650610000 == password ) {
        cout << "Login successful! \n" ;
                        // ATM
                        int choice = 1;
                        char ch;
                        do {
                            system("cls"); // clear the console
                            cout << "+-------------------------------------+\n";
                            cout << "|              ATM Menu               |\n"; 
                            cout << "+-------------------------------------+\n";
                            // display the menu options
                            for (int i = 1; i <= 4; i++) {
                                cout << "| ";
                                highlight(i, i == choice);
                                //cout << " |";
                            }
                            cout << "|                                     |\n";
                            cout << "+-------------------------------------+\n";

                            ch = getch(); // wait for a key press

                            // update the choice variable based on the arrow key input
                            if (ch == 72 && choice > 1) { // up arrow key
                                choice--;
                            }
                            else if (ch == 80 && choice < 4) { // down arrow key
                                choice++;
                            }
                        } while (ch != 13); // enter key

                        // display the selected option
                        switch (choice) {
                            case 1:
                                // Deposit
                                double depositAmount;
                                cout << "Enter the amount to deposit: ";
                                cin >> depositAmount;
                                if (depositAmount > 0) {
                                    balance += depositAmount;
                                    cout << "Deposit successful! Your new balance is: $" << fixed << setprecision(2) << balance << "\n";
                                } else {
                                    cout << "Invalid deposit amount.\n";
                                }
                                break;
                            case 2:
                                // Withdraw
                                double withdrawAmount;
                                cout << "Enter the amount to withdraw: ";
                                cin >> withdrawAmount;
                                if (withdrawAmount <= balance && withdrawAmount > 0) {
                                    balance -= withdrawAmount;
                                    cout << "Withdrawal successful! Your new balance is: $" << fixed << setprecision(2) << balance << "\n";
                                } else {
                                    cout << "Invalid withdrawal amount.\n";
                                }
                                break;
                            case 3:
                                // Balance Inquiry
                                cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
                                break;
                            case 4:
                                // Exit
                                cout << "Thank you for using this ATM. Goodbye!\n";
                                exit(0);  // terminate the program
                                break;
                        }

                        return 0;
    
    } else {
        cout << "\n\n+-------------------------------------+" ;
        cout << "\nLogin failed. Incorrect ID or password. \n" ;
        cout << "+-------------------------------------+\n" ;
    }
    
}
