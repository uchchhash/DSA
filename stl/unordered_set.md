# C++ STL - unordered_set

## Overview

`unordered_set` is a part of the C++ Standard Template Library (STL) and is used to store unique elements in no particular order. It is implemented as a hash table, providing average constant-time complexity for insertions, deletions, and lookups.

## Key Features

- **Uniqueness**: Each element must be unique; duplicates are not allowed.
- **No Order**: Elements are not stored in any particular order.
- **Fast Operations**: Average time complexity for search, insert, and delete is O(1).
- **Template-Based**: Can store any data type that supports hashing and equality comparison.

## Basic Operations

1. **Insertion**: Add elements to the set.
2. **Deletion**: Remove elements from the set.
3. **Searching**: Check if an element exists in the set.
4. **Iteration**: Iterate over the elements in the set.

## Example Code

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_set
    std::unordered_set<int> mySet;

    // Insert elements into the unordered_set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Duplicate; won't be added

    // Display the elements in the unordered_set
    std::cout << "Elements in the unordered_set: ";
    for (const int &elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    int searchElement = 20;
    if (mySet.find(searchElement) != mySet.end()) {
        std::cout << searchElement << " exists in the set." << std::endl;
    } else {
        std::cout << searchElement << " does not exist in the set." << std::endl;
    }

    // Erase an element
    mySet.erase(10);
    std::cout << "After erasing 10, elements in the unordered_set: ";
    for (const int &elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Get the size of the unordered_set
    std::cout << "Size of the unordered_set: " << mySet.size() << std::endl;

    return 0;
}
