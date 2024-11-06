#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Create an unordered_map: key-value pair container
    // An unordered_map stores the key-value pairs where keys are unique.
    // The key-value pairs are unordered (no specific sorting like in map).
    unordered_map<int, string> myUnorderedMap;

    // Inserting elements using insert() function
    myUnorderedMap.insert(make_pair(1, "Apple"));
    myUnorderedMap.insert(make_pair(2, "Banana"));
    myUnorderedMap.insert(make_pair(3, "Cherry"));
    myUnorderedMap.insert(make_pair(4, "Date"));

    // Inserting element with operator[] (adds or updates value)
    myUnorderedMap[5] = "Elderberry";

    // Visualizing the unordered_map after insertions:
    // The elements will not be ordered like in a map, as unordered_map 
    // uses a hash table and does not maintain order.
    cout << "Elements in the unordered_map:\n";
    for (auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // **Key Differences between map and unordered_map**:
    // 1. **Order**: 
    //    - `map` stores elements in sorted order based on the keys.
    //    - `unordered_map` stores elements using a hash table, and the order is not guaranteed.
    // 2. **Performance**:
    //    - `map` usually has O(log n) time complexity for most operations.
    //    - `unordered_map` typically has O(1) time complexity for insertions, lookups, and deletions.
    // 3. **Use Case**:
    //    - Use `unordered_map` when order is not important and you need faster average time complexity for lookups and insertions.
    //    - Use `map` if you need ordered elements based on keys.

    // **Finding an Element**:
    // The find() method returns an iterator to the element with the specified key.
    cout << "\nFinding key 3 in the unordered_map:\n";
    auto it = myUnorderedMap.find(3);  // Find the key-value pair with key 3
    if (it != myUnorderedMap.end()) {
        cout << "Found: Key: " << it->first << ", Value: " << it->second << endl;
    } else {
        cout << "Key not found\n";
    }

    // **Erasing an Element**:
    // We can erase an element from the unordered_map using the erase() function.
    cout << "\nErasing the element with key 2:\n";
    myUnorderedMap.erase(2);  // Erase element with key 2
    for (auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // **Checking the Size**:
    // The size() function returns the number of elements in the unordered_map.
    cout << "\nSize of unordered_map: " << myUnorderedMap.size() << endl;

    // **Checking if Unordered Map is Empty**:
    // The empty() function checks if the unordered_map is empty.
    cout << "\nIs the unordered_map empty? " << (myUnorderedMap.empty() ? "Yes" : "No") << endl;

    // **Clearing the unordered_map**:
    // The clear() function removes all elements from the unordered_map.
    myUnorderedMap.clear();
    cout << "\nAfter clearing, size of unordered_map: " << myUnorderedMap.size() << endl;

    return 0;
}
