#include <iostream>
#include <string> // Include the string library
using namespace std;

int main() {
    // Declare a string variable
    string myString;

    // Accept user input for the string
    cout << "Enter a string: ";
    getline(cin, myString); // Using getline to accept strings with spaces

    // Print the original string
    cout << "Original String: " << myString << endl;

    // Accept user input for the index of the character to replace
    int index;
    cout << "Enter the index of the character to replace: ";
    cin >> index;

    // Check if the index is within the bounds of the string
    if (index < 0 || index >= myString.length()) {
        cout << "Invalid index!" << endl;
    } else {
        // Accept user input for the new character
        char newChar;
        cout << "Enter the new character: ";
        cin >> newChar;

        // Replace the character at the specified index
        myString[index] = newChar;

        // Print the string after replacement
        cout << "String after replacing character at index " << index << ": " << myString << endl;
    }

    return 0;
}
