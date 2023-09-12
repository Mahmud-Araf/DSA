#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &v, vector<int> &dist, int n, int source) {
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int vi = node.second;

        if (visited[vi])
            continue;
        visited[vi] = 1;

        for (auto child : v[vi]) {
            int child_v = child.first;
            int wt = child.second;
            if (dist[vi] + wt < dist[child_v]) {
                dist[child_v] = dist[vi] + wt;
                pq.push({dist[child_v], child_v});
            }
        }
    }
}

int main() {
    int n = 6;  // Number of nodes
    int source = 1;  // Source node
    vector<vector<pair<int, int>>> graph(n + 1);

    // Add edges and weights to the graph
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 4});
    graph[2].push_back({4, 7});
    graph[3].push_back({5, 3});
    graph[4].push_back({6, 1});
    graph[5].push_back({6, 5});

    vector<int> dist(n + 1, INT_MAX);

    dijkstra(graph, dist, n, source);

    // Print the shortest distances from the source node
    for (int i = 1; i <= n; i++) {
        cout << "Shortest distance from node " << source << " to node " << i << " is: " << dist[i] << endl;
    }

    return 0;
}
