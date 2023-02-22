#include <iostream>

using namespace std;

int main() {
    int arr[] = {1000, 2100, 1200, 4110, 10};
    int pos;

    cout << "Enter the position of the element you want to retrieve: ";
    cin >> pos;

    // Check if the position is within the bounds of the array
    if (pos >= 1 && pos <= sizeof(arr)/sizeof(arr[0])) {
        // Retrieve the value at the given position
        int val = arr[pos-1];
        cout << "The value at position " << pos << " is: " << val << endl;
    }
    else {
        cout << "Invalid position!" << endl;
    }

    return 0;
}
