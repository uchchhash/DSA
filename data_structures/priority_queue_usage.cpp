#include <bits/stdc++.h>
using namespace std;

// Helper to print a priority queue (must pass by value)
template<typename T>
void print_pq(priority_queue<T> pq, const string &name) {
    cout << name << " (TOP → BOTTOM order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

// Helper for min-heap printing
template<typename T>
void print_minpq(priority_queue<T, vector<T>, greater<T>> pq, const string &name) {
    cout << name << " (SMALLEST FIRST): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

int main() {

    // ==========================================================
    // 1. BASIC: MAX-HEAP (default)
    // ==========================================================
    cout << "============= 1. MAX-HEAP (DEFAULT) =============\n\n";

    // Default priority_queue behaves like a MAX HEAP
    priority_queue<int> pq;

    cout << "Pushing 10, 4, 25, 7...\n";
    pq.push(10);
    pq.push(4);
    pq.push(25);
    pq.push(7);

    /*
        Visual idea (max heap):

               25  <-- TOP (largest)
             /    \
           10      7
          /
         4

        But priority_queue hides this tree.
    */

    print_pq(pq, "pq");

    cout << "Top element (largest) = " << pq.top() << "\n\n";


    // ==========================================================
    // 2. POP removes the LARGEST first
    // ==========================================================
    cout << "============= 2. POP removes MAX =============\n\n";

    pq.pop(); // removes the largest (25)

    cout << "After one pop, new top = " << pq.top() << "\n\n";


    // ==========================================================
    // 3. Checking size() and empty()
    // ==========================================================
    cout << "============= 3. size(), empty() =============\n\n";

    cout << "pq.size() = " << pq.size() << "\n";
    cout << "pq.empty()? " << (pq.empty() ? "YES" : "NO") << "\n\n";


    // ==========================================================
    // 4. MIN HEAP (custom comparator)
    // ==========================================================
    cout << "============= 4. MIN-HEAP =============\n\n";

    priority_queue<int, vector<int>, greater<int>> minpq;

    cout << "Pushing 10, 4, 25, 7...\n";
    minpq.push(10);
    minpq.push(4);
    minpq.push(25);
    minpq.push(7);

    /*
        Visual idea (min heap):

                 4  <-- TOP (smallest)
               /    \
             10     25
            /
           7

        Again, priority_queue hides the tree structure.
    */

    print_minpq(minpq, "minpq");

    cout << "Top element (smallest) = " << minpq.top() << "\n\n";


    // ==========================================================
    // 5. POP from MIN HEAP removes smallest
    // ==========================================================
    cout << "============= 5. POP from MIN-HEAP =============\n\n";

    minpq.pop(); // removes 4

    cout << "After pop, new top (next-smallest) = "
         << minpq.top() << "\n\n";


    // ==========================================================
    // 6. Building priority_queue from existing vector
    // ==========================================================
    cout << "============= 6. BUILD FROM VECTOR =============\n\n";

    vector<int> values = {3, 1, 9, 7, 2};

    // Builds a max-heap from the vector
    priority_queue<int> fromVec(values.begin(), values.end());

    print_pq(fromVec, "fromVec");

    cout << "\n";


    // ==========================================================
    // 7. IMPORTANT POINTS (no code, just understanding)
    // ==========================================================
    cout << "============= 7. IMPORTANT NOTES =============\n\n";

    cout << "• priority_queue ALWAYS keeps the largest/smallest at TOP\n";
    cout << "• You CANNOT index into it (no pq[i])\n";
    cout << "• You CAN only use: push, pop, top, empty, size\n";
    cout << "• Internally uses a heap (tree), but you never see it\n";
    cout << "• Max-heap is default; min-heap must be explicitly declared\n";
    cout << "\n";

    // ==========================================================
    // End of demo
    // ==========================================================
    cout << "Priority queue demo complete.\n";

    return 0;
}
