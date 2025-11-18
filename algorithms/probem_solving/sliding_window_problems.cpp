/*
// =======================================================
// 1. Maximum Average Subarray of Size k
// =======================================================
Given an integer array arr[] and an integer k,
find the maximum possible AVERAGE among all
contiguous subarrays of size k.
Return the maximum average as a double.
*/


/*
// =======================================================
// 2. Count Subarrays of Size k With Sum >= X
// =======================================================
You are given an array of integers arr[],
an integer k, and an integer X.
Count how many contiguous subarrays of size k
have a sum >= X.
Return the count.
*/


/*
// =======================================================
// 3. Minimum Sum Subarray of Size k
// =======================================================
Given an integer array arr[] and an integer k,
find the minimum sum of any contiguous subarray
of size exactly k.
Return that minimum sum.
*/


/*
// =======================================================
// 4. Maximum Distinct Elements in Any Window of Size k
// =======================================================
Given an integer array arr[] and an integer k,
consider every contiguous window of size k.
For each window compute the number of DISTINCT elements.
Return the maximum distinct count across all windows.
*/


/*
// =======================================================
// 5. Count Windows of Size k With At Most M Zeros
// =======================================================
You are given a binary array arr[] (only 0s and 1s),
and two integers k and M.
Among all windows of size exactly k,
count how many windows contain at most M zeros.
Return that count.
*/


#include<bits/stdc++.h>
using namespace std;

/*
// =======================================================
// 1. Maximum Average Subarray of Size k
// =======================================================
Given an integer array arr[] and an integer k,
find the maximum possible AVERAGE among all
contiguous subarrays of size k.
Return the maximum average as a double.
*/

double find_max_avg_array(vector<int> &v, int k){
    double average = 0;
    double window_sum = 0;
    int size = v.size();

    // First window
    for(int i=0; i<k; i++) window_sum += v[i];
    average = window_sum/k;
    
    for(int i=k; i<size; i++){
        window_sum += v[i];
        window_sum -= v[i-k];
        average = (window_sum/k > average) ? window_sum/k : average;
    }
    return average;
}


/*
// =======================================================
// 2. Count Subarrays of Size k With Sum >= X
// =======================================================
You are given an array of integers arr[],
an integer k, and an integer X.
Count how many contiguous subarrays of size k
have a sum >= X.
Return the count.
*/

int count_subarrays(vector<int> &v, int k, int x){
    int window_sum = 0;
    int count = 0;
    int size = v.size();

    // first window
    for(int i=0; i<k; i++){
        window_sum +=v[i];
    }
    if(window_sum>=x) count++; // here i am comparing after whole window sum is done
    
    // next windows
    for(int i=k; i<size; i++){
        window_sum += v[i];
        window_sum -= v[i-k];
        if(window_sum>=x) count ++; // here each loop a new window sum happens so comparing inside the loop
    }
    if(k>size) count = 0;
    return count;    
}


/*
// =======================================================
// 4. Maximum Distinct Elements in Any Window of Size k
// =======================================================
Given an integer array arr[] and an integer k,
consider every contiguous window of size k.
For each window compute the number of DISTINCT elements.
Return the maximum distinct count across all windows.
*/
int compute_distinct(vector<int> &v, int k) {
    int n = v.size();
    if (k > n) return 0;

    vector<int> window_array(k);
    vector<int> distinct_list;

    // First window
    for (int i = 0; i < k; i++)
        window_array[i] = v[i];

    sort(window_array.begin(), window_array.end());

    int count = 1; 
    for (int i = 0; i < k - 1; i++) {
        if (window_array[i] != window_array[i + 1])
            count++;
    }
    distinct_list.push_back(count);

    // Sliding windows
    for (int i = k; i < n; i++) {

        // Re-build the window fresh every time (slow but correct)
        for (int j = 0; j < k; j++)
            window_array[j] = v[i - k + 1 + j];

        sort(window_array.begin(), window_array.end());

        int C = 1;
        for (int j = 0; j < k - 1; j++) {
            if (window_array[j] != window_array[j + 1])
                C++;
        }
        distinct_list.push_back(C);
    }

    // Get max distinct count
    int best = 0;
    for (int x : distinct_list)
        best = max(best, x);

    return best;
}

/*
// =======================================================
// 5. Count Windows of Size k With At Most M Zeros
// =======================================================
You are given a binary array arr[] (only 0s and 1s),
and two integers k and M.
Among all windows of size exactly k,
count how many windows contain at most M zeros.
Return that count.
*/

int count_zeros(vector<int> &v, int k, int m){
    int count = 0;
    int size = v.size();
    int zero_sum = 0;
    vector<int> counter_list;

    // first window
    for(int i=0; i<k; i++){
        zero_sum += (v[i]==0);
    }
    if(zero_sum <= m) count++;
    counter_list.push_back(count);

    // next windows
    for(int i=k; i<size; i++){
        zero_sum += (v[i]==0);
        zero_sum -= (v[i-k]==0);
        if(zero_sum <=m) count++;
        counter_list.push_back(count);
    }

    // Get max count
    int best = 0;
    for (int x : counter_list)
        best = max(best, x);

    return best;
}


// =======================================================
// Variable Length Sliding Window
// =======================================================

/*
// =======================================================
// 1. Longest Subarray With Sum <= S (Positive Integers)
// =======================================================
Given an array of POSITIVE integers and an integer S,
find the MAXIMUM LENGTH of any contiguous subarray
whose sum is <= S.
Return the length.
*/


/*
// =======================================================
// 2. Count Subarrays With At Most K Zeros (Binary Array)
// =======================================================
Given a BINARY array (only 0s and 1s) and an integer K,
count how many subarrays contain AT MOST K zeros.
Return that count.
*/


/*
// =======================================================
// 3. Longest Substring With At Most K Distinct Characters
// =======================================================
Given a string s and an integer K,
find the length of the LONGEST substring that contains
AT MOST K distinct characters.
Return the length.
*/






int main() {
   // ==============================
    // TESTCASE 1
    // ==============================
    vector<int> v1 = {1, 0, 1, 1, 0, 1};
    int k1 = 3;
    int m1 = 1;
    cout << "Output: " << count_zeros(v1, k1, m1) << " // Expected: 4" << endl;

    // ==============================
    // TESTCASE 2
    // ==============================
    vector<int> v2 = {0, 0, 0, 0};
    int k2 = 2;
    int m2 = 0;
    cout << "Output: " << count_zeros(v2, k2, m2) << " // Expected: 0" << endl;

    // ==============================
    // TESTCASE 3
    // ==============================
    vector<int> v3 = {1, 1, 1, 1, 1};
    int k3 = 3;
    int m3 = 3;
    cout << "Output: " << count_zeros(v3, k3, m3) << " // Expected: 3" << endl;

    // ==============================
    // TESTCASE 4
    // ==============================
    vector<int> v4 = {0, 1, 0, 1, 0, 1, 1};
    int k4 = 4;
    int m4 = 2;
    cout << "Output: " << count_zeros(v4, k4, m4) << " // Expected: 4" << endl;

    // ==============================
    // TESTCASE 5
    // ==============================
    vector<int> v5 = {1, 0, 0, 1, 1, 0, 1};
    int k5 = 3;
    int m5 = 1;
    cout << "Output: " << count_zeros(v5, k5, m5) << " // Expected: 3" << endl;

    // ==============================
    // TESTCASE 6 (Edge Case: k == 1)
    // ==============================
    vector<int> v6 = {0, 1, 0, 1};
    int k6 = 1;
    int m6 = 0;
    cout << "Output: " << count_zeros(v6, k6, m6) << " // Expected: 2" << endl;

    // ==============================
    // TESTCASE 7 (Mixed + Larger k)
    // ==============================
    vector<int> v7 = {1,1,0,1,0,0,1,1,1};
    int k7 = 5;
    int m7 = 2;
    cout << "Output: " << count_zeros(v7, k7, m7) << " // Expected: 3" << endl;

    return 0;
}