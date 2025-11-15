#include <bits/stdc++.h>
using namespace std;

// helper function to print a stack (we copy because stack cannot be iterated directly)
void print_stack(stack<int> st, const string &name) {
    cout << name << " (TOP → BOTTOM): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {

    // =====================================================================
    // 1. DECLARATION + PUSH + VISUAL
    // =====================================================================
    cout << "================= 1. BASIC STACK =================\n\n";

    stack<int> st;

    cout << "Pushing 10, 20, 30...\n";
    st.push(10);  // bottom
    st.push(20);
    st.push(30);  // top

    /*
        Visual:

            TOP
             ↓
            [30]
            [20]
            [10]
            -----
            BOTTOM
    */

    print_stack(st, "st");


    // =====================================================================
    // 2. ACCESSING TOP + POP
    // =====================================================================
    cout << "\n================= 2. TOP + POP =================\n\n";

    // top element
    cout << "Top element = " << st.top() << "\n"; // 30

    cout << "Popping top...\n";
    st.pop();  // removes 30

    cout << "New top = " << st.top() << " (should be 20)\n\n";


    // =====================================================================
    // 3. CHECK EMPTY, SIZE
    // =====================================================================
    cout << "================= 3. empty(), size() =================\n\n";

    cout << "st.empty()? " << (st.empty() ? "YES" : "NO") << "\n";
    cout << "st.size()  = " << st.size() << "\n\n";


    // =====================================================================
    // 4. REBUILD STACK FOR NEXT EXAMPLES
    // =====================================================================
    st = stack<int>(); // reset to empty

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    /*
        Stack now:

           [5] ← top
           [4]
           [3]
           [2]
           [1] ← bottom
    */

    print_stack(st, "Rebuilt st");


    // =====================================================================
    // 5. POPPING UNTIL EMPTY (Correct way to iterate)
    // =====================================================================
    cout << "\n================= 5. POP UNTIL EMPTY =================\n\n";

    stack<int> temp = st;  // copy (stack doesn't allow iteration)
    cout << "Printing with while(!st.empty()): ";
    while (!temp.empty()) {
        cout << temp.top() << " "; // show
        temp.pop();                // remove
    }
    cout << "\n\n";

    // =====================================================================
    // 6. WRONG WAY: st[i] DOES NOT WORK
    // =====================================================================
    cout << "================= 6. WRONG WAY (for beginners) =================\n\n";

    cout << "You CANNOT do this:\n";
    cout << "   st[0]  // INVALID\n";
    cout << "Stack does NOT allow indexing. Only top/push/pop.\n\n";


    // =====================================================================
    // 7. USING STACK TO REVERSE AN ARRAY
    // =====================================================================
    cout << "================= 7. STACK FOR REVERSAL =================\n\n";

    vector<int> arr = {10, 20, 30, 40};
    stack<int> rev;

    // push all → top becomes last element
    for (int x : arr) rev.push(x);

    cout << "Reversed order: ";
    while (!rev.empty()) {
        cout << rev.top() << " ";
        rev.pop();
    }
    cout << "\n\n";

    /*
        Visual:

        Input array: [10, 20, 30, 40]

        Stack (top→bottom):
          [40]
          [30]
          [20]
          [10]

        Popping prints: 40 30 20 10
    */


    // =====================================================================
    // 8. USING STACK TO CHECK PARENTHESES
    // =====================================================================
    cout << "================= 8. CHECK PARENTHESES =================\n\n";

    string s = "((())())";

    stack<char> ps;
    bool ok = true;

    for (char c : s) {
        if (c == '(') ps.push(c);
        else {
            if (ps.empty()) { ok = false; break; }
            ps.pop();
        }
    }
    if (!ps.empty()) ok = false;

    cout << s << " is " << (ok ? "BALANCED" : "NOT BALANCED") << "\n\n";


    // =====================================================================
    // 9. STACK OVERFLOW & UNDERFLOW IDEA (Visual)
    // =====================================================================
    cout << "================= 9. UNDERFLOW DEMO =================\n\n";

    stack<int> uf;
    cout << "Attempting pop on empty stack (DON'T DO THIS):\n";

    /*
        Real code: uf.pop(); // CRASH – undefined behavior
        We WON'T run it, but explain visually:

        Empty stack:

        [ ] ← top does not exist

        pop() → ERROR (stack underflow)
    */

    cout << "Never call pop() or top() when st.empty() is true.\n\n";


    // =====================================================================
    // 10. STACK USED IN DFS ITERATIVE
    // =====================================================================
    cout << "================= 10. STACK IN DFS =================\n\n";

    /*
        Graph:
            1
            |
        2 - 0 - 3

        Adjacency list:
        G[0] = {1, 2, 3}
        G[1] = {0}
        G[2] = {0}
        G[3] = {0}
    */

    vector<vector<int>> G = {
        {1,2,3},
        {0},
        {0},
        {0}
    };

    vector<bool> vis(4, false);
    stack<int> dfs;

    dfs.push(0); // start from node 0

    cout << "DFS Order: ";

    while (!dfs.empty()) {
        int node = dfs.top();
        dfs.pop();

        if (vis[node]) continue;
        vis[node] = true;

        cout << node << " ";

        // push neighbors
        for (int nb : G[node]) {
            if (!vis[nb]) dfs.push(nb);
        }
    }
    cout << "\n\n";

    /*
        Visual idea:

        push(0)
        → pop 0 → visit → push neighbors 1,2,3
        → pop 3 → visit
        → pop 2 → visit
        → pop 1 → visit
    */


    // =====================================================================
    // 11. SUMMARY COMMENT
    // =====================================================================
    /*
        In this single file you learned:

        ✔ stack declaration
        ✔ push, pop, top, empty, size
        ✔ correct printing method
        ✔ stack can't be indexed (NO st[i])
        ✔ stack underflow safety
        ✔ visual LIFO behavior
        ✔ reversing a vector using stack
        ✔ checking balanced parentheses
        ✔ DFS using stack
        ✔ reinitializing a stack
        ✔ copying stacks for printing

        This covers 100% of what you need for:
        - DFS
        - Expression problems
        - Stack manipulation questions
        - Interviews
    */

    cout << "Demo complete.\n";

    return 0;
}
