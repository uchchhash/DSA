#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
 * Conventional Method: Finding Divisors
 * This method iterates from 1 to n and checks if n is divisible by the current number.
 * Time Complexity: O(n) because we iterate through all numbers up to n.
 */
vector<int> getAllDivisorsConventional(int n) {
    vector<int> divisors;
    
    // Loop through all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i); // If n is divisible by i, add i to divisors
        }
    }
    return divisors;
}

/*
 * Optimized Method: Finding Divisors
 * This method iterates from 1 to sqrt(n) and checks for divisibility.
 * It considers both i and n/i as divisors when n is divisible by i.
 * Time Complexity: O(√n) because we loop only up to the square root of n.
 * This reduces the number of checks significantly, making it more efficient for large numbers.
 */
vector<int> getAllDivisorsOptimized(int n) {
    vector<int> divisors;
    
    // Loop through all numbers from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i); // i is a divisor
            if (i != n / i) { // Avoid adding the square root twice
                divisors.push_back(n / i); // n/i is also a divisor
            }
        }
    }
    sort(divisors.begin(), divisors.end()); // Sort divisors in ascending order
    return divisors;
}

int main() {
    int number = 36; // Example number
    
    // Using Conventional Method
    vector<int> divisorsConventional = getAllDivisorsConventional(number);
    cout << "Divisors of " << number << " (Conventional): ";
    for (int divisor : divisorsConventional) {
        cout << divisor << " ";
    }
    cout << endl;

    // Using Optimized Method
    vector<int> divisorsOptimized = getAllDivisorsOptimized(number);
    cout << "Divisors of " << number << " (Optimized): ";
    for (int divisor : divisorsOptimized) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Summary:
 * The code provides two methods to find divisors of a number:
 * 1. Conventional Method (O(n)) - Loops through all numbers from 1 to n.
 * 2. Optimized Method (O(√n)) - Loops through numbers from 1 to √n, reducing checks.
 * Both methods return the divisors of the given number, sorted in ascending order.
 * The optimized method is more efficient for larger numbers because it reduces the number of checks.
 */
