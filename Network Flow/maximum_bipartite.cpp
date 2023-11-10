// implementation of maximum bipartite matching

#include<bits/stdc++.h>
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
            if (visited[v] == false && residual[u][v] && u!=t)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int edmondKarp(vector<vector<int>>&graph,int s, int t, vector<int>&parent)
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

    int max_flow = 0;

    vector<int>prev_parent = parent;

    while(bfs(residual,s,t,parent))
    {
        int path_flow = INT_MAX;

        for(v=t;v!=s;v=parent[v])
        {
            u = parent[v];
            prev_parent[v]=parent[v];
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

    parent = prev_parent;

    return max_flow;
}

void maximum_bipartite(vector<vector<int>>&graph)
{
    int m = graph.size();
    int n = graph[0].size();
    int s =0;
    int t =m+n+1;
    vector<vector<int>>mgraph(m+n+2,vector<int>(m+n+2,0));

    for(int i=1;i<=m;i++)
    {
        mgraph[s][i]=1;
    }

    for(int i=1;i<=n;i++)
    {
       mgraph[m+i][t]=1;
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mgraph[i+1][m+j+1] = graph[i][j];
        }
    }
    
    vector<int>parent(m+n+2,-1);

    int max_possible = edmondKarp(mgraph,s,t,parent);

    cout<<"max people: "<<max_possible<<endl;

    for(int i=m+1;i<m+n+1;i++)
    {
        if(parent[i]!=-1)
        cout<<i-m<<"->"<<parent[i]<<endl;
    }
}


int main()
{
    vector<vector<int>>graph={{1,1,0,0},
                              {1,0,1,0},
                              {0,0,1,1},
                              {0,1,0,0}};

    maximum_bipartite(graph);
}

