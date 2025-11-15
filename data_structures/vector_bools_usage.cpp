#include <bits/stdc++.h>
using namespace std;

// Helper to print vector<bool> cleanly
void print_vb(const vector<bool> &v, const string &name) {
    cout << name << " (size=" << v.size() << "): ";
    for (bool b : v) cout << (b ? "1 " : "0 ");
    cout << "\n";
}

int main() {

    // ================================================================
    // 1. BASIC DECLARATION
    // ================================================================
    cout << "================= 1. DECLARATION =================\n\n";

    vector<bool> vb1;                     // empty
    vector<bool> vb2(5);                  // size 5, all false (0)
    vector<bool> vb3(5, true);            // size 5, all true (1)
    vector<bool> vb4 = {1, 0, 1, 1, 0};   // initializer list

    print_vb(vb1, "vb1");
    print_vb(vb2, "vb2");
    print_vb(vb3, "vb3");
    print_vb(vb4, "vb4");

    cout << "\n";


    // ================================================================
    // 2. PUSHING VALUES (push_back)
    // ================================================================
    cout << "================= 2. push_back =================\n\n";

    vector<bool> v;

    v.push_back(true);   // push 1
    v.push_back(false);  // push 0
    v.push_back(true);   // push 1
    v.push_back(true);   // push 1

    print_vb(v, "v after pushing 1,0,1,1");

    cout << "v.size() = " << v.size() << "\n\n";


    // ================================================================
    // 3. ACCESSING & MODIFYING: v[i], v.at(i)
    // ================================================================
    cout << "================= 3. ACCESS & MODIFY =================\n\n";

    cout << "v[0] = " << v[0] << " (true)\n";
    cout << "v[1] = " << v[1] << " (false)\n";
    cout << "v.at(2) = " << v.at(2) << " (true)\n\n";

    // modify using operator[]
    v[1] = true;      // change false → true
    v[2] = false;     // change true → false

    print_vb(v, "v after modifications");

    /*
        IMPORTANT NOTE:
        vector<bool> stores bits, NOT real booleans.
        v[i] is NOT a normal bool — it's a proxy reference.
        But you can still use it like normal.
    */

    cout << "\n";


    // ================================================================
    // 4. FLIPPING VALUES (toggle)
    // ================================================================
    cout << "================= 4. FLIP VALUES =================\n\n";

    for (int i = 0; i < v.size(); i++) {
        v[i] = !v[i];   // flip: true→false, false→true
    }

    print_vb(v, "v after flipping all bits");

    cout << "\n";


    // ================================================================
    // 5. ITERATION METHODS
    // ================================================================
    cout << "================= 5. ITERATION =================\n\n";

    cout << "Range-based for: ";
    for (bool bit : v) {
        cout << (bit ? "1 " : "0 ");
    }
    cout << "\n";

    cout << "Index loop: ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v[i] ? "1 " : "0 ");
    }
    cout << "\n\n";


    // ================================================================
    // 6. POP BACK & CLEAR
    // ================================================================
    cout << "================= 6. pop_back & clear =================\n\n";

    v.pop_back(); // remove last bit
    print_vb(v, "v after pop_back");

    v.clear(); // remove all
    print_vb(v, "v after clear");

    cout << "\n";


    // ================================================================
    // 7. COUNT TRUE / FALSE
    // ================================================================
    cout << "================= 7. COUNT TRUE/FALSE =================\n\n";

    vector<bool> vc = {1,0,1,1,0,1,0};

    int count_true = 0;
    int count_false = 0;

    for (bool bit : vc) {
        if (bit) count_true++;
        else count_false++;
    }

    print_vb(vc, "vc");
    cout << "count_true  = " << count_true << "\n";
    cout << "count_false = " << count_false << "\n\n";


    // ================================================================
    // 8. COMPARING NORMAL VECTOR vs vector<bool>
    // ================================================================
    cout << "================= 8. NORMAL VS VECTOR<BOOL> =================\n\n";

    cout << "vector<int> uses 4 bytes per int.\n";
    cout << "vector<bool> packs bits tightly (1 bit per value).\n";
    cout << "This makes vector<bool> MEMORY EFFICIENT.\n";
    cout << "But indexing returns a proxy, not true bool.\n";
    cout << "For beginners, it's fine; just remember it's special.\n\n";


    // ================================================================
    // END
    // ================================================================
    cout << "Demo complete.\n";

    return 0;
}
