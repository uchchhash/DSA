

#include<bits/stdc++.h>
#include<iostream>
#include<utility>
using namespace std; 


// 7789 % 10 = 9
// 7789 / 10 = 778
// 778 % 10 = 8
// 778 / 10 = 77
// 77 % 10 = 7
// 7 % 7 = 0
void displayDigits(int N){
    while(N>0){
        int lastdigit = N % 10;
        cout << lastdigit << endl;
        N = N/10;
    }
}

int countDigits(int N){
    int count=0;
    while(N>0){
        N = N/10;
        count++;
    }
    return count;
}

int reverseNumbers(int N){
    int revN = 0;
    while(N>0){
        int lastDigit = N % 10;
        N = N / 10;
        revN = (revN*10) + lastDigit;
    }
}

int main() {

    int x = 7789;

    displayDigits(7789);
    
    int count=0;
    count = countDigits(154856);
    printf(" digit-count = %d ", count);
    int revN;
    revN = reverseNumbers(5789);
    cout << "reverse-number = " << revN <<endl;
}