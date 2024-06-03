#include <iostream>
using namespace std;

/*
Simple while Loop: 
- Iterates from 1 to 5, printing the value of i each time.

Simple do-while Loop: 
- Similar to the while loop, but checks the condition after executing the loop body.

Nested while Loops: 
- Demonstrates nesting, with an outer loop iterating from 1 to 3 and 
- an inner loop also iterating from 1 to 3. 
- It prints pairs of (outer, inner).

while Loop with break: 
- Iterates from 1 to 10, but 
- when k is equal to 6, the loop exits prematurely.

while Loop with continue: 
- Iterates from 1 to 10, but 
- when m is equal to 6, it skips printing 6 and proceeds to the next iteration.

do-while Loop with break and continue: 
- Similar to the while loop examples, but using a do-while loop instead.

*/

int main() {
    // Example of a while loop
    cout << "Example of a while loop:" << endl;
    int i = 1; // Initialize the loop control variable
    while (i <= 5) {
        cout << i << " "; // Print the value of i
        ++i; // Update the loop control variable
    }
    cout << endl << endl;

    // Example of a do-while loop
    cout << "Example of a do-while loop:" << endl;
    int j = 1; // Initialize the loop control variable
    do {
        cout << j << " "; // Print the value of j
        ++j; // Update the loop control variable
    } while (j <= 5); // Check the condition after executing the loop body
    cout << endl << endl;

    // Example of nested while loops
    cout << "Example of nested while loops:" << endl;
    int outer = 1;
    while (outer <= 3) {
        int inner = 1;
        while (inner <= 3) {
            cout << "(" << outer << "," << inner << ") "; // Print the pair (outer, inner)
            ++inner; // Update the inner loop control variable
        }
        cout << endl; // Move to the next line after printing each row
        ++outer; // Update the outer loop control variable
    }
    cout << endl;

    // Example of a while loop with break
    cout << "Example of a while loop with break:" << endl;
    int k = 1; // Initialize the loop control variable
    while (k <= 10) {
        if (k == 6) {
            break; // Exit the loop when k is equal to 6
        }
        cout << k << " ";
        ++k; // Update the loop control variable
    }
    cout << endl << endl;

    // Example of a while loop with continue
    cout << "Example of a while loop with continue:" << endl;
    int m = 1; // Initialize the loop control variable
    while (m <= 10) {
        if (m == 6) {
            ++m; // Increment m to avoid printing 6
            continue; // Skip printing 6 and proceed to the next iteration
        }
        cout << m << " ";
        ++m; // Update the loop control variable
    }
    cout << endl << endl;

    // Example of a do-while loop with break
    cout << "Example of a do-while loop with break:" << endl;
    int n = 1; // Initialize the loop control variable
    do {
        if (n == 6) {
            break; // Exit the loop when n is equal to 6
        }
        cout << n << " ";
        ++n; // Update the loop control variable
    } while (n <= 10);
    cout << endl << endl;

    // Example of a do-while loop with continue
    cout << "Example of a do-while loop with continue:" << endl;
    int p = 1; // Initialize the loop control variable
    do {
        if (p == 6) {
            ++p; // Increment p to avoid printing 6
            continue; // Skip printing 6 and proceed to the next iteration
        }
        cout << p << " ";
        ++p; // Update the loop control variable
    } while (p <= 10);
    cout << endl;

    return 0;
}
