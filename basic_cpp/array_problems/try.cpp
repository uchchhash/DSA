
#include<bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std; 






/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */
long aVeryBigSum(vector<long> ar) {
    long sum = 0;
    for(int i=0; i<ar.size(); i++){
        sum += ar[i];
    }
    return sum;
}


/*
 * 
 The rating for Alice's challenge is the triplet a = (a[0], a[1], a[2]), and 
 The rating for Bob's challenge is the triplet b = (b[0], b[1], b[2]).
 The task is to find their comparison points by 
 comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then Alice is awarded 1 point.
If a[i] < b[i], then Bob is awarded 1 point.
If a[i] = b[i], then neither person receives a point.

Comparison points is the total points a person earned.
Given a and b, determine their respective comparison points.

 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */



vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int aSum = 0; 
    int bSum = 0;
    vector<int> resultVector;
    for(int i=0; i<a.size(); i++){
        if(a[i] > b[i]) aSum++;
        else if (a[i] < b[i]) bSum++;
    }
    resultVector.push_back(aSum);
    resultVector.push_back(bSum);
    return resultVector;
}


int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for(int i=0; i<ar.size(); i++){
        sum += ar[i];
    }
    return sum;
}

int main() {
    vector<int> vectorOne;
    vector<int> vectorTwo;
    vector<int> vectorThree;

    vectorOne.push_back(10);
    vectorOne.push_back(20);
    vectorOne.push_back(30);
    vectorOne.push_back(40);
    vectorOne.push_back(50);
    for(auto& i : vectorOne){
        printf("vectorOne element: %d\n", i);  // Dereference the iterator to get the value
    }  
    cout << endl;
    cout << endl;

    int start = 0;
    int end = vectorOne.size() -1;
    for (int i = 0; i < vectorOne.size() / 2; i++) {
        int temp = vectorOne[start];
        vectorOne[start] = vectorOne[end];
        vectorOne[end] = temp;
        start++;
        end--;
     }
    cout << "Reversed Array: ";
    for (int i = 0; i < vectorOne.size(); i++) {
        cout << vectorOne[i] << " ";
    }
    cout << endl;
    
    int vectorSum;
    vectorSum = simpleArraySum(vectorOne);
    printf("vector sum : %d\n", vectorSum);



    vector<int> a = {5, 3, 7};
    vector<int> b = {3, 6, 10};

    // Call the compareTriplets function
    vector<int> result = compareTriplets(a, b);

    // Print the result
    cout << "Result: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    vector<long> arr = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
    long sumResult;
    sumResult = aVeryBigSum(arr);
    printf("sumResult = %d", sumResult);
 



    // 0 1 2 3 4
    // 0 - 4 3 2 1 0
    // 1 - 4 3 2 1 0
    // 2 - 4 3 2 1 0
    // 3 - 4 3 2 1 0
    // 4 - 4 3 2 1 0

    // 4 3 2 1 0
    // begin 0 : end 4
    // begin++ : end-- 0,4 // 1,3 // 2,2 // 3,1 // 4,0
    //
    // for(vector<int>::iterator it = vectorOne.begin(); it !=vectorOne.end(); it++){
    //     // auto vectorTemp = vectorOne[vectorOne.begin()++];
    //     // // vectorOne[vectorOne.begin()++] = vectorOne[vectorOne.end()--];
    //     // // vectorOne[vectorOne.end()--] = vectorTemp;
    //     printf("vectorOne element: %d\n", *it);  // Dereference the iterator to get the value
    // }
    // cout <<endl;
    // for(auto& i : vectorOne){
    //     printf("vectorOne element: %d\n", i);  // Dereference the iterator to get the value
    // }

    return 0;
}
