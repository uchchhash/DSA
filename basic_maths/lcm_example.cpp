#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Function 1: Conventional Method to Calculate LCM
 * Time Complexity: O(min(a, b)) since we check multiples of the larger number.
 * In this approach, we calculate the LCM by finding the smallest number that is divisible by both a and b.
 * Steps:
 * 1. Start from the larger number and keep checking for divisibility by both numbers.
 * 2. Return the first number that is divisible by both.
 */
int lcmConventional(int a, int b) {
    int maxNum = max(a, b); // Start checking from the larger number
    while (true) {
        if (maxNum % a == 0 && maxNum % b == 0) {
            return maxNum; // Return when the number is divisible by both
        }
        maxNum++; // Increment the number by 1 and check again
    }
}

/*
 * Function 2: Optimized Method using GCD to Calculate LCM (Using formula)
 * Time Complexity: O(log(min(a, b))) due to the use of the Euclidean Algorithm to calculate GCD.
 * Formula: LCM(a, b) = |a * b| / GCD(a, b)
 * Steps:
 * 1. First, calculate the GCD of a and b using the Euclidean algorithm.
 * 2. Then use the formula to calculate the LCM.
 */
int lcmEuclidean(int a, int b) {
    // Calculate GCD using Euclidean Algorithm
    int gcd = __gcd(a, b); // Built-in C++ function to calculate GCD
    return (a * b) / gcd; // Use the formula to calculate LCM
}

/*
 * Function 3: Built-in Method to Calculate LCM (Using built-in GCD function)
 * Time Complexity: O(log(min(a, b))) since the GCD calculation is logarithmic.
 * Steps:
 * 1. Directly use the built-in __gcd function from the algorithm library.
 * 2. Calculate LCM using the formula: LCM(a, b) = |a * b| / GCD(a, b)
 */
int lcmBuiltIn(int a, int b) {
    return (a * b) / __gcd(a, b); // Directly use the built-in function to calculate GCD and calculate LCM
}

int main() {
    int num1 = 12, num2 = 18;

    // Using Conventional Method
    cout << "LCM (Conventional) of " << num1 << " and " << num2 << " is: " << lcmConventional(num1, num2) << endl;

    // Using Optimized Euclidean Method
    cout << "LCM (Euclidean) of " << num1 << " and " << num2 << " is: " << lcmEuclidean(num1, num2) << endl;

    // Using Built-in Method
    cout << "LCM (Built-in) of " << num1 << " and " << num2 << " is: " << lcmBuiltIn(num1, num2) << endl;

    return 0;
}

/*
 * Explanation:
 * 1. The Conventional Method checks all multiples of the larger number starting from the maximum of the two numbers.
 *    Time Complexity: O(min(a, b)) because it checks all multiples up to the larger number.
 * 2. The Optimized Method uses the formula LCM(a, b) = |a * b| / GCD(a, b), with GCD calculated using the Euclidean algorithm.
 *    Time Complexity: O(log(min(a, b))) as the GCD calculation uses the Euclidean algorithm.
 * 3. The Built-in Method is the most efficient, using the __gcd function from the algorithm library, followed by the LCM formula.
 *    Time Complexity: O(log(min(a, b))) similar to the Euclidean algorithm.
 */
