// ============================
// ✅ LEVEL-1: Basic Problems
// ============================
// 1. Find the index of a target value in an array using linear search.
// 2. Find the index of a target value in a sorted array using binary search.
// 2.1 Find all the indexes of a target value in a sorted array using binary search.
// 3. Count how many times a target value appears in an array.
// 4. Find the minimum and maximum values in an array.
// 5. Find the first index where the value in a sorted array is greater than or equal to a given target.
// ====================================
// ✅ LEVEL-2: Binary Search Variants
// ====================================
// 6. Find the first occurrence of a target value in a sorted array.
// 7. Find the last occurrence of a target value in a sorted array.
// 8. Given a sorted array, count how many times a target value appears using binary search only.
// 9. Find the smallest value in a rotated sorted array.
// 10. Search for a target value in a rotated sorted array.
// ========================================
// ✅ LEVEL-3: Binary Search on Properties
// ========================================
// 11. Compute the integer square root of a number using binary search.
// 12. Compute the square root of a number up to six decimal places using binary search.
// 13. Given an array that strictly increases and then strictly decreases, find the index of the peak element.
// 14. Given a function isBadVersion(version), find the first bad version from 1 to n.
// 15. Given a sorted array of 0s and 1s, find the index of the first 1.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Helpter Methods
void input_array(vector<int> &v){
    cout<<"Size of the array = "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<"Enter the Elements ["<<i<<"] = ";
        cin>>v[i];
    }
}

void print_array(vector<int> &v, const string name){
    cout << "Array Name :: "<<name<<endl;
    for(int x:v) cout<< x << " ";
    cout<<endl;
}


//     priority_queue<int> fromVec(values.begin(), values.end());

// Sorting an array using priority queue 
void sort_array(vector<int> &v){
    priority_queue<int> sortThisVector(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--){
        v[i] = sortThisVector.top();
        sortThisVector.pop();
    }
    print_array(v, "Sorted");
}


// 1. Find the index of a target value in an array using linear search.
void find_index(vector<int> &v, int target){

    for(int i=0; i<v.size(); i++){
        if(target == v[i]) {
            cout<<"Found [Target = "<<target<<"]"<<" at index ["<<i<<"]"<<endl; 
            return;
        }
    }
    cout<<"Target is not in the Array"<<endl; 
}


// 2. Find the index of a target value in a sorted array using binary search.
void find_index_bin(vector<int> &v, int target){
    // Binary search needs and sorted array
    sort_array(v);
    int first = 0; 
    int last = v.size()-1;
    int mid;
    bool result = false;
    while(first<=last){
        mid = first + (last - first) / 2;
        if(target == v[mid]){
            cout<<"Found target at ["<<mid<<"] "<<endl;
            result = true;
            break;
        }
        else if(target > v[mid]) first = mid+1;
        else last = mid-1;
    }
    if(result == false) cout << "Target not found in the array"<<endl;
}


// 2.1 Find all the indexes of a target value in a sorted array using binary search.

void find_all_index_bin(vector<int> v, int target){
    // Binary search needs and sorted array
    sort_array(v);
    int first = 0;
    int last = v.size()-1;
    int mid;
    bool result;

    while(first<=last){
        mid = first + (last-first)/2;
        if(target == v[mid]){
            result = true;
            
            // Target found at the midpoint, lets search left of mid
            int left=mid;
            while(left >=0 && v[left-1]==target) left--;

            // Target found at the midpoint, lets search right of mid
            int right=mid;
            while(right + 1 < v.size() && v[right + 1] == target) right++;

            cout << "Found target at indices: ";
            for(int i = left; i <= right; i++)
                cout << "[" << i << "] ";
            cout << endl;

            // Stop search completely
            break;

        }
        else if(target > v[mid]) first = mid+1;
        else last = mid-1;
    }
    if(result == false) cout << "Target not found in the array"<<endl;
}

// 6. Find the first occurrence of a target value in a sorted array.
int find_first(const vector<int> &v, int target){
    int first = 0, last = v.size()-1, ans = -1;
    while(first <= last){
        int mid = first + (last - first) / 2;
        if(v[mid] == target){
            ans = mid;
            last = mid - 1;        // go left
        }
        else if(v[mid] > target){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    return ans;
}

// 7. Find the last occurrence of a target value in a sorted array.
int find_last(const vector<int> &v, int target){
    int first = 0, last = v.size()-1, ans = -1;
    while(first <= last){
        int mid = first + (last - first) / 2;
        if(v[mid] == target){
            ans = mid;
            first = mid + 1;       // go right
        }
        else if(v[mid] > target){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    return ans;
}

void find_all_occurrences(vector<int> &v, int target){
    sort(v.begin(), v.end());

    int first = find_first(v, target);
    int last  = find_last(v, target);

    if(first == -1){
        cout << "Target not found\n";
        return;
    }

    cout << "Target found at indices: ";
    for(int i = first; i <= last; i++)
        cout << "[" << i << "] ";
    cout << "\n";
}



int main(){

    // 1. Find the index of a target value in an array using linear search.
    int n;
    cout<<"Enter the Size of the input Array = ";
    cin>>n;
    vector<int> v(n);
    input_array(v);

    int target;
    cout<<"Enter the target element to search = ";
    cin>>target;
    find_index(v, target);

    // 2. Find the index of a target value in a sorted array using binary search.
    find_index_bin(v, target);

    // 2.1 Find all the indexes of a target value in a sorted array using binary search.
    // 3. Count how many times a target value appears in an array.
    find_all_index_bin(v, target);


    return 0;
}