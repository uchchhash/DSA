#include <bits/stdc++.h>   // includes most headers
using namespace std;

// Binary Search (O(log n)) // Fundamental algorithm
// Used everywhere: searching, optimization, math problems
// Teaches you how to think in “divide and conquer”
// Forms the backbone for many advanced problems
// When to use: Sorted array.
// Time: O(log n)


int main() {
    // n = number of elements in the array
    cout<<"Enter the number of elements of the Array = ";
    int n;
    cin >> n;

    // We use a vector instead of a raw array, flexible
    vector<int> arr(n);

    // Input: n integers in SORTED (non-decreasing) order
    // Binary search ONLY works correctly if the array is sorted.
    cout<<"Enter elements of the Array [Sorted Please]"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Enter elements of the Array [Sorted Please] ["<<i<<"] = ";
        cin >> arr[i];
    }

    // x = value we want to search for
    cout<<"Enter the value you want to search = ";
    int x;
    cin >> x;

    // first = left boundary of search range
    // last  = right boundary of search range
    int first = 0;
    int last  = n - 1;

    bool found = false;  // will track whether we found x
    int index; // number found at this index

    // ----------------- Binary Search Loop -----------------
    //
    // Time complexity intuition:
    //   - Each iteration cuts the search range roughly in HALF.
    //   - n -> n/2 -> n/4 -> n/8 -> ... -> 1
    //   - Number of steps k such that n / 2^k = 1
    //       => 2^k = n
    //       => k = log2(n)
    //   - So the worst-case time is O(log n).
    //
    while (first <= last) {
        // Middle index of current search range
        // We use this form to avoid overflow: (first + last) / 2 can overflow for big ints.
        int mid = first + (last - first) / 2;

        // Case 1: We found x at index mid
        if (arr[mid] == x) {
            found = true;
            index = mid;
            break;  // exit the loop, no need to search further
        }
        // Case 2: x is greater than the middle element
        // That means x, if it exists, must be in the RIGHT half.
        else if (x > arr[mid]) {
            // Discard the left half including mid
            // New search range becomes [mid + 1, last]
            first = mid + 1;
        }
        // Case 3: x is smaller than the middle element
        // That means x, if it exists, must be in the LEFT half.
        else {
            // Discard the right half including mid
            // New search range becomes [first, mid - 1]
            last = mid - 1;
        }
    }
    // ----------------- End of Binary Search -----------------

    // After the loop:
    //   - If found == true, we broke out because arr[mid] == x.
    //   - If found == false, search range became empty (first > last),
    //     so x does not exist in the array.
    if (found) {
        cout << "Found at index ["<<index<<"]"<<endl;;
    } else {
        cout << "Not found\n";
    }

    return 0;
}
