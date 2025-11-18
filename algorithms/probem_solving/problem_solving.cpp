/*
// =======================================================
1. First Index ≥ X in a Sorted Array
// =======================================================
    You are given a sorted array of integers (non-decreasing order) and an integer x.
    Find the smallest index i such that arr[i] >= x.
    If no such index exists, print -1.
*/


/*
// =======================================================
2. Stable Sorting of Tasks by Priority
// =======================================================
    You are given n tasks. Each task has:
    - an integer id
    - an integer priority
    Sort the tasks by increasing priority.
    If two tasks have the same priority, keep their original input order (stable sort).
    Print the ids in the final order.
*/


/*
// =======================================================
3. Count Pairs With Sum in a Range
// =======================================================
    Given an array of integers and two integers L and R,
    count how many pairs (i, j) with i < j satisfy:
        L <= arr[i] + arr[j] <= R
    Print the count.
*/


/*
// =======================================================
4. Longest Subarray With At Most K Zeros
// =======================================================
    Given a binary array (containing only 0 and 1) and an integer K,
    you may flip at most K zeros to ones.
    Find the maximum length of a contiguous subarray that can contain only ones
    after at most K flips.
*/


/*
// =======================================================
5. Partition Around a Pivot Value
// =======================================================
    Given an array of integers and an integer p,
    rearrange the array in-place so that:
      - all elements < p come first
      - then all elements == p
      - then all elements > p
    Output the final array after partitioning.
*/


/*
// =======================================================
6. Smallest Missing Positive Integer
// =======================================================
    Given an array of integers (can include negatives, zero, positives, duplicates),
    find the smallest positive integer that does NOT appear in the array.

    Example:
        Input: [3, 4, -1, 1]
        Output: 2
*/


/*
// =======================================================
7. Majority Element Check
// =======================================================
    Given an array of integers, determine if there is a value that appears
    strictly more than n/2 times (where n is the array size).
    If such a value exists, print it.
    Otherwise, print "NO".
*/


/*
// =======================================================
8. Closest Pair to a Target Sum
// =======================================================
    You are given a sorted array of integers and a target T.
    Find a pair (i, j) with i < j such that:
        arr[i] + arr[j]
    is as close as possible to T in absolute difference.
    If multiple pairs are equally close, any one is acceptable.
    Print the pair (the two values).
*/


/*
// =======================================================
9. Rotation Count in a Rotated Sorted Array
// =======================================================
    You are given an array originally sorted in increasing order,
    then rotated some number of times. All elements are distinct.

    Example:
        Original: [1, 2, 3, 4, 5]
        Rotated:  [3, 4, 5, 1, 2]  -> Rotated 3 times

    Find and print the rotation count k (index of the smallest element).
*/


/*
// =======================================================
10. Longest Substring With At Most K Distinct Characters
// =======================================================
    Given a string s and an integer K,
    find the length of the longest substring that contains
    at most K distinct characters.

    Example:
        s = "aabacbebebe", K = 3
        Output: length of the longest valid substring.
*/





#include<bits/stdc++.h>
using namespace std;



void input_array(vector<int> &v, int v_size){
    for(int i=0; i<v_size; i++){
        cout<<"Enter Array Elements ["<<i<<"] = ";
        cin>>v[i];
    }
    cout<<endl;
}

void print_array(vector<int> &v, const string name){
    cout<<"Array Name = "<<name<<" || "<<"Size = ["<<v.size()<<"]"<<" Elements = ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



// Sorting Array; Ascending or Descending
void sort_array(vector<int> &v, int v_size, int ascending){
    for(int i = 0; i<v_size-1; i++){
        for(int j=i+1; j<v_size; j++){
            // Compare and Swap
            if(ascending){
                if(v[i]>v[j]){
                    int temp = v[j];
                    v[j] = v[i];
                    v[i] = temp;
                }
            }
            else if(!ascending){
                if(v[i]<v[j]){
                    int temp = v[j];
                    v[j] = v[i];
                    v[i] = temp;
                }
            }
        }
    }
    print_array(v, "Sorted");
}


// // =======================================================
// 1. First Index ≥ X in a Sorted Array
// // =======================================================
//     You are given a sorted array of integers (non-decreasing order) and an integer x.
//     Find the smallest index i such that arr[i] >= x.
//     If no such index exists, print -1.

int find_smallest_index(vector<int> &v, int target){
    sort_array(v, v.size(), 1);
    int left = 0;
    int right = v.size();
    int mid;
    bool result = false;
    int index;
    while(left<=right){
        mid = left + (right-left)/2;
        if(v[mid] == target){
            index = mid; // found target at mid
            right = mid-1; // search left for smallest index
            result = true;
        }
        else if(target>v[mid]){
            left = mid + 1; // search right of mid
        }
        else right = mid - 1; // target on the left of mid
    }
    if(result == true){
        cout<<"Target ["<<target<<"]"<<" found at Index ["<<index<<"]"<<endl;
        return index;
    }
    else return -1;
    cout<<endl;
}

// // =======================================================
// 2. Stable Sorting of Tasks by Priority
// // =======================================================
//     You are given n tasks. Each task has:
//     - an integer id
//     - an integer priority
//     Sort the tasks by increasing priority.
//     If two tasks have the same priority, keep their original input order (stable sort).
//     Print the ids in the final order.


struct Task {
    int id;
    int priority;
};

void input_tasks(vector<Task> &v, int n){
    v.resize(n); // ensure vector has n slots

    for(int i = 0; i < n; i++){
        cout << "Enter Task ID [" << i << "]: ";
        cin >> v[i].id;

        cout << "Enter Task Priority [" << i << "]: ";
        cin >> v[i].priority;

        cout << endl;
    }
}

void stable_sorting(vector<Task> &v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        Task key = v[i];
        int j = i - 1;

        // Move elements greater than key.priority to the right
        while (j >= 0 && v[j].priority > key.priority) {
            v[j + 1] = v[j];
            j--;
        }

        // Insert the key into its correct position
        v[j + 1] = key;
    }
}


// // =======================================================
// 3. Count Pairs With Sum in a Range
// // =======================================================
//     Given an array of integers and two integers L and R,
//     count how many pairs (i, j) with i < j satisfy:
//         L <= arr[i] + arr[j] <= R
//     Print the count.

void count_pairs_with_sum(vector<int> &v, int left, int right){
    sort_array(v, v.size(), 1);
    int count =0;
    int sum = 0;
    for(int i=0; i<v.size()-1; i++){
        for(int j=i; j<v.size(); j++){
            sum = v[i]+v[j];
            cout<<"sum = "<<sum<<" ";
            if(sum>=left && sum<=right){
                count++;
            }
            else count = count;
        }
    }
    cout<<"|| Left = "<<left<<" "<<"RIght = "<<right<<" ||";
    cout<<"Satisfied Count = "<<count<<endl;
    cout<<endl;
}



int count_pairs_with_sum_modified(vector<int> &v, int L, int R) {
    sort(v.begin(), v.end()); // sort ascending
    int n = v.size();
    int count = 0;

    for(int i = 0; i < n-1; i++) {
        // Find first index j > i such that v[i]+v[j] >= L
        int low = i+1, high = n-1, start = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(v[i] + v[mid] >= L){
                start = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        // Find last index j > i such that v[i]+v[j] <= R
        low = i+1, high = n-1;
        int end = i;
        while(low <= high){
            int mid = (low + high)/2;
            if(v[i] + v[mid] <= R){
                end = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        // Count pairs in this range
        if(end >= start) count += (end - start + 1);
    }

    return count;
}

// // =======================================================
// 4. Longest Subarray With At Most K Zeros
// // =======================================================
//     Given a binary array (containing only 0 and 1) and an integer K,
//     you may flip at most K zeros to ones.
//     Find the maximum length of a contiguous subarray that can contain only ones
//     after at most K flips.


void longest_subarray_with_k_zero(vector<int> &v, int K) {
    int n = v.size();
    int left = 0;
    int zeros = 0;
    int max_length = 0;

    for (int right = 0; right < n; right++) {
        if (v[right] == 0) zeros++;

        // Shrink window until zeros <= K
        while (zeros > K) {
            if (v[left] == 0) zeros--;
            left++;
        }

        // Update max_length without using max()
        int current_length = right - left + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    cout << "Max-Length = " << max_length << endl;
}






int main(){

   // vector<int> v = {5, 7, 1, 9, 0, 3};
   // print_array(v, "Before Sorted");
    //sort_array(v, v.size(), 0);
   // print_array(v, "After Sorted");

    // int s;
    // cout<<"Enter Size of Array = ";
    // cin>>s;
    // vector<int> v(s);
    // input_array(v, s);

    // int smallest_index;
    // int n;
    // cout<<"Enter the target to Search = ";
    // cin>>n;

    // smallest_index = find_smallest_index(v, n);
    // cout<<"The smallest index = "<<smallest_index<<endl;

    // int n;
    // cout << "Enter number of tasks: ";
    // cin >> n;

    // vector<Task> tasks;
    // input_tasks(tasks, n);

    // stable_sorting(tasks); // your manual insertion sort

    // cout << "Sorted order of IDs with respective Priorities: ";
    // for (auto &t : tasks) {
    //     cout << t.id << " :: "<< t.priority<<"||  ";
    // }
    // cout << endl;



    // vector<int> v1 = {1,2,3,4,5};
    // cout << count_pairs_with_sum_modified(v1, 4, 7) << endl; // 7

    // vector<int> v2 = {0,0,0};
    // cout << count_pairs_with_sum_modified(v2, 0, 0) << endl; // 3

    // vector<int> v3 = {1,2,4,5};
    // cout << count_pairs_with_sum_modified(v3, 3, 5) << endl; // 2

    // vector<int> v4 = {10,20,30,40};
    // cout << count_pairs_with_sum_modified(v4, 50, 60) << endl; // 3

    // vector<int> v5 = {1,1,1,1};
    // cout << count_pairs_with_sum_modified(v5, 2, 2) << endl; // 6

    // vector<int> v6 = {-2,-1,0,1,2};
    // cout << count_pairs_with_sum_modified(v6, -1, 1) << endl; // 6

    vector<int> v1 = {1,1,0,1,0,1,1,1};
    longest_subarray_with_k_zero(v1, 1); // should be 5

    vector<int> v5 = {0,1,0,1,1,0,1,1,1};
    longest_subarray_with_k_zero(v5, 3); // should be 9

    vector<int> v6 = {1,0,0,1,1,0,1,0,1,1};
    longest_subarray_with_k_zero(v6, 2); // should be 7




    return 0;
}