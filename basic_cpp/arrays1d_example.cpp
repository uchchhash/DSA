#include <iostream>
using namespace std;

// Function Prototypes (declare the function signature before main)
int sumArray(int arr[], int size);  // Declaration for sumArray function
void reverseArray(int arr[], int size); // Declaration for reverseArray function

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate array size

    // Call the sumArray function
    int array_sum = sumArray(arr, size);
    cout << "Sum of array elements: " << array_sum << endl;

    // Call the reverseArray function
    reverseArray(arr, size);

    cout << "Array after reversing: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function Definitions (implement the functions after main)

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        // Swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}
