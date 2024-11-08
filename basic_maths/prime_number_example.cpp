#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
 * Function 1: Basic Prime Check (Brute Force)
 * Checks if a number is prime by iterating from 2 to n-1.
 * Time Complexity: O(n)
 */
bool isPrimeBasic(int n) {
    if (n <= 1) return false; // 1 and less are not prime numbers
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false; // Divisible by i, not prime
    }
    return true; // No divisors found, n is prime
}

/*
 * Function 2: Optimized Prime Check (Square Root Optimization)
 * Checks if a number is prime by iterating only up to √n.
 * Time Complexity: O(√n)
 */
bool isPrimeOptimized(int n) {
    if (n <= 1) return false; // Not prime
    if (n == 2 || n == 3) return true; // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Divisible by 2 or 3, not prime

    for (int i = 5; i <= sqrt(n); i += 6) { // Check factors from 5 up to √n
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true; // No divisors found, n is prime
}

/*
 * Function 3: Prime Numbers up to N (Sieve of Eratosthenes)
 * Generates all prime numbers up to a given number n.
 * Time Complexity: O(n log log n)
 */
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Initialize boolean array
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not primes

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i); // Collect prime numbers
    }
    return primes;
}

int main() {
    int number = 29;

    // Check if a number is prime using different methods
    cout << "Checking if " << number << " is prime:\n";
    cout << "Basic Prime Check: " << (isPrimeBasic(number) ? "Yes" : "No") << endl;
    cout << "Optimized Prime Check: " << (isPrimeOptimized(number) ? "Yes" : "No") << endl;

    // Generate all prime numbers up to a given number
    int limit = 50;
    cout << "\nPrime numbers up to " << limit << ":\n";
    vector<int> primes = sieveOfEratosthenes(limit);
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
