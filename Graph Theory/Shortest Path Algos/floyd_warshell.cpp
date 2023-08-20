// implementation of floyd-warshall algorithm


#include<bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>>&dist, int n)
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>>&dist, int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist, n);
}

int main()
{
   vector<vector<int> >graph(4,vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;

    floydWarshall(graph, 4);

    return 0;
}
