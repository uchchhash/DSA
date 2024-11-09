#include <iostream>
using namespace std;

void printNumbers(int n) {
    // Base case: when n is 0, stop the recursion
    if (n == 0) {
        return;
    }
    
    // Recursive case: print numbers before n
    printNumbers(n - 1);
    
    // Print the current number (this will print numbers from 1 to n)
    cout << n << " ";
}

void printNumbersUpto(int n){
    if(n == 0) return;
    cout << "Numbers rev :" << n <<endl;
    printNumbersUpto(n-1);
    cout << "Numbers :" << n <<endl;
}

void printNtimes(int N){
    if(N==0) return;
    printNtimes(N-1);
    printf("[%d] Hello I'm Sarkar", N);
    cout <<endl;
}

int sumUptoN(int N) {
    if (N == 0) return 0;          // Base case: sum up to 0 is 0
    int sum = N + sumUptoN(N - 1);  // Recursive call with accumulation
    cout << "Sum up to " << N << " = " << sum << endl;
    return sum;
}

// Factorial : N! = N*(N-1)*(N-2)*(N-3)*(N-(N-1))

// 5 
// factorial = 0
// factorial = 5 * (5-1) = 20
// factorial = 20

int factUpotoN(int N){
    if(N==0) return 0;
    int multiplication =  N * factUpotoN(N-1);
    int factorial = factorial*multiplication;
    return factorial;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Numbers from 1 to " << num << " are: ";
    printNumbers(num);
    cout << endl;
    cout << endl;

    printNumbersUpto(3);
    cout << endl;
    cout << endl;

    int sum;
    sum = sumUptoN(5);
    cout << "sum upto n = "<< sum <<endl;

    printNtimes(3); 

    int N = 5;
    int factor = factUpotoN(N);
    printf("factorial of %d is = %d", N, factor);

    return 0;
}
