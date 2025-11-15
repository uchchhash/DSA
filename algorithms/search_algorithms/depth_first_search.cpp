#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------
// Depth First Search (DFS)
// Idea:
//   • Travel through a graph like exploring branches of a tree
//   • Always go as deep as possible before coming back (backtracking)
//   • Once a node is visited, mark it so we don't visit it again
//   • DFS can be implemented in two ways: Recursion OR Stack
// ----------------------------------------------------------------------



// ----------------------------
// DFS Using Recursion (Top-Down)
// ----------------------------
void dfs_recursive(int v, vector<vector<int>>& G, vector<bool>& marked) {

    // Visit the current node (Print it)
    cout << "Visiting: " << v << "\n";

    // Mark this node as visited so we don't visit it again
    marked[v] = true;

    // Loop through all neighbors of node v
    for (int w : G[v]) {

        // If this neighbor is NOT visited yet, explore it
        if (!marked[w]) {

            // DFS goes "deep" — call dfs on the neighbor
            dfs_recursive(w, G, marked);
        }
    }

    // Once all neighbors of v are explored,
    // recursion automatically backtracks to previous node
}



// ----------------------------
// DFS Using Stack (Iterative)
// ----------------------------
void dfs_stack(int start, vector<vector<int>>& G, vector<bool>& marked) {

    // Create an empty stack for DFS
    stack<int> st;

    // Push the starting node
    st.push(start);

    // Continue until stack becomes empty
    while (!st.empty()) {

        // Pop the top node of the stack
        int v = st.top();
        st.pop();

        // If this node is not visited yet, visit it
        if (!marked[v]) {
            cout << "Visiting: " << v << "\n";
            marked[v] = true;
        }

        // Push all unvisited neighbors into the stack
        //
        // Stack will ensure: Last added neighbor is explored first
        for (int w : G[v]) {
            if (!marked[w]) {
                st.push(w);
            }
        }
    }
}



// ----------------------------
// Driver Code
// ----------------------------
int main() {

    // Number of nodes in the graph
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;

    // Graph represented as adjacency list:
    // G[i] = list of neighbors of node i
    vector<vector<int>> G(n);

    // Number of edges
    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    // Input edges one by one
    // For an undirected graph, we push both (u -> v) and (v -> u)
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // -----------------------------
    // Run DFS Recursively
    // -----------------------------
    cout << "\n--- DFS (Recursive) ---\n";

    // Create a visited array initialized to false
    vector<bool> marked_r(n, false);

    // Start DFS from node 0
    dfs_recursive(0, G, marked_r);



    // -----------------------------
    // Run DFS Using a Stack
    // -----------------------------
    cout << "\n--- DFS (Stack) ---\n";

    // Reset visited array
    vector<bool> marked_s(n, false);

    // Start stack-based DFS from node 0
    dfs_stack(0, G, marked_s);

    return 0;
}
