#include <iostream>
using namespace std;

// Function to demonstrate pass by value
/*
Pass by Value Function (passByValue):
- This function demonstrates pass by value with an integer parameter.
- The function receives a copy of the original value, and modifications made inside the function do not affect the original variable.
*/
void passByValue(int num) {
    num += 10; // Modify the local copy of num
    cout << "Inside passByValue function: " << num << endl;
}

// Function to demonstrate pass by reference
/*
Pass by Reference Function (passByReference):
- This function demonstrates pass by reference with an integer parameter.
- The function receives a reference to the original variable, allowing modifications made inside the function to affect the original variable.
*/
void passByReference(int &num) {
    num += 10; // Modify the original value of num
    cout << "Inside passByReference function: " << num << endl;
}

// Function to demonstrate pass by reference with an array parameter
/*
Pass by Reference Function with Array Parameter (modifyArray):
- This function demonstrates pass by reference with an array parameter.
- The function receives a reference to the original array, allowing modifications made inside the function to affect the original array.
*/
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] += 10; // Modify each element of the array
    }
}

int main() {
    // Example with integer parameter
    int x = 5;
    cout << "Original value of x: " << x << endl;

    // Call passByValue function
    passByValue(x);
    cout << "Value of x after passByValue function: " << x << endl; // Value remains unchanged

    // Call passByReference function
    passByReference(x);
    cout << "Value of x after passByReference function: " << x << endl; // Value is modified

    // Example with array parameter
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "\nOriginal array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call modifyArray function
    modifyArray(arr, size);

    cout << "Array elements after modification: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
