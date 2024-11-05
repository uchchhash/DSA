#include <iostream>
#include <utility> // For std::pair
#include <vector>  // For std::vector

using namespace std;

int main() {
    // Creating a pair using make_pair
    pair<int, string> myPair = make_pair(1, "One");

    // Accessing elements
    cout << "First: " << myPair.first << endl;
    cout << "Second: " << myPair.second << endl;

    // Creating a pair directly
    pair<double, char> anotherPair(3.14, 'A');

    // Accessing elements
    cout << "First: " << anotherPair.first << endl;
    cout << "Second: " << anotherPair.second << endl;

    // Using pairs in a vector
    vector<pair<int, string>> vec;
    vec.push_back(make_pair(2, "Two"));
    vec.push_back(make_pair(3, "Three"));

    // Iterating through the vector of pairs
    cout << "Vector of pairs:" << endl;
    for (const auto& p : vec) {
        cout << "First: " << p.first << ", Second: " << p.second << endl;
    }

    // Comparing pairs
    pair<int, int> p1(1, 2);
    pair<int, int> p2(1, 3);
    
    if (p1 < p2) {
        cout << "p1 is less than p2" << endl;
    }

    return 0;
}
