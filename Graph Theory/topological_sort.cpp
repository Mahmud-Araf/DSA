//implementation of topological sort using bfs
#include<bits/stdc++.h>
using namespace std;

void topo_sort(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st)
{
    
    visited[v] = true;

    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            topo_sort(i, adj, visited, st);
        }
    }

    st.push(v);
}

int main()
{
    vector<vector<int>> adj(6);
    vector<bool> visited(6, false);
    stack<int> st;

    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[5].push_back(1);
    adj[5].push_back(0);

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
            topo_sort(i, adj, visited, st);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}