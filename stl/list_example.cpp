#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    // Declare a list of integers
    list<int> myList;

    // Adding Elements
    myList.push_back(10);           // Add 10 to the end of the list
    // Visualizing the List after push_back operations:
    // -------------------------------------------------
    //   | 10 |   <----- push_back
    // -------------------------------------------------

    myList.emplace_back(20);        // Construct 20 in place at the end
    // Visualizing the List after emplace_back operations:
    // -------------------------------------------------
    //   | 10 | 20 |   <----- emplace_back
    // -------------------------------------------------

    myList.push_front(5);           // Add 5 to the front of the list
    // Visualizing the List after push_front operations:
    // -------------------------------------------------
    //   | 5  | 10 | 20 |   <----- push_front
    // -------------------------------------------------

    myList.emplace_front(1);        // Construct 1 in place at the front
    // Visualizing the List after emplace_front operations:
    // -------------------------------------------------
    //   | 1  | 5  | 10 | 20 |   <----- emplace_front
    // -------------------------------------------------

    // Displaying Elements
    cout << "Elements in the list: ";
    for (const int &elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Size of the List
    cout << "Size of the list: " << myList.size() << endl; // Size: 4

    // Inserting Elements
    auto it = myList.begin();       // Create an iterator pointing to the beginning
    advance(it, 2);                 // Move iterator to the 3rd position (index 2)
    myList.insert(it, 25);          // Insert 25 before the current position
    // Visualizing the List after insertion of 25:
    // -------------------------------------------------
    //   | 1  | 5  | 25 | 10 | 20 |   <----- insert(25)
    // -------------------------------------------------

    // Displaying Elements after insertion
    cout << "After inserting 25: ";
    for (const int &elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Swapping Lists
    list<int> anotherList = {100, 200, 300}; // Another list to swap with
    myList.swap(anotherList);        // Swap contents of myList with anotherList
    // Visualizing Lists after swapping:
    // myList becomes {100, 200, 300}
    // anotherList becomes {1, 5, 25, 10, 20}

    cout << "After swapping with another list:" << endl;
    cout << "myList: ";
    for (const int &elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "anotherList: ";
    for (const int &elem : anotherList) {
        cout << elem << " ";
    }
    cout << endl;

    // Clearing the List
    myList.clear();                  // Remove all elements from myList
    cout << "After clearing, size of myList: " << myList.size() << endl; // Size: 0

    // Check if List is Empty
    if (myList.empty()) {
        cout << "myList is empty." << endl;
    }

    // Re-initialize myList
    myList = {1, 2, 3, 4, 5};

    // Removing Elements
    myList.remove(3);               // Remove all occurrences of 3
    // Visualizing the List after removing 3:
    // -------------------------------------------------
    //   | 1  | 2  | 4  | 5 |   <----- remove(3)
    // -------------------------------------------------

    cout << "After removing 3: ";
    for (const int &elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Sorting the List
    myList.push_back(0);             // Adding more elements
    myList.push_back(6);
    myList.sort();                   // Sort the list
    // Visualizing the List after sorting:
    // -------------------------------------------------
    //   | 0  | 1  | 2  | 4 | 5 | 6 |   <----- sort()
    // -------------------------------------------------

    cout << "After sorting: ";
    for (const int &elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Finding Elements
    auto found = find(myList.begin(), myList.end(), 4);
    if (found != myList.end()) {
        cout << "Element 4 found in the list." << endl;
    } else {
        cout << "Element 4 not found in the list." << endl;
    }

    // Using rbegin() and rend() for reverse iteration
    cout << "Elements in reverse order: ";
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
