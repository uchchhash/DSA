#include <iostream>
#include <map>
using namespace std;

int main() {
    // Creating a multimap to store int keys and string values
    // A multimap is like a map, but allows duplicate keys. It keeps all the key-value pairs sorted by the key.
    multimap<int, string> myMultimap;

    // Inserting elements into the multimap (duplicate keys are allowed)
    // Unlike a map, a multimap allows multiple elements with the same key.
    myMultimap.insert(make_pair(1, "One"));  // Key 1 maps to "One"
    myMultimap.insert(make_pair(2, "Two"));  // Key 2 maps to "Two"
    myMultimap.insert(make_pair(2, "Second Two"));  // Duplicate key 2 maps to "Second Two"
    myMultimap.insert(make_pair(3, "Three"));  // Key 3 maps to "Three"
    myMultimap.insert(make_pair(1, "Another One"));  // Duplicate key 1 maps to "Another One"

    // Visualizing the multimap after inserting elements:
    // The elements are sorted by their keys and duplicates are allowed.
    // -------------------------------------------------------------
    // Key: 1 | Value: One
    // Key: 1 | Value: Another One
    // Key: 2 | Value: Two
    // Key: 2 | Value: Second Two
    // Key: 3 | Value: Three
    // -------------------------------------------------------------
    cout << "Elements in the multimap (sorted by keys):\n";
    for (auto it = myMultimap.begin(); it != myMultimap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // **Map vs Multimap Comparison**:
    // ------------------------------------------------------
    // A map stores only unique keys, so if you insert a duplicate key,
    // the new value would overwrite the old one. In contrast, a multimap
    // allows multiple elements with the same key and keeps them all sorted.
    // For example, if we inserted two pairs with the key 2, they would both be kept
    // in the multimap, unlike a map where only the last insertion would persist.

    // **Finding a Specific Key in the Multimap**:
    // We can use the find method to search for elements in a multimap.
    cout << "\nFinding key 2 in the multimap:\n";
    auto it = myMultimap.find(2);  // Returns an iterator to the first element with key 2
    // Since a multimap can have multiple elements with the same key, 
    // we use a loop to print all elements with key 2.
    while (it != myMultimap.end() && it->first == 2) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }

    // **Erasing Elements from the Multimap**:
    // The erase function removes elements from the multimap. 
    // It can erase elements by key or by iterator.
    cout << "\nErasing the pair with key 1:\n";
    myMultimap.erase(1);  // Erase all elements with key 1 (duplicate keys are removed)
    for (auto it = myMultimap.begin(); it != myMultimap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // **Counting the Number of Occurrences of a Key**:
    // The count method returns the number of elements with the specified key.
    cout << "\nCount of key 2 in the multimap: " << myMultimap.count(2) << endl;
    // This will print the number of times the key 2 appears in the multimap.
    // Since 2 appears twice, it should return 2.

    // **Lower Bound and Upper Bound**:
    // The lower_bound and upper_bound functions are used to find the range of elements
    // that are equal to or greater than a given key.
    cout << "\nLower bound and upper bound for key 2:\n";
    auto lower = myMultimap.lower_bound(2); // First element with key >= 2
    auto upper = myMultimap.upper_bound(2); // First element with key > 2
    cout << "Lower bound (key: " << lower->first << ", value: " << lower->second << ")\n";
    cout << "Upper bound (key: " << upper->first << ", value: " << upper->second << ")\n";
    // Lower bound will point to the first element with key >= 2, and upper bound
    // will point to the first element with key > 2.

    // **Swapping Two Multimaps**:
    // We can swap the contents of two multimaps using the swap function.
    multimap<int, string> anotherMultimap;
    anotherMultimap.insert(make_pair(5, "Five"));
    anotherMultimap.insert(make_pair(4, "Four"));

    cout << "\nBefore swap, another multimap:\n";
    for (auto it = anotherMultimap.begin(); it != anotherMultimap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // Swap the contents of the two multimaps
    myMultimap.swap(anotherMultimap);

    cout << "\nAfter swap, my multimap:\n";
    for (auto it = myMultimap.begin(); it != myMultimap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }
    // The contents of myMultimap and anotherMultimap are now swapped.

    return 0;
}
