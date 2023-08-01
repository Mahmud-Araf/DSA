// implementation of calculating bridge using tarjan's algorithm

#include <bits/stdc++.h>
using namespace std;

class Bridge
{
private:
    int time;
    int par;
    int bridgeCount;
    bool *visited;
    int *d;
    int *low;

    void dfs(vector<vector<int>> &adj, int u, int &time, int parent)
    {
        visited[u] = true;
        d[u] = low[u] = ++time;

        for (auto v : adj[u])
        {
            if (v == parent)
                continue;

            if (visited[v])
            {
                low[u] = min(low[u], d[v]);
            }
            else
            {
                dfs(adj, v, time, u);

                low[u] = min(low[u], low[v]);

                if (low[v] > d[u])
                {
                    cout << u << " " << v << endl;
                    bridgeCount++;
                }
            }
        }
    }

public:
    int n;
    Bridge(int n)
    {
        this->n = n;
        time = 0;
        par = -1;
        bridgeCount = 0;
        visited = new bool[n];
        d = new int[n];
        low = new int[n];
    }

    int getBridgeCount()
    {
        return bridgeCount;
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

        cout << "Total Bridges are: " << getBridgeCount() << endl;
    }
};

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    cout << "\nBridges in first graph: \n";
    vector<vector<int>> adj1(5);

    Bridge b = Bridge(5);
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    b.printBCC(adj1);

    cout << "\nBridges in second graph: \n";
    vector<vector<int>> adj2(4);

    b = Bridge(4);
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    b.printBCC(adj2);

    cout <<"\nBridges in third graph: \n";
    vector<vector<int>> adj3(7);

    b = Bridge(7);
    addEdge(adj3,0, 1);
    addEdge(adj3,1, 2);
    addEdge(adj3,2, 0);
    addEdge(adj3,1, 3);
    addEdge(adj3,1, 4);
    addEdge(adj3,1, 6);
    addEdge(adj3,3, 5);
    addEdge(adj3,4, 5);
    b.printBCC(adj3);
}
