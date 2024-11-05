#include <iostream>
#include <set>
using namespace std;

int main() {
    // Declaring a set
    set<int> mySet; // A set is a collection of unique elements, sorted automatically

    // Adding elements to the set
    mySet.insert(30); // Inserts 30 into the set
    mySet.insert(10); // Inserts 10 into the set
    mySet.insert(20); // Inserts 20 into the set
    mySet.insert(10); // This will be ignored since sets only contain unique elements

    // Visualizing the Set after insert operations:
    // -------------------------------------------------
    //   | 10 | 20 | 30 |   <----- Ordered elements
    // -------------------------------------------------

    // Displaying the elements in the set
    cout << "Elements in the set: ";
    for (const auto &elem : mySet) {
        cout << elem << " "; // Will print: 10 20 30
    }
    cout << endl;

    // Checking if an element exists
    int searchElement = 20;
    auto it = mySet.find(searchElement); // Finds the element, returns an iterator
    if (it != mySet.end()) {
        cout << searchElement << " exists in the set." << endl; // Should print this line
    } else {
        cout << searchElement << " does not exist in the set." << endl;
    }

    // Counting occurrences of an element (sets have unique elements)
    int countOfElement = mySet.count(10); // Should be either 0 or 1
    cout << "Count of 10 in the set: " << countOfElement << endl; // Should print 1

    // Erasing an element
    mySet.erase(30); // Removes 30 from the set

    // Visualizing the Set after erase operation:
    // -------------------------------------------------
    //   | 10 | 20 |   <----- Ordered elements
    // -------------------------------------------------

    // Displaying the elements after erasure
    cout << "Elements in the set after erasing 30: ";
    for (const auto &elem : mySet) {
        cout << elem << " "; // Will print: 10 20
    }
    cout << endl;

    // Lower and upper bound
    mySet.insert(25); // Insert 25 for testing lower and upper bounds
    cout << "After adding 25, elements in the set: ";
    for (const auto &elem : mySet) {
        cout << elem << " "; // Will print: 10 20 25
    }
    cout << endl;

    auto lower = mySet.lower_bound(20); // Points to the first element not less than 20
    auto upper = mySet.upper_bound(20); // Points to the first element greater than 20

    cout << "Lower bound of 20: " << (lower != mySet.end() ? *lower : -1) << endl; // Should print 20
    cout << "Upper bound of 20: " << (upper != mySet.end() ? *upper : -1) << endl; // Should print 25

    // Clearing the set
    mySet.clear(); // Removes all elements from the set
    cout << "Size of the set after clearing: " << mySet.size() << endl; // Should print 0

    return 0;
}
