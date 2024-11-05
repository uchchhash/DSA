#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // Create an unordered_set
    unordered_set<int> mySet;

    // Insert elements into the unordered_set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // This will be ignored since 20 is a duplicate

    // Display the elements in the unordered_set
    cout << "Elements in the unordered_set: ";
    for (const int &elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element exists
    int searchElement = 20;
    if (mySet.find(searchElement) != mySet.end()) {
        cout << searchElement << " exists in the set." << endl;
    } else {
        cout << searchElement << " does not exist in the set." << endl;
    }

    // Erase an element
    mySet.erase(10);
    cout << "After erasing 10, elements in the unordered_set: ";
    for (const int &elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Get the size of the unordered_set
    cout << "Size of the unordered_set: " << mySet.size() << endl;

    return 0;
}
