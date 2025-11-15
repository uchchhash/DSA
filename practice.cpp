
#include<bits/stdc++.h>
using namespace std;


void print_vector(const vector<int> &v, const string &name){
    cout << name << " [Size : " << v.size() <<" ] = ";
    for(int x : v){
        cout<< x << " ";
    }
    cout<<endl;
}


void print_v(const vector<int> &v, const string name){
    cout<<"Name : "<<name<< " (Size : "<<v.size()<<") = ";
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    print_v(v, "1D Vector");


    // Different Ways to Initialize 
    vector<int> a(5); 
    vector<int> b(5, 10);
    vector<int> c = {1, 2, 3, 4, 5};

    print_v(a, "a");
    print_v(b, "b");
    print_v(c, "c");

    // Accessing Vector Elements 
    cout<< "v[0] = " << v[0] <<endl;
    cout<< "v[1] = " << v[1] <<endl;
    cout<< "v.at(2) = " << v.at(2) <<endl;
    
    cout<< "v.front() = " << v.front()<<endl;
    cout<< "v.back()  = " << v.back() <<endl;

    cout << "\n";
    cout << "\n";

    // Iterating over vector 
    for(int i =0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    cout << "\n";
    cout << "\n";


    for(int x:v){
        cout << x <<endl;
    }

    cout << "\n";
    cout << "\n";

    // referene based 
    for(int &x:v){
        x = x*2; // doubling each element
    }

    print_v(v, "V after doubling");

    // Iterators 
    for(auto it = v.begin(); it != v.end(); it++){
        cout<< " it = "<< *it <<endl; 
    }

    cout << "\n";
    cout << "\n";

    vector<int> cap_test;
    cout << "Pushing 1..10 and printing size & capacity:\n";
    for(int i=0; i<10; i++){
        cap_test.push_back(i);
        cout<<"Capacity = "<<cap_test.capacity()<<endl;
        cout<<"Size = "<<cap_test.size()<<endl;
        cout<<endl;
    }


    // modifying contents
    // insert, erase, pop_back, clear, resize 

    vector<int> m = {10, 20, 30, 40};
    m.insert(m.begin()+1, 99);
    m.erase(m.end()-1);
    m.resize(10);
    m.clear();

    // two dimentional vector
    int rows = 3, cols = 4;
    vector<vector<int>> M(rows, vector<int>(cols, 0));

    int val = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

        }
    }

}






