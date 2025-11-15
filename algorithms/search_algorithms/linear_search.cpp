#include <bits/stdc++.h>   // includes most headers
using namespace std;

// Linear Search (O(n)) // Simple & universal algorithm
// Works on ANY array: sorted or unsorted
// Idea: Check every element from left to right until found
// When to use: Unsorted array, small datasets
// Time: O(n)


int main() {
    // n = number of elements in the array
    cout<<"Enter the number of elements of the Array = ";
    int n;
    cin >> n;

    // We use a vector instead of a raw array, flexible
    vector<int> arr(n);

    // Input: n integers (NO need to be sorted)
    cout<<"Enter elements of the Array"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Enter element ["<<i<<"] = ";
        cin >> arr[i];
    }

    // x = value we want to search for
    cout<<"Enter the value you want to search = ";
    int x;
    cin >> x;

    bool found = false;  // track if x exists
    int index;           // store the index if found

    // ----------------- Linear Search Loop -----------------
    //
    // Time complexity intuition:
    //   - We may need to look at ALL n elements.
    //   - Worst case: value not present → check every element.
    //   - Best case: value at index 0 → only 1 check.
    //   - Average/worst time = O(n)
    //
    for (int i = 0; i < n; i++) {

        // If the current element matches x, we found it
        if (arr[i] == x) {
            found = true;
            index = i;
            break;      // stop searching once found
        }
    }
    // ----------------- End of Linear Search -----------------

    // After the loop:
    //   - If found == true, we found x at index i.
    //   - If found == false, we checked all n elements with no match.
    if (found) {
        cout << "Found at index [" << index << "]" << endl;
    } else {
        cout << "Not found\n";
    }

    return 0;
}
