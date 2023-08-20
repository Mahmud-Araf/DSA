// implementation of jhonson's algorithm

#include<bits/stdc++.h>
using namespace std;

bool negativeCycleExist =false;

vector<int> bellmanFord(vector<vector<pair<int, int>>> &graph, int n) {
    vector<int> h(n+1,INT_MAX);
    h[n] = 0;

    for (int i = 1; i <= n ; ++i) {
        for (int vi = 1; vi <= n; ++vi) {
            for (auto child : graph[vi]) {
                int child_v = child.first;
                int wt = child.second;
                if (h[vi] != INT_MAX && h[vi] + wt < h[child_v]) {
                    h[child_v] = h[vi] + wt;
                }
            }
        }
    }

    for (int vi = 1; vi <= n; ++vi) {
        for (auto child : graph[vi]) {
            int child_v = child.first;
            int wt = child.second;
            if (h[vi] != INT_MAX && h[vi] + wt < h[child_v]) {
                negativeCycleExist = true;
                return h;
            }
        }
    }

    return h;
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph,int n, int source)
{
    vector<int>dist(n,INT_MAX);
    vector<int> visited(n, 0);
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

        for (auto child : graph[vi])
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

    return dist;
}

void printSolution(vector<vector<int>>&dist, int n)
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] ==INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}


void johnson(vector<vector<pair<int, int>>> &graph,int n)
{
    for(int i=0;i<n;i++)
    {
       graph[n].push_back({i,0});
    }

    auto h=bellmanFord(graph,n);

    if(negativeCycleExist==true)
    {
        cout<<"Negative cycle exists so shortest path is not possible"<<endl;
        return;
    }

    for(int i=0;i<n;i++)
    {
        for(auto j:graph[i])
        {
            int &wt=j.second;
            wt= wt+h[i]- h[j.first];
        }
    }

    vector<vector<int>>shortest(n);

    for(int source=0;source<n;source++)
    {
        shortest[source]=dijkstra(graph,n,source);
    }
    
    printSolution(shortest,n);
}


int main() {
    int n = 4; // Number of vertices
    vector<vector<pair<int, int>>> graph(n+1);

    vector<vector<int> >matrix(4,vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INT_MAX;
        }
    }

    matrix[0][1] = 5;
    matrix[0][3] = 10;
    matrix[1][2] = 3;
    matrix[2][3] = 1;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != INT_MAX) {
                graph[i].push_back({j, matrix[i][j]});
            }
        }
    }

    johnson(graph, n);

    return 0;
}