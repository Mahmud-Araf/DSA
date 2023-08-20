#include <bits/stdc++.h>
using namespace std;


void dijkstra(vector<vector<pair<int, int>>> &v,vector<int>&dist,int n, int source)
{
    vector<int> visited(n + 1, 0);
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        int vi = node.second;
        st.erase(st.begin());

        if (visited[vi])
            continue;
        visited[vi] = 1;

        for (auto child : v[vi])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[vi] + wt < dist[child_v])
            {
                dist[child_v] = dist[vi] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int n, m; // Number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Create the adjacency list
    vector<vector<pair<int, int>>> v(n + 1);
    vector<int> dist(n + 1, INT_MAX);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, w; // Edge from x to y with weight w
        cin >> x >> y >> w;
        v[x].push_back({y, w});
    }

    int source; // Source node for Dijkstra's algorithm
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(v, dist, n, source);

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF" << endl;
        else
            cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}