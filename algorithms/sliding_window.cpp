#include <bits/stdc++.h>
using namespace std;

// =======================================================
//  Fixed-size Sliding Window (array of ints)
//  Assumption: 1 <= k <= n
// =======================================================

// 1) Maximum sum of any subarray of size k
long long max_sum_k(const vector<int> &a, int k) {
    int n = (int)a.size();
    long long window_sum = 0;

    // build first window
    for (int i = 0; i < k; i++) window_sum += a[i];

    long long best = window_sum;

    // slide window
    for (int i = k; i < n; i++) {
        window_sum += a[i];       // add new
        window_sum -= a[i - k];   // remove old
        best = max(best, window_sum);
    }

    return best;
}

// 2) Minimum sum of any subarray of size k
long long min_sum_k(const vector<int> &a, int k) {
    int n = (int)a.size();
    long long window_sum = 0;

    for (int i = 0; i < k; i++) window_sum += a[i];
    long long best = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += a[i];
        window_sum -= a[i - k];
        best = min(best, window_sum);
    }

    return best;
}

// 3) Average of all subarrays of size k
vector<double> avg_all_k(const vector<int> &a, int k) {
    int n = (int)a.size();
    vector<double> res;
    if (k > n) return res;

    long long window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += a[i];
    res.push_back((double)window_sum / k);

    for (int i = k; i < n; i++) {
        window_sum += a[i];
        window_sum -= a[i - k];
        res.push_back((double)window_sum / k);
    }

    return res;
}

// 4) Count subarrays of size k with sum >= X
int count_subarrays_k_sum_ge_x(const vector<int> &a, int k, long long X) {
    int n = (int)a.size();
    if (k > n) return 0;

    long long window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += a[i];
    int cnt = 0;
    if (window_sum >= X) cnt++;

    for (int i = k; i < n; i++) {
        window_sum += a[i];
        window_sum -= a[i - k];
        if (window_sum >= X) cnt++;
    }

    return cnt;
}

// 5) Collect all subarrays of size k (for practice / debugging)
vector<vector<int>> all_subarrays_k(const vector<int> &a, int k) {
    int n = (int)a.size();
    vector<vector<int>> res;
    if (k > n) return res;

    for (int start = 0; start + k <= n; start++) {
        vector<int> window;
        for (int i = start; i < start + k; i++) window.push_back(a[i]);
        res.push_back(window);
    }
    return res;
}

// =======================================================
//  Variable-size Sliding Window (positive/ non-negative arrays)
// =======================================================
// These assume a[] elements are >= 0 (important for correctness)

// 6) Smallest subarray with sum >= X (positive numbers)
int smallest_subarray_sum_at_least_x(const vector<int> &a, long long X) {
    int n = (int)a.size();
    int left = 0;
    long long window_sum = 0;
    int best_len = INT_MAX;

    for (int right = 0; right < n; right++) {
        window_sum += a[right];

        // shrink from left while condition holds
        while (window_sum >= X) {
            best_len = min(best_len, right - left + 1);
            window_sum -= a[left];
            left++;
        }
    }

    if (best_len == INT_MAX) return -1; // no such subarray
    return best_len;
}

// 7) Longest subarray with sum <= X (non-negative numbers)
int longest_subarray_sum_at_most_x(const vector<int> &a, long long X) {
    int n = (int)a.size();
    int left = 0;
    long long window_sum = 0;
    int best_len = 0;

    for (int right = 0; right < n; right++) {
        window_sum += a[right];

        // shrink until sum <= X
        while (window_sum > X && left <= right) {
            window_sum -= a[left];
            left++;
        }

        // now sum <= X
        best_len = max(best_len, right - left + 1);
    }

    return best_len;
}

// =======================================================
//  Example main() just to test functions quickly
//  You can comment this out and write your own tests.
// =======================================================
int main() {
    int n, k;
    cout << "n = ";
    cin >> n;
    vector<int> a(n);
    cout << "array: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "k = ";
    cin >> k;

    cout << "max_sum_k = " << max_sum_k(a, k) << "\n";
    cout << "min_sum_k = " << min_sum_k(a, k) << "\n";

    long long X;
    cout << "X (for sum>=X, <=X problems) = ";
    cin >> X;

    cout << "count_subarrays_k_sum_ge_x = "
         << count_subarrays_k_sum_ge_x(a, k, X) << "\n";

    cout << "smallest_subarray_sum_at_least_x = "
         << smallest_subarray_sum_at_least_x(a, X) << "\n";

    cout << "longest_subarray_sum_at_most_x = "
         << longest_subarray_sum_at_most_x(a, X) << "\n";

    return 0;
}
