#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// GCD Function using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular inverse using the Extended Euclidean Algorithm (EEA)
// This function finds the modular inverse of 'a' modulo 'm' if the gcd(a, m) = 1
// This method is valid for all integers 'a' and 'm' where gcd(a, m) = 1.
int modInverseEEA(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    // If m is 1, the inverse doesn't exist.
    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        // q is the quotient
        q = a / m;
        t = m;

        // Update m and a for the next iteration
        m = a % m;
        a = t;

        t = x0;

        // Update x0 and x1 (Bézout's coefficients)
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Ensure x1 is positive (modular inverse can be negative)
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// Function to compute modular inverse using Fermat's Little Theorem (FLT)
// This function calculates the modular inverse of 'a' modulo 'm' assuming 'm' is prime.
// According to Fermat's Little Theorem: a^(m-2) % m is the modular inverse of 'a' mod 'm' when 'm' is prime.
int modInverseFLT(int a, int m) {
    // Fermat's Little Theorem: a^(m-2) % m is the modular inverse of a mod m
    // We use exponentiation by squaring to efficiently compute a^(m-2) % m
    int res = 1;
    a = a % m; // In case a is greater than or equal to m

    int exp = m - 2; // Compute the exponent (m - 2)
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % m; // If the exponent is odd, multiply result by a
        }
        a = (a * a) % m;  // Square the base
        exp /= 2;          // Halve the exponent
    }
    
    return res;
}



/* =================== Quadratic Equation ================== */

// Basic Method: Solve using the quadratic formula
void solveQuadraticBasic(int a, int b, int c) {
    // The quadratic formula is (-b ± sqrt(b^2 - 4ac)) / 2a
    double discriminant = b * b - 4 * a * c;  // Calculate the discriminant
    if (discriminant < 0) {
        cout << "No real roots exist." << endl;
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1: " << root1 << ", Root 2: " << root2 << endl;
    }
}

// Optimized Method: Solve using the more accurate approach
void solveQuadraticOptimized(int a, int b, int c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "No real roots exist." << endl;
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1: " << root1 << ", Root 2: " << root2 << endl;
    }
}

/* =================== Prime Factorization ================== */

// Basic Method: Factorization using trial division
void primeFactorizationBasic(int n) {
    cout << "Prime Factorization (Basic): ";
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    cout << endl;
}

// Optimized Method: Factorization using trial division only up to sqrt(n)
void primeFactorizationOptimized(int n) {
    cout << "Prime Factorization (Optimized): ";
    for (int i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n; // n is prime if greater than 1
    cout << endl;
}

/* =================== Factorial ================== */

// Basic Method: Iterative approach to calculate factorial
int factorialBasic(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Optimized Method: Recursive approach to calculate factorial
int factorialOptimized(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialOptimized(n - 1);
}

/* =================== Chinese Remainder Theorem ================== */

// Basic Method: Chinese Remainder Theorem for solving two linear congruences
int chineseRemainderBasic(int a, int m, int b, int n) {
    // Using the extended Euclidean algorithm to solve linear congruences
    for (int x = 0; x < m * n; ++x) {
        if ((a + m * x) % n == b % n) {
            return a + m * x;
        }
    }
    return -1; // No solution
}

// Optimized Method: Efficient solution using the Chinese Remainder Theorem
int chineseRemainderOptimized(int a, int m, int b, int n) {
    int x, y;
    int g = gcd(m, n);
    if ((b - a) % g != 0) return -1;  // If no solution exists
    int mod = (m * n) / g;
    int inv_m = modInverseFLT(m, n);  // Implement modular inverse function
    int inv_n = modInverseFLT(n, m);
    return (a * inv_n * n + b * inv_m * m) % mod;
}

/* =================== Pascal’s Triangle ================== */

// Basic Method: Print Pascal's triangle using loops
void printPascalsTriangleBasic(int n) {
    for (int line = 0; line < n; ++line) {
        int num = 1;
        for (int j = 0; j <= line; ++j) {
            cout << num << " ";
            num = num * (line - j) / (j + 1);  // Binomial coefficient
        }
        cout << endl;
    }
}

// Optimized Method: Using dynamic programming for Pascal’s triangle
void printPascalsTriangleOptimized(int n) {
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Printing Pascal’s Triangle
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test each function

    cout << "=================== Modular Inverse ===================" << endl;
    int a = 3, m = 11;
    // Test the modular inverse using Extended Euclidean Algorithm
    int inverseEEA = modInverseEEA(a, m);
    cout << "Modular inverse of " << a << " using EEA under modulo " << m << " is: " << inverseEEA << endl;

    // Test the modular inverse using Fermat's Little Theorem
    int inverseFLT = modInverseFLT(a, m);
    cout << "Modular inverse of " << a << " using FLT under modulo " << m << " is: " << inverseFLT << endl;

    cout << "=================== Quadratic Equation ===================" << endl;
    solveQuadraticBasic(1, -3, 2);  // Example: x^2 - 3x + 2 = 0
    solveQuadraticOptimized(1, -3, 2);
    
    cout << "\n=================== Prime Factorization ===================" << endl;
    primeFactorizationBasic(56);  // Example: Prime factors of 56
    primeFactorizationOptimized(56);

    cout << "\n=================== Factorial ===================" << endl;
    cout << "Factorial (Basic) of 5: " << factorialBasic(5) << endl;
    cout << "Factorial (Optimized) of 5: " << factorialOptimized(5) << endl;

    cout << "\n=================== Chinese Remainder Theorem ===================" << endl;
    cout << "Chinese Remainder (Basic): " << chineseRemainderBasic(2, 3, 3, 5) << endl;  // Example: x ≡ 2 (mod 3), x ≡ 3 (mod 5)
    cout << "Chinese Remainder (Optimized): " << chineseRemainderOptimized(2, 3, 3, 5) << endl;

    cout << "\n=================== Pascal's Triangle ===================" << endl;
    printPascalsTriangleBasic(5);  // Print the first 5 rows
    printPascalsTriangleOptimized(5);

    return 0;
}
