#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <utility>    // For std::pair

using namespace std;

// Function to sort an array of integers in ascending order
void sortArray() {
    int arr[] = {9, 3, 5, 1, 8, 7};
    sort(arr, arr + 6);  // Sort the array in ascending order

    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to sort a vector of integers in ascending order
void sortVector() {
    vector<int> vec = {10, 20, 5, 8, 15};
    sort(vec.begin(), vec.end());  // Sort the vector in ascending order

    cout << "Sorted vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to sort a vector of integers in descending order
void sortVectorDescending() {
    vector<int> vec = {10, 20, 5, 8, 15};
    sort(vec.begin(), vec.end(), greater<int>());  // Sort the vector in descending order

    cout << "Sorted vector in descending order: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to sort a vector of pairs in ascending order by first element, and by second element in case of tie
void sortPairVector() {
    vector<pair<int, int>> vec = {{1, 5}, {2, 3}, {1, 4}, {3, 2}, {2, 1}};
    sort(vec.begin(), vec.end());  // Sort by the first element, then by second element

    cout << "Sorted vector of pairs: ";
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

// Function to sort a vector of pairs by the second element of each pair
void sortPairVectorBySecond() {
    vector<pair<int, int>> vec = {{1, 5}, {2, 3}, {1, 4}, {3, 2}, {2, 1}};
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;  // Sort by the second element of the pair
    });

    cout << "Sorted vector of pairs by second element: ";
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

// Function to sort a vector of strings in ascending order
void sortStringVector() {
    vector<string> vec = {"apple", "banana", "cherry", "date"};
    sort(vec.begin(), vec.end());  // Sort the vector in ascending order

    cout << "Sorted strings: ";
    for (const string& str : vec) {
        cout << str << " ";
    }
    cout << endl;
}

// Function to sort a vector of strings in descending order
void sortStringVectorDescending() {
    vector<string> vec = {"apple", "banana", "cherry", "date"};
    sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
        return a > b;  // Sort the strings in descending order
    });

    cout << "Sorted strings in descending order: ";
    for (const string& str : vec) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {
    // Call each sorting function
    cout << "Example 1: Sorting an Array of Integers (Ascending Order)" << endl;
    sortArray();

    cout << "\nExample 2: Sorting a Vector of Integers (Ascending Order)" << endl;
    sortVector();

    cout << "\nExample 3: Sorting a Vector of Integers (Descending Order)" << endl;
    sortVectorDescending();

    cout << "\nExample 4: Sorting a Vector of Pairs (By First Element, Then Second Element)" << endl;
    sortPairVector();

    cout << "\nExample 5: Sorting a Vector of Pairs (By Second Element)" << endl;
    sortPairVectorBySecond();

    cout << "\nExample 6: Sorting a Vector of Strings (Ascending Order)" << endl;
    sortStringVector();

    cout << "\nExample 7: Sorting a Vector of Strings (Descending Order)" << endl;
    sortStringVectorDescending();

    return 0;
}
