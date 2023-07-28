// implementation of bfs 
#include<bits/stdc++.h>
using namespace std;

void bfs(int p, int adj[][1000],int visited[],int len[])
{
    queue<int>q;
    q.push(p);
    visited[p]=1;
    len[p]=0;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        
        for(auto i:adj[f])
        {
            if(!visited[i])
            {
                visited[i]=1;
                len[i]=len[f]+1;
                q.push(i);
            }
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
    int len[1000];

    // initialize visited and len arrays to all -1's
    for (int i = 0; i < n; i++) {
        visited[i] = -1;
        len[i] = -1;
    }

    bfs(0, adj, visited, len);

    // print out visited and len arrays to check if BFS was successful
    for (int i = 0; i < n; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << len[i] << " ";
    }
    cout << endl;

    return 0;
}