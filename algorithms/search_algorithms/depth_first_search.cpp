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
// DFS on Grid
// ----------------------------
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs_grid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    int R = grid.size();
    int C = grid[0].size();

    vis[x][y] = true;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if (!vis[nx][ny] && grid[nx][ny] == 1) {
                dfs_grid(nx, ny, grid, vis);
            }
        }
    }
}


// ----------------------------
// DFS Backtracking Example
// ----------------------------
void dfs_backtrack(int index, vector<int>& path, vector<int>& arr) {
    // print current combination
    cout << "{ ";
    for (int x : path) cout << x << " ";
    cout << "}\n";

    for (int i = index; i < arr.size(); i++) {
        path.push_back(arr[i]);       // choose
        dfs_backtrack(i + 1, path, arr); // explore
        path.pop_back();              // un-choose (backtrack)
    }
}


// ----------------------------
// DFS Cycle Detection
// ----------------------------
bool dfs_cycle(int v, int parent, vector<vector<int>>& G, vector<bool>& visited) {
    visited[v] = true;

    for (int nei : G[v]) {
        if (!visited[nei]) {
            if (dfs_cycle(nei, v, G, visited)) return true;
        }
        else if (nei != parent) {
            return true; // cycle found
        }
    }
    return false;
}


// ----------------------------
// Driver Code + TESTCASES
// ----------------------------
int main() {

    cout << "\n======================================\n";
    cout << " TESTCASE 1: GRAPH DFS\n";
    cout << "======================================\n";

    // Graph adjacency list
    vector<vector<int>> G1 = {
        {1, 2},     // 0
        {0, 3},     // 1
        {0, 3},     // 2
        {1, 2, 4},  // 3
        {3}         // 4
    };

    vector<bool> vis1(5, false);
    cout << "DFS Recursive starting at 0: ";
    dfs_recursive(0, G1, vis1);
    cout << "\n";

    fill(vis1.begin(), vis1.end(), false);
    cout << "DFS Stack starting at 0: ";
    dfs_stack(0, G1, vis1);
    cout << "\n";


    cout << "\n======================================\n";
    cout << " TESTCASE 2: CYCLE DETECTION\n";
    cout << "======================================\n";

    vector<vector<int>> G2 = {
        {1},        // 0
        {0, 2},     // 1
        {1, 3},     // 2
        {2, 1}      // 3 --> back edge to 1 creates a cycle
    };

    vector<bool> vis2(4, false);
    bool cycle = dfs_cycle(0, -1, G2, vis2);
    cout << "Cycle present? " << (cycle ? "YES" : "NO") << "\n";


    cout << "\n======================================\n";
    cout << " TESTCASE 3: GRID DFS (Number of Islands)\n";
    cout << "======================================\n";

    vector<vector<int>> grid = {
        {1,0,1,1},
        {1,1,0,0},
        {0,1,1,0},
        {0,0,1,1}
    };

    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> visg(R, vector<bool>(C, false));

    int islands = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1 && !visg[i][j]) {
                islands++;
                dfs_grid(i, j, grid, visg);
            }
        }
    }

    cout << "Number of islands = " << islands << "\n";


    cout << "\n======================================\n";
    cout << " TESTCASE 4: DFS BACKTRACKING (Subsets)\n";
    cout << "======================================\n";

    vector<int> arr = {1, 2, 3};
    vector<int> path;

    cout << "All subsets:\n";
    dfs_backtrack(0, path, arr);


    cout << "\n======================================\n";
    cout << " END OF TESTCASES\n";
    cout << "======================================\n";

    return 0;
}
