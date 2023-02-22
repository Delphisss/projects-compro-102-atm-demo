#include <iostream>

using namespace std;

int main() {
    int choice = 0;
    bool done = false;
    while (!done) {
        // Display main menu
        cout << "Main Menu" << endl;
        cout << "1. Option 1" << endl;
        cout << "2. Option 2" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Process user's choice
        switch (choice) {
            case 1:
                // Handle option 1
                cout << "Option 1 selected." << endl;
                break;
            case 2:
                // Handle option 2
                cout << "Option 2 selected." << endl;
                break;
            case 3:
                // Quit
                cout << "Goodbye!" << endl;
                done = true;
                break;
            default:
                // Invalid choice
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        if (!done) {
            // Wait for user to press enter before going back to main menu
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
            cout << endl;
        }
    }
    return 0;
}
