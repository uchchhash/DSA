// Skeleton of a C++ program

// Library to take input and produce output
//#include<iostream> // This can be used to include specific input-output functionality

// Include all C++ libraries
#include<bits/stdc++.h> // This is a header file that includes most of the C++ standard libraries
using namespace std; // This allows us to use names from the standard library without the 'std::' prefix

int main() {
    // Outputting text to the console
    std::cout << "Hello World" << "\n"; // '\n' is used to insert a new line
    std::cout << "Hello World" << std::endl; // std::endl also inserts a new line and flushes the output buffer
    std::cout << "Hello World" << "\nHello Mars" << endl; // Multiple outputs in a single statement

    // Declaring integer variables
    int x, y;
    
    // Taking input from the user
    cin >> x; // Input an integer value and store it in variable x
    cin >> y; // Input another integer value and store it in variable y
    
    // Outputting the values of the variables
    cout << "Value of x: " << x << endl; // Print the value of x followed by a new line
    cout << "Value of y: " << y; // Print the value of y without a new line

    return 0; // Indicate that the program ended successfully
}
