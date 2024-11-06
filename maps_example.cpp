#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Declaring a map to store key-value pairs (key: int, value: string)
    map<int, string> myMap;
    map<int, string> myMap2;

    // Explanation:
    // In a map, each element is a pair: key and value.
    // Keys must be unique and are stored in sorted order, just like elements in a set.
    // Values can be of any data type and can be modified once added.

    // Inserting elements into the map using insert and emplace
    myMap.insert({1, "Apple"});
    myMap.insert({3, "Banana"});
    myMap.emplace(2, "Cherry"); // emplace constructs the element in place (efficient for complex types)
    myMap.insert({4, "Date"});

    // Visualizing the Map after insertions (sorted by keys):
    // ---------------------------------------------------------
    //   Key | Value
    // ---------------------------------------------------------
    //    1  | Apple
    //    2  | Cherry
    //    3  | Banana
    //    4  | Date
    // ---------------------------------------------------------

    // Displaying map elements using an iterator
    cout << "Map elements using iterator:\n";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl; // Accessing key with .first and value with .second
    }

    // Displaying map elements using range-based for loop (for-each loop)
    cout << "\nMap elements using range-based for loop:\n";
    for (const auto &pair : myMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Finding an element
    int keyToFind = 3;
    auto it = myMap.find(keyToFind);
    if (it != myMap.end()) {
        cout << "\nFound key " << keyToFind << " with value: " << it->second << endl;
    } else {
        cout << "\nKey " << keyToFind << " not found in the map.\n";
    }

    // Demonstrating lower_bound and upper_bound
    // lower_bound(key) gives iterator to the first element >= key
    // upper_bound(key) gives iterator to the first element > key
    int keyForBound = 2;
    auto lb = myMap.lower_bound(keyForBound); // Points to key 2 (Cherry)
    auto ub = myMap.upper_bound(keyForBound); // Points to key 3 (Banana)
    if (lb != myMap.end()) {
        cout << "\nLower bound of key " << keyForBound << " is " << lb->first << ": " << lb->second << endl;
    }
    if (ub != myMap.end()) {
        cout << "Upper bound of key " << keyForBound << " is " << ub->first << ": " << ub->second << endl;
    }

    // Erasing an element
    int keyToErase = 1;
    myMap.erase(keyToErase); // Erases the element with key 1 (Apple)
    cout << "\nMap elements after erasing key " << keyToErase << ":\n";
    for (const auto &pair : myMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Size, empty, and swapping maps
    cout << "\nSize of map: " << myMap.size() << endl; // Shows the number of key-value pairs in the map
    cout << "Is the map empty? " << (myMap.empty() ? "Yes" : "No") << endl;

    // Creating another map and swapping contents
    map<int, string> anotherMap;
    anotherMap.insert({10, "Orange"});
    anotherMap.insert({20, "Grape"});

    cout << "\nContents of anotherMap before swap:\n";
    for (const auto &pair : anotherMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    myMap.swap(anotherMap); // Swapping myMap with anotherMap

    cout << "\nContents of myMap after swap:\n";
    for (const auto &pair : myMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    cout << "\nContents of anotherMap after swap:\n";
    for (const auto &pair : anotherMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}
