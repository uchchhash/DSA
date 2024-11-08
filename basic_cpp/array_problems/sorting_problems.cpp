#include<bits/stdc++.h>
#include<iostream>
#include<utility>
using namespace std; 


// pair<int, int> sortArrayPairs(pair <int, int>){
//     for(int i=0; i<sizeof(a)/sizeof(a[0])-1; i++){
//         if(a[i].second == a[i+1].second){
//             cout << "seconds-are-same-decending" <<endl;
//             if(a[i].first < a[i+1].first){
//                 int swap1 = a[i].first;
//                 a[i].first = a[i+1].first;
//                 a[i+1].first = swap1;
//                 }
//             }
//         else if (a[i].second > a[i+1].second){
//             int swap2 = a[i].second;
//             a[i].second = a[i+1].second;
//             a[i+1].second = swap2;
//             cout << "decending . . ." <<endl;
//         }
//         else cout << "do-nothing" <<endl;
//     }
// }


int main() {

    pair<int, int> a[] = {{1,1},{2,1},{4,1},{7,5},{3,3},{2,4}};
    // sort it according to second element ascending
    // if second element is same, then sort
    // it according to first element in decending

    for(int i=0; i<sizeof(a)/sizeof(a[0])-1; i++){
        if(a[i].second == a[i+1].second){
            cout << "seconds-are-same-decending" <<endl;
            if(a[i].first < a[i+1].first){
                int swap1 = a[i].first;
                a[i].first = a[i+1].first;
                a[i+1].first = swap1;
                }
            }
        else if (a[i].second > a[i+1].second){
            int swap2 = a[i].second;
            a[i].second = a[i+1].second;
            a[i+1].second = swap2;
            cout << "decending . . ." <<endl;
        }
        else cout << "do-nothing" <<endl;
    }
    // Loop through each pair and print in one line
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        std::cout << "(" << a[i].first << ", " << a[i].second << ")";
        if (i != sizeof(a) / sizeof(a[0]) - 1) {
            std::cout << ", "; // Add comma between pairs, but not after the last pair
        }
    }
    std::cout << std::endl; // Newline after all pairs are printed
   
}