#include <iostream>
using namespace std;

/*
Simple for loop: 
- This loop iterates from 1 to 5, printing the value of i each time.

Nested for loop: 
- This loop demonstrates nesting, with an outer loop iterating from 1 to 3 
- and an inner loop also iterating from 1 to 3. It prints pairs of (i, j).

For loop with break: 
- This loop iterates from 1 to 10, but when i is equal to 6, 
- the break statement is encountered, causing the loop to exit prematurely.

For loop with continue: 
- This loop also iterates from 1 to 10, but when i is equal to 6, 
- the continue statement is encountered, skipping the printing of 6 
- and proceeding to the next iteration.

*/


int main() {
    // Example of a simple for loop
    cout << "Example of a simple for loop:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << i << " "; // Print the value of i
    }
    cout << endl << endl;

    // Example of a nested for loop
    cout << "Example of a nested for loop:" << endl;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cout << "(" << i << "," << j << ") "; // Print the pair (i, j)
        }
        cout << endl; // Move to the next line after printing each row
    }
    cout << endl;

    // Example of a for loop with break
    cout << "Example of a for loop with break:" << endl;
    for (int i = 1; i <= 10; ++i) {
        if (i == 6) {
            break; // Exit the loop when i is equal to 6
        }
        cout << i << " ";
    }
    cout << endl << endl;

    // Example of a for loop with continue
    cout << "Example of a for loop with continue:" << endl;
    for (int i = 1; i <= 10; ++i) {
        if (i == 6) {
            continue; // Skip printing 6 and proceed to the next iteration
        }
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
