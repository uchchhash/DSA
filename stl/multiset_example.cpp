#include <iostream>
#include <set>
using namespace std;

int main() {
    // Declaring a multiset
    multiset<int> myMultiSet; // A multiset allows duplicate elements and keeps them sorted

    // Adding elements to the multiset
    myMultiSet.insert(30); // Inserts 30 into the multiset
    myMultiSet.insert(10); // Inserts 10 into the multiset
    myMultiSet.insert(20); // Inserts 20 into the multiset
    myMultiSet.insert(10); // Inserts another 10 (duplicates allowed)
    myMultiSet.insert(20); // Inserts another 20 (duplicates allowed)

    // Visualizing the Multiset after insert operations:
    // -------------------------------------------------
    //   | 10 | 10 | 20 | 20 | 30 |   <----- Ordered elements, duplicates included
    // -------------------------------------------------

    // Displaying the elements in the multiset
    cout << "Elements in the multiset: ";
    for (const auto &elem : myMultiSet) {
        cout << elem << " "; // Will print: 10 10 20 20 30
    }
    cout << endl;

    // Checking if an element exists and counting occurrences
    int searchElement = 10;
    int countOfElement = myMultiSet.count(searchElement); // Should return 2 for value 10
    cout << "Count of " << searchElement << " in the multiset: " << countOfElement << endl; // Should print 2

    // Erasing all occurrences of an element
    myMultiSet.erase(10); // Removes all occurrences of 10
    // if I erase an element, it erases all instances of that element

    // Visualizing the Multiset after erase operation:
    // -------------------------------------------------
    //   | 20 | 20 | 30 |   <----- Ordered elements after erasing 10
    // -------------------------------------------------

    // Displaying the elements after erasure
    cout << "Elements in the multiset after erasing 10: ";
    for (const auto &elem : myMultiSet) {
        cout << elem << " "; // Will print: 20 20 30
    }
    cout << endl;

    // Inserting elements again for further operations
    myMultiSet.insert(20); // Inserts another 20
    myMultiSet.insert(40); // Inserts 40

    // Finding an element
    auto it = myMultiSet.find(20); // Finds an instance of 20
    if (it != myMultiSet.end()) {
        cout << "Found 20 in the multiset." << endl; // Should print this line
    }

    // Erasing a specific instance using an iterator
    myMultiSet.erase(it); // Erases one instance of 20 (the first occurrence)
    // if I say erase iterator, it erases only that particular instance of that element

    // Visualizing the Multiset after erasing one instance of 20:
    // -------------------------------------------------
    //   | 20 | 30 | 40 |   <----- Ordered elements after erasing one instance of 20
    // -------------------------------------------------

    // Displaying the elements after erasure
    cout << "Elements in the multiset after erasing one instance of 20: ";
    for (const auto &elem : myMultiSet) {
        cout << elem << " "; // Will print: 20 30 40
    }
    cout << endl;

    // Clearing the multiset
    myMultiSet.clear(); // Removes all elements from the multiset
    cout << "Size of the multiset after clearing: " << myMultiSet.size() << endl; // Should print 0

    return 0;
}
