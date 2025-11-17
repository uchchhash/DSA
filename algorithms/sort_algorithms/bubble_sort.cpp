#include <bits/stdc++.h>   // includes most standard headers
using namespace std;

/*
--------------------------------------------------------------
                        Bubble Sort
--------------------------------------------------------------
• Type: Comparison-based sorting algorithm
• When to use:
      - For teaching sorting basics
      - When n is small
      - When a simple, intuitive method is enough

• Idea:
      - Repeatedly compare adjacent elements
      - Swap them IF they are in the wrong order
      - After each pass, the LARGEST element "bubbles" to the end

• Time Complexity:
      - Worst case: O(n^2)
      - Best case (already sorted + optimized version): O(n)
      - Why O(n^2)?
           For n elements:
               Pass 1 → n-1 comparisons
               Pass 2 → n-2 comparisons
               ...
               Pass (n-1) → 1 comparison
           Total = (n-1) + (n-2) + ... + 1 = n(n-1)/2 = O(n^2)

• Space Complexity:
      - O(1) → In-place sorting

• Stability:
      - Stable (does not change the relative order of equal elements)
--------------------------------------------------------------
*/

int main() {

    // ============================================================
    // Input: number of elements
    // ============================================================
    cout << "Enter the number of elements of the Array = ";
    int n;
    cin >> n;

    vector<int> arr(n);

    // ============================================================
    // Input: unsorted array
    // ============================================================
    cout << "Enter elements of the Array (Unsorted Allowed)" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "] = ";
        cin >> arr[i];
    }

    // ============================================================
    // Bubble Sort Algorithm
    // ============================================================
    cout << "\nStarting Bubble Sort...\n";

    /*
        -----------------------------
        How Bubble Sort Works:
        -----------------------------
        For n elements, we need up to (n-1) passes.

        pass = 1: push the largest element to arr[n-1]
        pass = 2: push the second-largest to arr[n-2]
        ...
    */

    bool swapped; // To detect if a pass made any swap

    for (int pass = 1; pass <= n - 1; pass++) {

        swapped = false;

        cout << "\n--- Pass " << pass << " ---\n";

        // Compare each adjacent pair
        for (int i = 0; i < n - pass; i++) {
            // cout << "Comparing arr[" << i << "] = " << arr[i]
            //      << " with arr[" << i+1 << "] = " << arr[i+1] << endl;

            if (arr[i] > arr[i+1]) {
                // cout << "  → Out of order, swapping!" << endl;
                
                // ------------------------------
                // Manual swap using a temp variable
                // ------------------------------
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

                swapped = true;
            } else {
                 cout << "  → Correct order, no swap." << endl;
            }
        }

        // Show array after each pass
        cout << "Array after pass " << pass << ": ";
        for (int x : arr) cout << x << " ";
        cout << "\n";

        // Optimization: If no swaps, the array is already sorted
        if (!swapped) {
            cout << "\nArray is sorted. Stopping early.\n";
            break;
        }
    }

    // ============================================================
    // Final sorted array output
    // ============================================================
    cout << "\nFinal Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
