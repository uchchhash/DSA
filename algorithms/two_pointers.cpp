#include <bits/stdc++.h>
using namespace std;

/*

####################################################################
##########                TWO-POINTERS                    ##########
####################################################################
• It is a TECHNIQUE used mainly on sorted arrays or strings.

Basic idea:
    Use two indexes:
        left  → start of array
        right → end of array

    Move them based on conditions to reduce work from O(n^2) to O(n).

Here we solve the classic problem:
    "Does there exist a pair (i, j) such that arr[i] + arr[j] = target?"

Requirements:
    • Array must be sorted (non-decreasing)
    • Two pointers: L = 0, R = n-1

Time Complexity:  O(n)
Space: O(1)

########################################################
#### Poblems two-pointers can solve.
########################################################

--------------------------------------------------------------------
# ✅ **Beginner Level Problems**
--------------------------------------------------------------------
1. Reverse an array
2. Reverse a string
3. Check if a string is a palindrome
4. Check if an array is a palindrome
5. Find if a pair exists with sum = X (sorted array)
6. Find a pair whose sum is closest to X
7. Find a pair whose sum is closest to zero
8. Count pairs with sum < X (sorted array)
9. Merge two sorted arrays into one
10. Find intersection of two sorted arrays

--------------------------------------------------------------------
# ✅ **Basic-Mid Level Problems**
--------------------------------------------------------------------

11. Remove duplicates from a sorted array
12. Remove all occurrences of a given value from array
13. Move zeros to the end of the array
14. Partition array into even and odd numbers
15. Partition array around a pivot (like quicksort)
16. Find if a pair exists with difference = K
17. Find all pairs with a given sum (sorted array)
18. Compare two strings lexicographically using two pointers
19. Check if two strings are rotations of each other (two-pointer scanning)
20. Check if string can become a palindrome by removing at most one char


*/



int main() {

    // ------------------------------------------------------------
    // 1. Input number of elements
    // ------------------------------------------------------------
    cout << "Enter the number of elements of the Array = ";
    int n;
    cin >> n;

    vector<int> arr(n);

    // ------------------------------------------------------------
    // 2. Input sorted array
    // ------------------------------------------------------------
    cout << "Enter elements of the Array [Sorted Please]" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "] = ";
        cin >> arr[i];
    }

    // ------------------------------------------------------------
    // 3. Input target sum
    // ------------------------------------------------------------
    cout << "\nEnter the target sum X = ";
    int target;
    cin >> target;

    // ------------------------------------------------------------
    // 4. Apply Two-Pointers Technique
    // ------------------------------------------------------------
    int left = 0;          // at beginning
    int right = n - 1;     // at end

    bool found = false;

    cout << "\nStarting Two-Pointers Search...\n";

    while (left < right) {

        int current_sum = arr[left] + arr[right];

        cout << "Checking: arr[" << left << "] = " << arr[left]
             << " + arr[" << right << "] = " << arr[right]
             << " → Sum = " << current_sum << endl;

        // Case 1: Found exact sum
        if (current_sum == target) {
            cout << "  → Found! (" << arr[left] << " + " << arr[right] << " = " << target << ")\n";
            found = true;
            break;
        }

        // Case 2: sum too big → move right pointer left
        else if (current_sum > target) {
            cout << "  → Sum too large, moving RIGHT pointer left\n";
            right--;
        }

        // Case 3: sum too small → move left pointer right
        else {
            cout << "  → Sum too small, moving LEFT pointer right\n";
            left++;
        }
    }

    // ------------------------------------------------------------
    // 5. Final decision
    // ------------------------------------------------------------
    if (!found) {
        cout << "\nNo pair found that sums to " << target << ".\n";
    } else {
        cout << "\nPair exists in the array.\n";
    }

    return 0;
}
