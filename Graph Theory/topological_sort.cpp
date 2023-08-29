//implementation of topological sort using bfs
#include<bits/stdc++.h>
using namespace std;

bool topo_sort(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, vector<int>& parent) {
    visited[v] = true;

    for (auto i : adj[v]) {
        if (!visited[i]) {
            parent[i] = v;
            if (!topo_sort(i, adj, visited, st, parent)) {
                return false;
            }
        } else if (i != parent[v] && visited[i]) {
            return false;
        }
    }

    st.push(v);
    return true;
}


int main()
{
    vector<vector<int>> adj(6);
    vector<bool> visited(6, false);
    stack<int> st;
    vector<int> parent(6, -1);

    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[5].push_back(1);
    adj[5].push_back(0);

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            parent[i]=i;
            if(!topo_sort(i, adj, visited, st,parent))
            {
                cout << "Not a DAG" << endl;
                return 0;
            }
        }

            
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}