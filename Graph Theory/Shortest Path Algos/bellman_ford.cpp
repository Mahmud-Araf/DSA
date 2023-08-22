#include<bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<pair<int, int>>> &v, vector<int> &dist, int n, int source) {
    dist[source] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (int vi = 0; vi < n; ++vi) {
            for (auto child : v[vi]) {
                int child_v = child.first;
                int wt = child.second;
                if (dist[vi] != INT_MAX && dist[vi] + wt < dist[child_v]) {
                    dist[child_v] = dist[vi] + wt;
                }
            }
        }
    }

    for (int vi = 0; vi < n; ++vi) {
        for (auto child : v[vi]) {
            int child_v = child.first;
            int wt = child.second;
            if (dist[vi] != INT_MAX && dist[vi] + wt < dist[child_v]) {
                cout << "Negative cycle detected!" << endl;
                return;
            }
        }
    }
}

int main() {
    int n = 5; // Number of vertices in graph
    int m = 8; // Number of edges in graph

    vector<vector<pair<int, int>>> v(n);
    vector<int> dist(n, INT_MAX);
    
    // Adding edges to the graph
    v[0].push_back({1, -1});
    v[0].push_back({2, 4});
    v[1].push_back({2, 3});
    v[1].push_back({3, 2});
    v[1].push_back({4, 2});
    v[3].push_back({2, 5});
    v[3].push_back({1, 1});
    v[4].push_back({3, -3});

    int source = 0; // Using 0-based indexing for the source vertex

    bellmanFord(v, dist, n, source);

    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << "\t\t";
        if (dist[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
