
#include<bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std; 

int main() {
    vector<int> vectorOne;

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
