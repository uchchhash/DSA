#include <bits/stdc++.h>
using namespace std;

// Small helper to print a 1D vector nicely
void print_vec(const vector<int> &v, const string &name) {
    cout << name << " (size=" << v.size() << "): ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// Helper to print a 2D vector (matrix style)
void print_2d(const vector<vector<int>> &M, const string &name) {
    cout << name << " (rows=" << M.size() << "):\n";
    for (int i = 0; i < (int)M.size(); i++) {
        cout << "  row " << i << ": ";
        for (int x : M[i]) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

// Example to show passing vectors to functions
void add_one_to_all(vector<int> &v) {
    // passed by reference -> changes affect caller
    for (int &x : v) {
        x += 1;
    }
}

int main() {

    // ============================================================
    // 1. BASIC DECLARATION + PUSH_BACK + VISUAL
    // ============================================================
    cout << "================ 1. BASIC VECTOR =================\n\n";

    // Empty vector of int
    vector<int> v;

    // push_back appends at the end, grows size dynamically
    v.push_back(10);  // v: [10]
    v.push_back(20);  // v: [10, 20]
    v.push_back(30);  // v: [10, 20, 30]

    /*
        Visual:

        Index:   0    1    2
        v    = [10,  20,  30]

        size() = 3  → number of elements currently stored
    */

    print_vec(v, "v");

    cout << "v.size() = " << v.size() << "\n\n";


    // ============================================================
    // 2. DIFFERENT WAYS TO INITIALIZE
    // ============================================================
    cout << "================ 2. INITIALIZATION =================\n\n";

    vector<int> a(5);        // size 5, all 0 by default
    vector<int> b(5, 7);     // size 5, all 7
    vector<int> c = {1, 2, 3, 4}; // initializer list

    print_vec(a, "a");
    print_vec(b, "b");
    print_vec(c, "c");

    /*
        Visual:

        a: [0, 0, 0, 0, 0]
        b: [7, 7, 7, 7, 7]
        c: [1, 2, 3, 4]
    */

    cout << "\n";


    // ============================================================
    // 3. ACCESSING ELEMENTS: [], at(), front(), back()
    // ============================================================
    cout << "================ 3. ACCESSING ELEMENTS =================\n\n";

    cout << "v[0] = " << v[0] << "\n";       // no bounds check
    cout << "v[1] = " << v[1] << "\n";
    cout << "v.at(2) = " << v.at(2) << "\n"; // throws if index invalid

    cout << "v.front() = " << v.front() << "\n"; // first element
    cout << "v.back()  = " << v.back()  << "\n"; // last element

    /*
        Always make sure index is in range: 0 <= i < v.size()
    */

    cout << "\n";


    // ============================================================
    // 4. ITERATING OVER VECTOR
    // ============================================================
    cout << "================ 4. ITERATING =================\n\n";

    cout << "Using classic index-based for:\n";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "  v[" << i << "] = " << v[i] << "\n";
    }
    cout << "\n";

    cout << "Using range-based for (copy each element):\n";
    for (int x : v) {
        cout << "  value = " << x << "\n";
    }
    cout << "\n";

    cout << "Using range-based for with reference (modify in-place):\n";
    for (int &x : v) {
        x *= 2; // double each element
    }
    print_vec(v, "v after doubling");

    cout << "\nUsing iterators explicitly:\n";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "  *it = " << *it << "\n";
    }
    cout << "\n";


    // ============================================================
    // 5. SIZE vs CAPACITY (rough idea)
    // ============================================================
    cout << "================ 5. SIZE vs CAPACITY =================\n\n";

    vector<int> cap_test;
    cout << "Pushing 1..10 and printing size & capacity:\n";
    for (int i = 1; i <= 10; i++) {
        cap_test.push_back(i);
        cout << "  i=" << i
             << "  size=" << cap_test.size()
             << "  capacity=" << cap_test.capacity() << "\n";
    }
    cout << "\n";
    /*
        size()     → how many elements are in use
        capacity() → how many elements can fit before reallocation

        Internally, vector sometimes allocates extra memory so it
        doesn't need to reallocate with every push_back.
    */


    // ============================================================
    // 6. MODIFYING CONTENTS: insert, erase, pop_back, clear, resize
    // ============================================================
    cout << "================ 6. MODIFYING CONTENTS =================\n\n";

    vector<int> m = {10, 20, 30};
    print_vec(m, "m start");

    // insert 99 at index 1
    m.insert(m.begin() + 1, 99); // m: [10, 99, 20, 30]
    print_vec(m, "m after insert 99 at index 1");

    // erase element at index 2 (20)
    m.erase(m.begin() + 2);      // m: [10, 99, 30]
    print_vec(m, "m after erase index 2");

    // pop_back removes last element (30)
    m.pop_back();                // m: [10, 99]
    print_vec(m, "m after pop_back");

    // resize: change size; new elements become 0
    m.resize(5);                 // m: [10, 99, 0, 0, 0]
    print_vec(m, "m after resize(5)");

    // clear: remove all elements (size=0)
    m.clear();
    print_vec(m, "m after clear");


    // ============================================================
    // 7. STANDALONE ALGORITHMS ON VECTOR: sort, reverse, find, count
    // ============================================================
    cout << "\n================ 7. STL ALGORITHMS =================\n\n";

    vector<int> u = {5, 1, 7, 3, 3, 9, 3};
    print_vec(u, "u start");

    // sort ascending
    sort(u.begin(), u.end()); // [1, 3, 3, 3, 5, 7, 9]
    print_vec(u, "u after sort ascending");

    // reverse
    reverse(u.begin(), u.end());
    print_vec(u, "u after reverse");

    // find first occurrence of 3
    auto it3 = find(u.begin(), u.end(), 3);
    if (it3 != u.end()) {
        int idx = (int)(it3 - u.begin());
        cout << "First 3 found at index " << idx << "\n";
    } else {
        cout << "3 not found\n";
    }

    // count how many 3s
    int c3 = count(u.begin(), u.end(), 3);
    cout << "Number of 3s = " << c3 << "\n\n";


    // ============================================================
    // 8. PASSING VECTOR TO FUNCTIONS
    // ============================================================
    cout << "================ 8. PASSING TO FUNCTIONS =================\n\n";

    vector<int> func_v = {1, 2, 3};
    print_vec(func_v, "func_v before add_one_to_all");

    add_one_to_all(func_v); // passed by reference
    print_vec(func_v, "func_v after add_one_to_all");


    // ============================================================
    // 9. 2D VECTORS: FIXED MATRIX
    // ============================================================
    cout << "\n================ 9. 2D VECTORS (FIXED MATRIX) =================\n\n";

    /*
        2D vector (matrix) as 3x4:

        M:
          row 0: [a00, a01, a02, a03]
          row 1: [a10, a11, a12, a13]
          row 2: [a20, a21, a22, a23]

        Indexing: M[row][col]
    */

    int rows = 3, cols = 4;

    // Create 3 rows, each row is a vector<int> of size 4, all 0
    vector<vector<int>> M(rows, vector<int>(cols, 0));

    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M[i][j] = val++;
        }
    }

    print_2d(M, "M (3x4 matrix)");

    /*
        Visual:

        M =
          row 0: [ 1,  2,  3,  4]
          row 1: [ 5,  6,  7,  8]
          row 2: [ 9, 10, 11, 12]
    */


    // ============================================================
    // 10. 2D VECTORS: JAGGED ARRAY (different row sizes)
    // ============================================================
    cout << "================ 10. 2D VECTORS (JAGGED) =================\n\n";

    vector<vector<int>> J;  // initially empty

    // push_back rows one by one
    J.push_back({1, 2});        // row 0: 2 columns
    J.push_back({3, 4, 5});     // row 1: 3 columns
    J.push_back({6});           // row 2: 1 column

    print_2d(J, "J (jagged)");

    /*
        Visual:

        J =
          row 0: [1, 2]
          row 1: [3, 4, 5]
          row 2: [6]

        Here: J[i].size() can be different for each i.
    */


    // ============================================================
    // 11. 2D VECTORS FOR GRAPHS (ADJACENCY LIST)
    // ============================================================
    cout << "================ 11. 2D VECTORS (GRAPH) =================\n\n";

    int n = 5; // number of nodes: 0..4

    // G[i] = vector of neighbors of node i
    vector<vector<int>> G(n);

    // Let's add edges for an undirected graph:
    // 0 - 1, 0 - 2, 1 - 3, 1 - 4
    G[0].push_back(1);
    G[1].push_back(0);

    G[0].push_back(2);
    G[2].push_back(0);

    G[1].push_back(3);
    G[3].push_back(1);

    G[1].push_back(4);
    G[4].push_back(1);

    /*
        Visual graph:

            3
            |
        2 - 0 - 1 - 4

        G[0] = [1, 2]
        G[1] = [0, 3, 4]
        G[2] = [0]
        G[3] = [1]
        G[4] = [1]
    */

    print_2d(G, "G (adjacency list)");

    cout << "Neighbors of node 1: ";
    for (int nb : G[1]) {
        cout << nb << " ";
    }
    cout << "\n\n";

    // ============================================================
    // 12. 2D DATA STRUCTURES USING ARRAY + VECTOR
    // ============================================================
    cout << "================ 12. 2D USING array<> + vector<> =================\n\n";

    /*
        vector<array<int, C>> is a very common alternative to vector<vector<int>> 
        when the number of columns is fixed.

        Advantages:
        - array<int,C> is fixed size → faster, contiguous, no realloc inside rows
        - Cleaner and more cache-friendly than vector<vector<int>>
    */

    const int R = 3;
    const int C = 4;

    vector<array<int, C>> VA(R);  // 3 rows, each row is array<4 ints>

    int k = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            VA[i][j] = k++;
        }
    }

    cout << "VA (vector<array<int,4>>):\n";
    for (int i = 0; i < R; i++) {
        cout << "  row " << i << ": ";
        for (int j = 0; j < C; j++) cout << VA[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";


    // ============================================================
    // 13. STATIC 2D ARRAY (Classic C-style, contiguous, fastest)
    // ============================================================
    cout << "================ 13. STATIC 2D ARRAY =================\n\n";

    /*
        When rows & cols are known at compile time (or even runtime), 
        int A[rows][cols] is extremely fast & fully contiguous.

        Memory layout:
        A = [ a00 a01 a02 a03  a10 a11 a12 a13  a20 a21 a22 a23 ]
    */

    int A2[R][C];
    k = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            A2[i][j] = k++;
        }
    }

    cout << "A2 (int[R][C]):\n";
    for (int i = 0; i < R; i++) {
        cout << "  row " << i << ": ";
        for (int j = 0; j < C; j++) cout << A2[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";


    // ============================================================
    // 14. array<array<int,N>,M>  (STL fixed 2D array)
    // ============================================================
    cout << "================ 14. array<array<>> =================\n\n";

    array<array<int, C>, R> ARR2;

    k = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ARR2[i][j] = k++;
        }
    }

    cout << "ARR2 (array<array<int,4>,3>):\n";
    for (int i = 0; i < R; i++) {
        cout << "  row " << i << ": ";
        for (int j = 0; j < C; j++) cout << ARR2[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    // ============================================================
    // 15. POINTER-BASED 2D: vector<int*>  (rarely used, but good to know)
    // ============================================================
    cout << "================ 15. vector<int*> =================\n\n";

    /*
        This mimics C "array of pointers":
            int* rows[R];

        Every row is separately allocated. 
        Not contiguous! But indexing is A[i][j].
    */

    vector<int*> P(R);

    for (int i = 0; i < R; i++) {
        P[i] = new int[C];
    }

    k = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            P[i][j] = k++;
        }
    }

    cout << "P (vector<int*>):\n";
    for (int i = 0; i < R; i++) {
        cout << "  row " << i << ": ";
        for (int j = 0; j < C; j++) cout << P[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    // cleanup
    for (int i = 0; i < R; i++) delete[] P[i];

    
    // ============================================================
    // Practice on Array
    // ============================================================
    /*
        1. Reverse array in-place, No extra memory.
        2. Find 2nd largest / 2nd smallest, Requires careful boundary handling.
        3. Remove duplicates from sorted array, Return the new length.
        4. Rotate array by K positions, Both left and right rotation.
        5. Partition array (odd numbers left, even numbers right), Order doesn't matter → 2-pointer technique.
        6. Matrix transpose (square + rectangular)
        7. Rotate matrix 90° clockwise
        8. Spiral order traversal, Print matrix in spiral:
    */

    cout << "Demo complete.\n";

    return 0;
}
