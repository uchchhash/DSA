#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------------
                           SLIDING WINDOW
--------------------------------------------------------------------
Goal of this example:
    Given:
        • n  = number of elements
        • arr[0..n-1] = array of integers
        • k  = window size (k <= n)

    Find:
        • Maximum sum of any CONTIGUOUS subarray of size k

Example:
    arr = [1, 2, 3, 4, 5], k = 3

    Windows of size 3:
        [1, 2, 3] → sum = 6
        [2, 3, 4] → sum = 9
        [3, 4, 5] → sum = 12  (maximum)

--------------------------------------------------------------------
What is Sliding Window?

    • Technique to process ranges [L..R] in an array/string efficiently.
    • Instead of recomputing from scratch for each range,
      we "slide" a window and update the answer in O(1) per step.

Fixed-size window (this example):
    • Window size is always K
    • We move:
          window_start (left pointer)
          window_end   (right pointer)

    • At every step:
          - Add new element at right
          - Remove old element at left
          - Move both pointers forward

Time Complexity:
    • O(n)
      Because each element is added once and removed once.

Space Complexity:
    • O(1)
      We only store:
         - current_sum
         - max_sum
         - few indices
--------------------------------------------------------------------
**Sliding Window problems**

# ✅ **Beginner Level Sliding Window Problems**

1. Maximum sum of any subarray of size **k**
2. Minimum sum of any subarray of size **k**
3. Print all subarrays of size **k**
4. Average of all subarrays of size **k**
5. Count how many subarrays of size **k** have sum ≥ X

---

# ✅ **Basic–Mid Level Sliding Window Problems**

6. Longest substring without repeating characters
7. Longest subarray with sum ≤ X
8. Smallest subarray with sum ≥ X
9. Count subarrays with sum exactly = X (positive numbers)
10. Longest subarray with all 1s after flipping at most K zeros
11. Number of subarrays with product < X
12. Longest substring with at most K distinct characters
13. Longest substring with exactly K distinct characters
14. Find all anagrams of a pattern inside a string
15. Minimum window substring (basic-mid version)


*/

int main() {

    // ==============================================================
    // 1. Input: array size
    // ==============================================================
    cout << "Enter the number of elements of the Array = ";
    int n;
    cin >> n;

    vector<int> arr(n);

    // ==============================================================
    // 2. Input: array elements (unsorted is fine)
    // ==============================================================
    cout << "Enter elements of the Array" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "] = ";
        cin >> arr[i];
    }

    // ==============================================================
    // 3. Input: window size k
    // ==============================================================
    cout << "\nEnter window size k = ";
    int k;
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid window size. It must satisfy: 1 <= k <= n\n";
        return 0;
    }

    // ==============================================================
    // 4. Initialize sliding window
    //    First window: indices [0 .. k-1]
    // ==============================================================
    int window_start = 0;
    int window_end   = 0;

    long long current_sum = 0;   // sum of current window
    long long max_sum     = LLONG_MIN;
    int max_start_index   = 0;   // to remember where max window starts

    cout << "\nBuilding initial window [0.." << (k-1) << "]\n";

    // Build the first window of size k
    for (window_end = 0; window_end < k; window_end++) {
        current_sum += arr[window_end];
        cout << "Adding arr[" << window_end << "] = " << arr[window_end]
             << ", current_sum = " << current_sum << endl;
    }

    max_sum = current_sum;
    max_start_index = 0;

    cout << "Initial window sum = " << current_sum << endl;
    cout << "Current max_sum = " << max_sum << " for window [0.." << (k-1) << "]\n";

    // ==============================================================
    // 5. Slide the window across the array
    //
    //    Now window is always size k:
    //        Before slide: [window_start .. window_end-1]
    //        After slide : [window_start+1 .. window_end]
    //
    //    Steps when sliding:
    //        1) Remove arr[window_start]   from current_sum
    //        2) Add    arr[window_end]     to current_sum
    //        3) Move   window_start++
    // ==============================================================
    cout << "\nStarting to slide the window...\n";

    while (window_end < n) {
        /*
            At this point:
                - Previous loop created a window [window_start .. window_end-1] of size k
                - window_end is currently at index k, then k+1, ..., n-1
                - New window after slide will be [window_start+1 .. window_end]
        */

        // Remove the element that is leaving the window
        cout << "\nSliding window by 1 step...\n";
        cout << "Removing arr[" << window_start << "] = " << arr[window_start]
             << " from current_sum\n";
        current_sum -= arr[window_start];

        // Shift window_start to the right
        window_start++;

        // Add the new element entering the window
        cout << "Adding arr[" << window_end << "] = " << arr[window_end]
             << " to current_sum\n";
        current_sum += arr[window_end];

        // Now the window is [window_start .. window_end]
        cout << "Current window = ["
             << window_start << ".." << window_end << "], "
             << "current_sum = " << current_sum << endl;

        // Update max_sum if this window is better
        if (current_sum > max_sum) {
            cout << "New max_sum found! Old = " << max_sum
                 << ", New = " << current_sum << endl;
            max_sum = current_sum;
            max_start_index = window_start;
        } else {
            cout << "max_sum stays = " << max_sum << endl;
        }

        // Move window_end one step to the right
        window_end++;
    }

    // ==============================================================
    // 6. Print final result
    // ==============================================================
    cout << "\n================ RESULT ================\n";
    cout << "Maximum sum of any subarray of size " << k
         << " is = " << max_sum << endl;

    cout << "This maximum sum window is from index ["
         << max_start_index << ".." << (max_start_index + k - 1)
         << "], elements: ";

    for (int i = max_start_index; i < max_start_index + k; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
