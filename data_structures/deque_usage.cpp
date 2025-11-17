#include <bits/stdc++.h>
using namespace std;

// Helper to print a deque (we pass by value so we can access safely)
template<typename T>
void print_deque(deque<T> dq, const string &name) {
    cout << name << " (FRONT → BACK): ";
    /*
        Visual order:

        front                        back
          ↓                            ↓
        [dq[0], dq[1], dq[2], ..., dq[n-1]]
    */
    for (const T &x : dq) cout << x << " ";
    cout << "\n";
}

int main() {

    // ============================================================
    // 1. BASIC DEQUE: Double-Ended Queue
    // ============================================================
    cout << "================ 1. BASIC DEQUE =================\n\n";

    deque<int> dq;

    cout << "Pushing 10, 20, 30 at the BACK...\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    /*
        Visual:

        FRONT                     BACK
          ↓                         ↓
        [10,          20,          30]
    */
    print_deque(dq, "dq after push_back");


    cout << "\nPushing 5, then 1 at the FRONT...\n";
    dq.push_front(5);
    dq.push_front(1);

    /*
        Visual:

        FRONT                              BACK
          ↓                                  ↓
        [1,      5,      10,      20,      30]
    */
    print_deque(dq, "dq after push_front");


    // ============================================================
    // 2. front(), back(), size(), empty()
    // ============================================================
    cout << "\n================ 2. front/back/size/empty =================\n\n";

    cout << "Front element = " << dq.front() << " (should be 1)\n";
    cout << "Back element  = " << dq.back()  << " (should be 30)\n";
    cout << "Size          = " << dq.size()  << "\n";
    cout << "Is empty?     = " << (dq.empty() ? "YES" : "NO") << "\n\n";


    // ============================================================
    // 3. POP from both ends
    // ============================================================
    cout << "================ 3. POP FRONT & POP BACK =================\n\n";

    cout << "Popping from FRONT...\n";
    dq.pop_front(); // removes 1

    cout << "Popping from BACK...\n";
    dq.pop_back(); // removes 30

    /*
        Visual after pops:

        FRONT                     BACK
          ↓                         ↓
        [5,      10,      20]
    */
    print_deque(dq, "dq after pop_front & pop_back");


    // ============================================================
    // 4. RANDOM ACCESS (deque SUPPORTS indexing)
    // ============================================================
    cout << "\n================ 4. INDEXING (deque supports it!) =================\n\n";

    cout << "dq[0] = " << dq[0] << "\n";
    cout << "dq[1] = " << dq[1] << "\n";
    cout << "dq[2] = " << dq[2] << "\n";

    cout << "Modifying dq[1] = 100...\n";
    dq[1] = 100;

    print_deque(dq, "dq after dq[1] = 100");

    /*
        IMPORTANT:
        Unlike queue and stack → deque ALLOWS indexing.
    */


    // ============================================================
    // 5. ITERATING over deque
    // ============================================================
    cout << "\n================ 5. ITERATION =================\n\n";

    cout << "Range-based for: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    cout << "Index-based for: ";
    for (int i = 0; i < (int)dq.size(); i++) cout << dq[i] << " ";
    cout << "\n\n";


    // ============================================================
    // 6. SIMULATION: Browser History (front/back usage)
    // ============================================================
    cout << "================ 6. BROWSER HISTORY SIMULATION =================\n\n";

    deque<string> history;

    cout << "Visiting pages: A, B, C, D...\n";
    history.push_back("A");
    history.push_back("B");
    history.push_back("C");
    history.push_back("D");

    print_deque(history, "History");

    cout << "User presses BACK twice...\n";
    history.pop_back(); // remove D
    history.pop_back(); // remove C

    print_deque(history, "History after 2 back presses");

    cout << "User visits new page E...\n";
    history.push_back("E");

    print_deque(history, "History after adding E");


    // ============================================================
    // 7. SAFETY: Never pop on empty deque
    // ============================================================
    cout << "\n================ 7. UNDERFLOW SAFETY =================\n\n";

    deque<int> safe;

    cout << "Correct way:\n";
    cout << "if (!safe.empty()) safe.pop_front();\n";


    // ============================================================
    // 8. DEQUE USE-CASE: SLIDING WINDOW MAX/MIN (concept only)
    // ============================================================
    cout << "\n================ 8. USE CASE: SLIDING WINDOW (concept only) =================\n\n";

    cout << "Deque is perfect for problems that need pushing and popping\n";
    cout << "from BOTH sides — such as sliding window max/min.\n";
    cout << "We will learn these later when we learn sliding window.\n\n";


    // ============================================================
    // 9. SUMMARY
    // ============================================================
    /*
        In this single file you saw:

        ✔ deque<T> declaration
        ✔ push_back(x)
        ✔ push_front(x)
        ✔ pop_back()
        ✔ pop_front()
        ✔ front()  – see first element
        ✔ back()   – see last element
        ✔ indexing support like deque[i]
        ✔ size(), empty()

        ✔ Browser history simulation
        ✔ Safety notes (avoid popping when empty)

        Key Differences vs queue:
        -------------------------
        queue:
            - only push_back and pop_front
            - strictly FIFO
            - NO indexing

        deque:
            - push_front, push_back
            - pop_front, pop_back
            - indexing allowed
            - very flexible
            - ideal for two-pointers, sliding window, 0-1 BFS, etc.
    */

    cout << "Deque demo complete.\n";
    return 0;
}
