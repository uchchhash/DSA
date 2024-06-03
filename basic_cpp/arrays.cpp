#include <iostream>
using namespace std;

int main() {
    // 1D Array Example
    cout << "1D Array Example:" << endl;
    int arr1D[5]; // Declaration of a 1D array
    cout << "Enter 5 elements for the 1D array:" << endl;
    cout << "Enter element 1: ";
    cin >> arr1D[0];
    cout << "Enter element 2: ";
    cin >> arr1D[1];
    cout << "Enter element 3: ";
    cin >> arr1D[2];
    cout << "Enter element 4: ";
    cin >> arr1D[3];
    cout << "Enter element 5: ";
    cin >> arr1D[4];

    // Printing the elements of the 1D array
    cout << "Elements of the 1D array: ";
    cout << arr1D[0] << " " << arr1D[1] << " " << arr1D[2] << " " << arr1D[3] << " " << arr1D[4] << endl << endl;

    // 2D Array Example
    cout << "2D Array Example:" << endl;
    int arr2D[3][3]; // Declaration of a 2D array
    cout << "Enter 9 elements for the 2D array:" << endl;
    cout << "Enter element (1,1): ";
    cin >> arr2D[0][0];
    cout << "Enter element (1,2): ";
    cin >> arr2D[0][1];
    cout << "Enter element (1,3): ";
    cin >> arr2D[0][2];
    cout << "Enter element (2,1): ";
    cin >> arr2D[1][0];
    cout << "Enter element (2,2): ";
    cin >> arr2D[1][1];
    cout << "Enter element (2,3): ";
    cin >> arr2D[1][2];
    cout << "Enter element (3,1): ";
    cin >> arr2D[2][0];
    cout << "Enter element (3,2): ";
    cin >> arr2D[2][1];
    cout << "Enter element (3,3): ";
    cin >> arr2D[2][2];

    // Printing the elements of the 2D array
    cout << "Elements of the 2D array:" << endl;
    cout << arr2D[0][0] << " " << arr2D[0][1] << " " << arr2D[0][2] << endl;
    cout << arr2D[1][0] << " " << arr2D[1][1] << " " << arr2D[1][2] << endl;
    cout << arr2D[2][0] << " " << arr2D[2][1] << " " << arr2D[2][2] << endl << endl;

    return 0;
}
