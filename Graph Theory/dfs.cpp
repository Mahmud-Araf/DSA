// implementation of dfs

#include <bits/stdc++.h>
using namespace std;

void dfs(int p, int adj[][1000], int visited[])
{
    if (!visited[p]) visited[p] = 1;

    for (auto i : adj[p])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
        }
    }
}

int main()
{
    int n = 6; // number of nodes
    int m = 7; // number of edges

    int adj[1000][1000] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 1, 0}
    };

    int visited[1000];

    // initialize visited array to all 0's
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // perform DFS on each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

    // print out visited array to check if DFS was successful
    for (int i = 0; i < n; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;

    return 0;
}