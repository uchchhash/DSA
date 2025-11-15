#include <bits/stdc++.h>
using namespace std;

// Helper to print a queue (we pass by value so we can pop safely)
void print_queue(queue<int> q, const string &name) {
    cout << name << " (FRONT → BACK): ";
    /*
        Visual order:

        front                        back
          ↓                            ↓
        [q.front(), ..., ..., q.back()]
    */
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {

    // ============================================================
    // 1. BASIC QUEUE: FIFO (First In, First Out)
    // ============================================================
    cout << "================ 1. BASIC QUEUE =================\n\n";

    // Declare an empty queue of int
    queue<int> q;

    cout << "Pushing 10, 20, 30 into the queue...\n";
    q.push(10); // first in → will be first out (front)
    q.push(20);
    q.push(30); // last in → currently at back

    /*
        Visual:

        FRONT                     BACK
          ↓                         ↓
        [10,          20,          30]

        Next pop() will remove 10
    */

    print_queue(q, "q (after push 10,20,30)");

    // Note: print_queue copies the queue and empties the copy,
    // the original queue `q` is unchanged by print_queue.
    cout << "\n";


    // ============================================================
    // 2. front(), back(), size(), empty()
    // ============================================================
    cout << "================ 2. front/back/size/empty =================\n\n";

    // Rebuild the queue since the previous print used a copy
    q = queue<int>();  // reset to empty
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element = " << q.front() << " (should be 10)\n";
    cout << "Back element  = " << q.back()  << " (should be 30)\n";
    cout << "Size          = " << q.size()  << "\n";
    cout << "Is empty?     = " << (q.empty() ? "YES" : "NO") << "\n\n";

    /*
        KEY IDEA:

        - front() → oldest element (next to be removed)
        - back()  → newest element (just inserted)
        - FIFO: First In, First Out
    */


    // ============================================================
    // 3. POP: Dequeue elements in order
    // ============================================================
    cout << "================ 3. POP (DEQUEUE) =================\n\n";

    /*
        Current q:

        FRONT                     BACK
          ↓                         ↓
        [10,          20,          30]
    */

    cout << "Popping elements in order:\n";
    while (!q.empty()) {
        cout << "  front = " << q.front() << "  → popping it\n";
        q.pop();
    }
    cout << "Now q.empty()? " << (q.empty() ? "YES" : "NO") << "\n\n";

    /*
        Output order: 10, then 20, then 30.
        This shows: First In → First Out.
    */


    // ============================================================
    // 4. WRONG WAY: No indexing like q[i]
    // ============================================================
    cout << "================ 4. WRONG WAY (no q[i]) =================\n\n";

    cout << "You cannot do this with queue:\n";
    cout << "  q[0];   // INVALID\n";
    cout << "Queue does NOT allow random access.\n";
    cout << "Only front(), back(), push(), pop(), empty(), size().\n\n";


    // ============================================================
    // 5. SIMULATING A LINE OF PEOPLE (simple queue example)
    // ============================================================
    cout << "================ 5. SIMULATION: LINE OF PEOPLE =================\n\n";

    queue<string> line;

    cout << "People join the line: Alice, Bob, Charlie...\n";
    line.push("Alice");    // front
    line.push("Bob");
    line.push("Charlie");  // back

    /*
        Visual:

        FRONT                         BACK
          ↓                             ↓
        ["Alice",       "Bob",      "Charlie"]
    */

    cout << "First in line: " << line.front() << "\n";
    cout << "Last  in line: " << line.back()  << "\n\n";

    cout << "Serving people in order:\n";
    while (!line.empty()) {
        cout << "  Serving: " << line.front() << "\n";
        line.pop();
    }
    cout << "Line empty now? " << (line.empty() ? "YES" : "NO") << "\n\n";


    // ============================================================
    // 6. QUEUE SAFETY: Underflow (popping when empty)
    // ============================================================
    cout << "================ 6. UNDERFLOW SAFETY =================\n\n";

    queue<int> safe;

    cout << "Never do this:\n";
    cout << "  safe.pop();  // if safe.empty() is true → undefined behavior\n\n";

    cout << "Always check:\n";
    cout << "  if (!safe.empty()) safe.pop();\n\n";


    // ============================================================
    // 7. BFS (Breadth-First Search) USING QUEUE
    // ============================================================
    cout << "================ 7. QUEUE IN BFS =================\n\n";

    /*
        Graph (undirected):

            1
            |
        2 - 0 - 3
            |
            4

        Node numbers: 0,1,2,3,4

        Adjacency list (vector<vector<int>>):

        G[0] = {1,2,3,4}
        G[1] = {0}
        G[2] = {0}
        G[3] = {0}
        G[4] = {0}
    */

    vector<vector<int>> G = {
        {1, 2, 3, 4},  // neighbors of 0
        {0},           // neighbors of 1
        {0},           // neighbors of 2
        {0},           // neighbors of 3
        {0}            // neighbors of 4
    };

    vector<bool> visited(5, false);
    queue<int> bfs_q;

    int start = 0;
    bfs_q.push(start);
    visited[start] = true;

    cout << "BFS traversal starting from node 0:\n";
    cout << "Order: ";

    while (!bfs_q.empty()) {
        int node = bfs_q.front();
        bfs_q.pop();

        cout << node << " ";

        // Visit all neighbors
        for (int nb : G[node]) {
            if (!visited[nb]) {
                visited[nb] = true;
                bfs_q.push(nb);
            }
        }
    }
    cout << "\n\n";

    /*
        BFS with queue:

        Step 0:
            queue: [0]                visited: {0}

        Step 1:
            pop 0 → visit 0
            push neighbors 1,2,3,4
            queue: [1,2,3,4]

        Step 2:
            pop 1 → visit 1
            neighbors: [0] (already visited, skip)
            queue: [2,3,4]

        Step 3:
            pop 2 → visit 2
            neighbors: [0] (visited)
            queue: [3,4]

        Step 4:
            pop 3 → visit 3
            neighbors: [0] (visited)
            queue: [4]

        Step 5:
            pop 4 → visit 4
            neighbors: [0] (visited)
            queue: []

        Final BFS order: 0 1 2 3 4
        This is level-by-level exploration because queue is FIFO.
    */


    // ============================================================
    // 8. SUMMARY
    // ============================================================
    /*
        In this single file you saw:

        ✔ queue<T> declaration
        ✔ push(x)   – enqueue at BACK
        ✔ pop()     – dequeue from FRONT
        ✔ front()   – get oldest element
        ✔ back()    – get newest element
        ✔ empty()   – check if queue has no elements
        ✔ size()    – current number of elements

        ✔ why no indexing (q[i] is invalid)
        ✔ line/people simulation
        ✔ underflow safety: always check empty()
        ✔ BFS implementation using queue + adjacency list

        That’s everything you need for BFS and most queue-based problems.
    */

    cout << "Queue demo complete.\n";
    return 0;
}
