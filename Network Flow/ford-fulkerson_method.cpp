//implementation of ford-fulkerson method for maximum flow problem using dfs

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &residual, int s, int t, vector<int> &parent, vector<bool> &visited) {
    int n = residual.size();
    visited[s] = true;
    if (s == t) {
        return true;
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v] && residual[s][v] > 0) {
            parent[v] = s;
            if (dfs(residual, v, t, parent, visited)) {
                return true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> &graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residual(n, vector<int>(n, 0));

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            residual[u][v] = graph[u][v];
        }
    }

    vector<int> parent(n, -1);
    int maxFlow = 0;
    vector<bool>visited(n, false);
    while (dfs(residual, source, sink, parent,visited)) 
    {
        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;

        visited.assign(n, false);
    }

    return maxFlow;
}

int main() {
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    int maxFlow = fordFulkerson(graph, source, sink);

    cout << "The maximum possible flow is " << maxFlow << endl;
}