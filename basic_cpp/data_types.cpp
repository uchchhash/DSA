#include<bits/stdc++.h>
using namespace std;

// This program demonstrates the use of various data types in C++.
// Below are the sizes of some common data types:
// int - 4 bytes
// long - 4 bytes (on many systems, it can be 8 bytes on others)
// float - 4 bytes
// string - varies, depends on the length of the string
// char - 1 byte

int main() {
    // int - 4 bytes: Used to store integer values.
    int a = 10; // Example of int type, initialized with the value 10.

    // long - 4 bytes (on many systems, it can be 8 bytes on others): Used to store larger integer values.
    long b = 100; // Example of long type, initialized with the value 100.

    // float - 4 bytes: Used to store single-precision floating point numbers.
    float c; // Declaration of a float variable.
    cout << "Enter a float value: ";
    cin >> c; // Input a float value from the user and store it in variable c.

    // string: A sequence of characters, used to store text.
    string mystring; // Declaration of a string variable.
    cout << "Enter a string (no spaces): ";
    cin >> mystring; // Input a string from the user and store it in variable mystring.

    cin.ignore(); // Clear the input buffer to remove any leftover newline character from previous input.

    // getline: Used to read a whole line of text including spaces.
    string mystring2; // Declaration of another string variable.
    cout << "Enter a full line of text: ";
    getline(cin, mystring2); // Input a full line of text from the user and store it in mystring2.

    // char - 1 byte: Used to store a single character.
    char x; // Declaration of a char variable.
    cout << "Enter a single character: ";
    cin >> x; // Input a single character from the user and store it in variable x.

    // Output the values of the variables to the console.
    cout << "Value of int a = " << a << endl; // Print the value of integer a.
    cout << "Value of long b = " << b << endl; // Print the value of long b.
    cout << "Value of float c = " << c << "\n"; // Print the value of float c.
    cout << "My-String = " << mystring << endl; // Print the value of string mystring.
    cout << "My-String2 = " << mystring2 << endl; // Print the value of string mystring2.
    cout << "Character x = " << x << endl; // Print the value of character x.

    return 0; // Indicate that the program ended successfully.
}
