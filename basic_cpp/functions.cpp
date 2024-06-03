#include <iostream>
using namespace std;

/*
Void Function (greet): 
- This function does not return any value. It simply prints a greeting message.
*/
// Void function: does not return a value
void greet() {
    cout << "Hello! Welcome to the world of functions." << endl;
}

// Function with return value
/*
Function with Return Value (square):
- This function takes an integer parameter and returns the square of that number.
*/
int square(int num) {
    return num * num;
}

// Parameterized function: takes parameters
/*
Parameterized Function (displayMessage):
- This function takes a string parameter and displays a message.
*/
void displayMessage(string message) {
    cout << "Message from the function: " << message << endl;
}

// Function without parameters
/*
Function without Parameters (printNumbers):
- This function does not take any parameters. It prints numbers from 1 to 5.
*/
void printNumbers() {
    cout << "Numbers from 1 to 5: ";
    for (int i = 1; i <= 5; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

// Function without return keyword (implicitly returns void)
/*
Function without Return Keyword (add):
- This function calculates the sum of two numbers and prints the result.
- Although not recommended, C++ allows defining functions without specifying a return type. If no return type is specified, it defaults to int.
*/
add(int a, int b) {
    int sum = a + b;
    cout << "Sum of " << a << " and " << b << " is: " << sum << endl;
}

int main() {
    // Calling void function
    greet();

    // Calling function with return value
    int result = square(5);
    cout << "Square of 5: " << result << endl;

    // Calling parameterized function
    displayMessage("Have a great day!");

    // Calling function without parameters
    printNumbers();

    // Calling function without return keyword
    add(10, 20);

    return 0;
}
