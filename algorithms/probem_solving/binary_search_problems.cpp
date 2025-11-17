// ====================================
// ✅ Binary Search Problems
// ====================================
// 1. Find the first occurrence of a target value in a sorted array.
// 2. Find the last occurrence of a target value in a sorted array.
// 3. Given a sorted array, count how many times a target value appears using binary search only.
// 4. Find the smallest value in a rotated sorted array.
// 5. Search for a target value in a rotated sorted array.


#include<bits/stdc++.h>
using namespace std;


void input_array(vector<int> &v){
    cout<<"Size of the array = "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<"Enter the Elements ["<<i<<"] = ";
        cin>>v[i];
    }
}

void print_array(vector<int> &v, const string name){
    cout << "Array Name :: "<<name<<" ";
    for(int x:v) cout<< x << " ";
    cout<<endl;
}

// Array sorting using priority queue
void sort_array(vector<int> &v){
    priority_queue<int> pq; // Max-Heap-By-Default // Descending
    for(int x : v) pq.push(x);
    // Make it ascending
    for(int i=v.size()-1; i>=0; i--){ // Reverse order (min-to-max)
        v[i] = pq.top();
        pq.pop();
    }
    print_array(v, "Sorted Ascending = ");
}

// 1. Find the first occurrence of a target value in a sorted array.
int find_first(vector<int> &v, int target){
    sort_array(v); // Binary search works on sorted array
    int first = 0;
    int last  = v.size()-1;
    int mid   = 0;
    bool result = false;
    int index;
    while(first<=last){
        mid = first + (last-first)/2;
        if(target == v[mid]){
            result = true;
            index = mid; // found index at the middle
            last = mid-1; // search left
        }
        else if (target > v[mid]){
            first = mid+1; // target in upper region
        }
        else last = mid-1; // target in lower region
    }
    if(!result) {
        cout<<"Target Not Found";
        index = -1;
    }
    else cout <<"Target Found at First Index = "<<index<<endl;
    return index;
}


// 2. Find the last occurrence of a target value in a sorted array.
int find_last(vector<int> &v, int target){
    int first = 0;
    int last = v.size()-1;
    int mid = 0;
    int index = 0;
    bool result = false;
    while(first<=last){
        mid = first + (last-first)/2;
        if(target == v[mid]){
            result = true;
            index = mid; // Found target at middle
            first = mid + 1; // search upper half
        }
        else if(target < v[mid]){
            last = mid -1; // search lower half 
        }
        else first = mid +1; // search upper half
    }
    if(!result) {
        cout<<"Target Not Found";
        index = -1;
    }
    else cout <<"Target Found at Last Index = "<<index<<endl;
    return index;
}


// 3. Given a sorted array, count how many times a target value appears using binary search only.
void index_count(vector<int> &v, int target){
    sort_array(v); // Sort the array in ascending for binary search
    int first_index = 0;
    int last_index  = 0;
    first_index = find_first(v, target);
    last_index  = find_last(v, target);
    int count = (last_index - first_index) + 1;
    for(int i=first_index; i<=last_index; i++){
        cout<<"Target ["<<target<<"]"<<" found in the indexes = ";
        cout<<i<<" "<<endl;
    }
    cout<<"Total appearences = "<<count<<" "<<endl;
}

// A rotated sorted array.
// 1 2 3 4 - 5 6 7 8
// rotated_index = 3
// 5 6 7 8 - 1 2 3 4
void rotated_sorted(vector<int> &v, int rotated_index){
    // Step 1: sort the array
    sort_array(v);

    // Step 2: prepare new array
    vector<int> rotated;

    // Step 3: add the right side (after pivot)
    for(int i = rotated_index + 1; i < v.size(); i++){
        rotated.push_back(v[i]);
    }

    // Step 4: add the left side (0 to pivot)
    for(int i = 0; i <= rotated_index; i++){
        rotated.push_back(v[i]);
    }

    // Step 5: copy back
    v = rotated;
    cout<<"Rotated Sorted Index = "<<rotated_index<<endl;
    print_array(v, "Rotated Sorted = ");
}

// 4. Find the smallest value in a rotated sorted array.
int findMin(const vector<int> &v){
    int left = 0, right = v.size() - 1;

    // If array is not rotated
    if(v[left] <= v[right])
        return v[left];

    while(left < right){
        int mid = left + (right - left) / 2;

        // If mid element is greater than the rightmost element,
        // the min must be to the right of mid
        if(v[mid] > v[right])
            left = mid + 1;
        else
            right = mid; // min is at mid or to the left
    }
    return v[left];
}

// 5. Search for a target value in a rotated sorted array.
int searchRotated(const vector<int> &v, int target){
    int left = 0, right = v.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(v[mid] == target) return mid; // found

        // Check if left half is sorted
        if(v[left] <= v[mid]){
            if(v[left] <= target && target < v[mid])
                right = mid - 1;   // target in left half
            else
                left = mid + 1;    // target in right half
        }
        else { // right half is sorted
            if(v[mid] < target && target <= v[right])
                left = mid + 1;    // target in right half
            else
                right = mid - 1;   // target in left half
        }
    }

    return -1; // target not found
}

// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

int missing_number(vector<int> &v, int n) {
    sort_array(v); // ascending order

    // Check if 0 is missing
    if(v[0] != 0) return 0;

    // Check internal gaps
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i+1] - v[i] > 1)
            return v[i] + 1;
    }

    // If no gaps, missing number is n
    return n;
}



int main(){

    int n = 0;
    cout<<"Enter the number of elements = ";
    cin>>n;

    vector<int> v(n);
    input_array(v);
    print_array(v, "before sorted ");
   // sort_array(v);
   // print_array(v, "after sorted");


//     int target = 0;
//     cout<<"Enter the target value = ";
//     cin>>target;
//     int first_index, last_index;
//   //  first_index = find_first(v, target);
//   //  last_index = find_last(v, target);

//     index_count(v, target);

//     int rotate_index;
//     cout<<"Rotate the array after index = ";
//     cin>>rotate_index;
//     rotated_sorted(v, rotate_index);
    
    int missed;
    missed = missing_number(v, n);
    if(missed<0) cout<<"No Missing Number"<<endl;
    else cout<<"The missing number is = "<<missed<<endl;

    
    return 0;
}

