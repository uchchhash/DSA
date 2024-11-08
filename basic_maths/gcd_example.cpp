#include <iostream>
#include <vector>
#include <numeric>  // For the built-in std::gcd function in C++17 and later

using namespace std;

/* 
 * Function 1: Conventional (Brute-Force) GCD Calculation
 * ------------------------------------------------------
 * - This function finds the GCD of two numbers by checking divisibility from
 *   the smallest of the two numbers down to 1.
 * - It returns the first common divisor found (starting from the larger possible divisors),
 *   making it the GCD of the two numbers.
 * 
 * Time Complexity: O(min(a, b))
 * - This approach has a time complexity of O(min(a, b)) since it iterates up to the smaller number.
 * - The worst case occurs when `a` and `b` are relatively prime, as it requires the loop to complete.
 */
int gcdConventional(int a, int b) {
    int gcd = 1;
    int limit = min(a, b); // We only need to iterate up to the smaller number

    for (int i = limit; i >= 1; i--) { 
        if (a % i == 0 && b % i == 0) { // Check if `i` divides both `a` and `b`
            gcd = i;
            break; // Found the GCD, so exit the loop
        }
    }
    return gcd;
}

/* 
 * Function 2: Euclidean Algorithm (Iterative Implementation)
 * ----------------------------------------------------------
 * - This function finds the GCD of two numbers using the Euclidean algorithm.
 * - The Euclidean algorithm calculates GCD by iteratively finding the remainder
 *   until it reaches zero. GCD(a, b) = GCD(b, a % b), and this reduces the numbers
 *   until `b` becomes zero.
 * 
 * Time Complexity: O(log(min(a, b)))
 * - This approach is much faster than the conventional method.
 * - The Euclidean algorithm's time complexity is logarithmic in the smaller of the two numbers.
 */
int gcdEuclidean(int a, int b) {
    while (b != 0) { 
        int remainder = a % b; // Find the remainder when `a` is divided by `b`
        a = b;                 // Set `a` to `b`
        b = remainder;         // Set `b` to the remainder
    }
    return a; // `a` is the GCD when `b` reaches zero
}


int main() {
    int num1 = 36;
    int num2 = 60;

    cout << "Numbers: " << num1 << ", " << num2 << "\n\n";

    // Call and display results from each GCD function
    cout << "GCD (Conventional Method): " << gcdConventional(num1, num2) << endl;
    cout << "GCD (Euclidean Algorithm): " << gcdEuclidean(num1, num2) << endl;

    return 0;
}
