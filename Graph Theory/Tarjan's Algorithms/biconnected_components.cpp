// implementation of determining biconnected components using tarjan's algorithm

#include <bits/stdc++.h>
using namespace std;

class BCC
{
private:
    int time;
    int par;
    int bccCount;
    bool *visited;
    int *d;
    int *low;
    stack<pair<int, int>> st;

    void dfs(vector<vector<int>> &adj, int u, int &time, int parent)
    {
        int children = 0;
        visited[u] = true;
        d[u] = low[u] = ++time;

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                children++;

                st.push({u, v});

                dfs(adj, v, time, u);

                low[u] = min(low[u], low[v]);

                if ((d[u]>1 && low[v] >= d[u]) || (d[u]==1 && children > 1))
                {
                    while (st.top().first != u || st.top().second != v)
                    {
                        cout << st.top().first << "--" << st.top().second << " ";
                        st.pop();
                    }
                    cout << st.top().first << "--" << st.top().second << " ";
                    st.pop();
                    cout << endl;
                    bccCount++;
                }
            }
            else if (v != parent)
            {
                low[u] = min(low[u], d[v]);
                if (d[v] < d[u])
                {
                    st.push({u, v});
                }
            }
        }
    }

public:
    int n;
    BCC(int n)
    {
        this->n = n;
        time = 0;
        par = -1;
        bccCount = 0;
        visited = new bool[n];
        d = new int[n];
        low = new int[n];
    }

    int getBCCs()
    {
        return bccCount;
    }

    void printBCC(vector<vector<int>> &adj)
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            d[i] = 0;
            low[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, time, par);
            }
        }

        int i = 0;
        while (st.size() > 0)
        {
            i = 1;
            cout << st.top().first << "--" << st.top().second << " ";
            st.pop();
        }

        if (i == 1)
        {
            cout << endl;
            bccCount++;
        }
    }
};

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    BCC bcc = BCC(12);
    vector<vector<int>> adj(12);

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 3);
    addEdge(adj, 1, 5);
    addEdge(adj, 5, 1);
    addEdge(adj, 0, 6);
    addEdge(adj, 6, 0);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 5);
    addEdge(adj, 5, 8);
    addEdge(adj, 8, 5);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 7);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 8);
    addEdge(adj, 10, 11);
    addEdge(adj, 11, 10);

    bcc.printBCC(adj);

    cout<<"Total BCCS: "<<bcc.getBCCs()<<endl;
}