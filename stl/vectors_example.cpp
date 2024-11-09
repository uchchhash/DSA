#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std;

int main() {
    // Creating a vector of integers
    vector<int> myVector;

    // Arrays are constant
    // Vectors are dynamic
    // Push_back adds elements to the end of the vector
    // -------------------------------------------------
    // index_0 | index_1 | index_2 . . . . . index_n |   <----- push_back
    // -------------------------------------------------

    // Adding elements using push_back
    myVector.push_back(10);  // Adds 10 at index 0
    myVector.push_back(20);  // Adds 20 at index 1
    myVector.push_back(30);  // Adds 30 at index 2

    // Access elements in a vector
    // Indexing: myVector[index_number]
    // Using indexing to access elements
    cout << "Elements in the vector using indexing: ";
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " "; // Access elements using operator[]
    }
    cout << endl;

    // Accessing elements using an iterator
    // Iterator syntax
    // Points to the memory, not to the element
    // .begin() returns an iterator to the first element
    // .end() returns an iterator to the memory location right after the last element
    cout << "Elements in the vector using iterator: ";
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " "; // Dereference iterator to access the element
    }
    cout << endl;

    // Alternative way using range-based for loop (auto keyword)
    cout << "Elements in the vector using range-based for loop: ";
    for (auto it : myVector) {
        cout << it << " "; // Automatically deduces the type of the iterator
    }
    cout << endl;

    // Demonstrating some vector functions
    cout << "Size of vector: " << myVector.size() << endl; // Size of the vector

    // Inserting a vector inside a vector
    vector<int> anotherVector = {40, 50};
    myVector.insert(myVector.end(), anotherVector.begin(), anotherVector.end()); // Inserts anotherVector elements at the end
    cout << "After inserting another vector: ";
    for (auto it : myVector) {
        cout << it << " "; // Display updated vector
    }
    cout << endl;

    // Erase elements from the vector (removing the first element)
    myVector.erase(myVector.begin()); // Removes the first element
    cout << "After erasing the first element: ";
    for (auto it : myVector) {
        cout << it << " ";
    }
    cout << endl;

    // Removing the last element
    myVector.pop_back(); // Removes the last element
    cout << "After popping the last element: ";
    for (auto it : myVector) {
        cout << it << " ";
    }
    cout << endl;

    // Checking if the vector is empty
    if (myVector.empty()) {
        cout << "Vector is empty." << endl;
    } else {
        cout << "Vector is not empty." << endl;
    }

    // Clearing all elements from the vector
    myVector.clear(); // Removes all elements
    cout << "After clearing, size of vector: " << myVector.size() << endl;

    return 0; // Return 0 to indicate successful execution
}
