//implementation of edmonds-karp for maximum flow problem using bfs
#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &residual, int s, int t, vector<int> &parent)
{
    int n = residual.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && residual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int edmondKarp(vector<vector<int>>&graph,int s, int t)
{
    int u,v;
    int n = graph.size();
    vector<vector<int>> residual(n,vector<int>(n,0));

    for(u=0;u<n;u++)
    {
        for(v=0;v<n;v++)
        {
            residual[u][v]=graph[u][v];
        }
    }

    vector<int> parent(n,-1);

    int max_flow = 0;

    while(bfs(residual,s,t,parent))
    {
        int path_flow = INT_MAX;

        for(v=t;v!=s;v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow,residual[u][v]);
        }

        for(v=t;v!=s;v=parent[v])
        {
            u = parent[v];
            residual[u][v]-=path_flow;
            residual[v][u]+=path_flow;
        }

        max_flow+=path_flow;
    }

    return max_flow;
}

int main()
{
    vector<vector<int>>graph={ { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    
    cout<<"The maximum possible flow is "<<edmondKarp(graph,0,5)<<endl;
}
