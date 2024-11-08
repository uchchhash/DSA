#include <iostream>
#include <vector>
using namespace std;

// Function 1: Find the nth Fibonacci number (Basic Approach)
int nthFibonacciBasic(int n) {
    // Start with the first two Fibonacci numbers
    int a = 0, b = 1;
    // Iterate from 2 to n, as the first two numbers are already assigned
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;  // Fibonacci formula: F(n) = F(n-1) + F(n-2)
        a = b;             // Move b to a
        b = temp;          // Move the newly calculated Fibonacci number to b
    }
    return n == 0 ? a : b;  // If n is 0, return 0; otherwise, return b
}

// Function 2: Print the first n Fibonacci numbers (Basic Approach)
void printFibonacciUpToN(int n) {
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; ++i) {
        int temp = a + b;
        cout << temp << " ";
        a = b;
        b = temp;
    }
    cout << endl;
}

// Function 3: Find Fibonacci numbers for a series of positions (Basic Approach)
vector<int> fibonacciForPositions(const vector<int>& positions) {
    vector<int> fibonacciNumbers;
    for (int pos : positions) {
        fibonacciNumbers.push_back(nthFibonacciBasic(pos));  // Call nthFibonacciBasic for each position
    }
    return fibonacciNumbers;
}

// Function 4: Find Fibonacci numbers up to a certain value (Basic Approach)
vector<int> fibonacciUpToValue(int maxValue) {
    vector<int> fibonacciNumbers;
    int a = 0, b = 1;
    fibonacciNumbers.push_back(a);
    fibonacciNumbers.push_back(b);

    // Keep adding Fibonacci numbers until we exceed the max value
    while (b <= maxValue) {
        int temp = a + b;
        fibonacciNumbers.push_back(temp);
        a = b;
        b = temp;
    }
    return fibonacciNumbers;
}

// Optimized Fibonacci using Dynamic Programming (Storing results to avoid recalculation)
int nthFibonacciOptimizedDP(int n) {
    vector<int> dp(n + 1, 0);  // Create a DP table to store Fibonacci numbers up to n
    dp[1] = 1;  // Base case: F(1) = 1
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Fill the table using the Fibonacci formula
    }
    return dp[n];  // Return the nth Fibonacci number
}

// Optimized Fibonacci using Memoization (Top-down approach)
int fibonacciMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;  // Base case
    if (memo[n] != -1) return memo[n];  // If already calculated, return it
    // Otherwise calculate and store the result in memo
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 6;

    // Example 1: Find the nth Fibonacci number using Basic Approach
    cout << "Nth Fibonacci (Basic): " << nthFibonacciBasic(n) << endl;

    // Example 2: Print the first n Fibonacci numbers
    cout << "First " << n << " Fibonacci numbers (Basic): ";
    printFibonacciUpToN(n);

    // Example 3: Find Fibonacci numbers for a series of positions
    vector<int> positions = {2, 4, 6};
    vector<int> fibonacciSeries = fibonacciForPositions(positions);
    cout << "Fibonacci numbers at positions 2, 4, 6 (Basic): ";
    for (int num : fibonacciSeries) {
        cout << num << " ";
    }
    cout << endl;

    // Example 4: Find Fibonacci numbers up to a certain value
    int maxValue = 15;
    vector<int> fibonacciUpToMax = fibonacciUpToValue(maxValue);
    cout << "Fibonacci numbers up to " << maxValue << " (Basic): ";
    for (int num : fibonacciUpToMax) {
        cout << num << " ";
    }
    cout << endl;

    // Example 5: Optimized Fibonacci using Dynamic Programming
    cout << "Nth Fibonacci (Optimized DP): " << nthFibonacciOptimizedDP(n) << endl;

    // Example 6: Optimized Fibonacci using Memoization
    vector<int> memo(n + 1, -1);  // Initialize memoization table with -1
    cout << "Nth Fibonacci (Memoization): " << fibonacciMemo(n, memo) << endl;

    return 0;
}
