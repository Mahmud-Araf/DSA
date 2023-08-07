// implementation of kruskal's algorithm to find mst using dsu

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class MST
{
private:
    int n;
    vector<vector<int>> adj;

public:
    MST(int n)
    {
        this->n = n;
    }

    void addEdge(int x, int y, int w)
    {
        adj.push_back({w, x, y});
    }

    void printMST()
    {
        sort(adj.begin(), adj.end());

        DSU dsu(n);

        int cost = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;

        for (auto edge : adj)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (dsu.find(x) != dsu.find(y))
            {
                dsu.unite(x, y);

                cost += w;

                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }

        cout << "Minimum Cost Spanning Tree: " << cost << endl;
    }
};

int main()
{
    MST mst(4);
    mst.addEdge(0, 1, 10);
    mst.addEdge(1, 3, 15);
    mst.addEdge(2, 3, 4);
    mst.addEdge(2, 0, 6);
    mst.addEdge(0, 3, 5);

    // Function call
    mst.printMST();

    return 0;
}