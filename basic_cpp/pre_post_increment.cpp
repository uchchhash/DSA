#include <iostream>
#include <vector>
using namespace std;

int main() {
    // =======================================
    // Example 1: Basic Pre-Increment and Post-Increment with Simple Variables
    // =======================================
    int a = 5;

    // Pre-Increment: The value of a is incremented first, and then it is used
    int b = ++a;  // a becomes 6 first, then b is assigned 6
    cout << "Pre-Increment:\n";
    cout << "a: " << a << ", b: " << b << endl;  // a is 6, b is 6

    // Post-Increment: The current value of a (5) is assigned to b first, then a is incremented
    int c = a++;  // c is assigned 6, then a becomes 7
    cout << "Post-Increment:\n";
    cout << "a: " << a << ", c: " << c << endl;  // a is 7, c is 6

    // =======================================
    // Example 2: Pre-Increment and Post-Increment with Iterators
    // =======================================
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Using Pre-Increment with Iterator
    cout << "\nUsing Pre-Increment with Iterator:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";  // Pre-increment, directly moves to next element
    }
    cout << endl;

    // Using Post-Increment with Iterator
    cout << "\nUsing Post-Increment with Iterator:\n";
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << " ";  // Post-increment, creates a temporary copy for use before incrementing
    }
    cout << endl;

    // =======================================
    // Example 3: Difference Between Pre and Post Increment in a Condition
    // =======================================
    int x = 0, y = 0;

    // Pre-Increment: First increments x and then uses the incremented value in the condition
    if (++x == 1) {
        cout << "\nPre-Increment condition: x = " << x << endl;  // x is 1 after increment
    }

    // Post-Increment: First uses the value of x and then increments it after the condition check
    if (y++ == 0) {
        cout << "Post-Increment condition: y = " << y << endl;  // y is 1 after increment
    }

    // =======================================
    // Example 4: Using Increment on Lvalue and Rvalue
    // =======================================
    int m = 10;

    // Lvalue Example: Using the increment on an lvalue (variable)
    int n = ++m;  // m is incremented to 11, then n is assigned 11
    cout << "\nLvalue Pre-Increment:\n";
    cout << "m: " << m << ", n: " << n << endl;  // m is 11, n is 11

    // Rvalue Example: Using the increment on an rvalue (expression)
    int p = 5;
    int q = p++ + 5;  // p is used first as 5, then p is incremented to 6
    cout << "Rvalue Post-Increment:\n";
    cout << "p: " << p << ", q: " << q << endl;  // p is 6, q is 10 (5 + 5)

    // =======================================
    // Example 5: Performance Considerations (Pre vs Post Increment in Iterators)
    // =======================================
    // Pre-Increment is often preferred for iterators, as post-increment creates a temporary copy of the iterator
    vector<int> vec = {10, 20, 30};

    // Pre-Increment Iterator
    cout << "\nUsing Pre-Increment with Iterator (Efficient):\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";  // Pre-increment: Increment is done before accessing value
    }
    cout << endl;

    // Post-Increment Iterator (Less Efficient)
    cout << "Using Post-Increment with Iterator (Less Efficient):\n";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";  // Post-increment: Creates a temporary copy for use
    }
    cout << endl;

    // =======================================
    // Example 6: Temporary Storage in Post-Increment
    // =======================================
    // The following example demonstrates how a temporary copy is created when using post-increment
    vector<int> nums = {100, 200, 300};
    
    auto it = nums.begin();
    auto tempIt = it++;  // tempIt is a temporary copy of 'it' before it is incremented
    cout << "\nTemporary Storage in Post-Increment:\n";
    cout << "Original Iterator (tempIt points here): " << *tempIt << endl;  // Points to 100
    cout << "New Iterator (after increment): " << *it << endl;  // Points to 200

    return 0;
}
