// #include <iostream>
// using namespace std;

// void printNumbers(int n) {
//     // Base case: when n is 0, stop the recursion
//     if (n == 0) {
//         return;
//     }
    
//     // Recursive case: print numbers before n
//     printNumbers(n - 1);
    
//     // Print the current number (this will print numbers from 1 to n)
//     cout << n << " ";
// }

// void printNumbersUpto(int n){
//     int count = count+1;
//     if(n == count) return;
//     cout << "Numbers :" << count <<endl;
//     count++;
//     printNumbersUpto(n);
// }

// int main() {
//     int num;
//     cout << "Enter a number: ";
//     cin >> num;

//     cout << "Numbers from 1 to " << num << " are: ";
//     printNumbers(num);
//     cout << endl;

//     printNumbersUpto(10);

//     return 0;
// }
