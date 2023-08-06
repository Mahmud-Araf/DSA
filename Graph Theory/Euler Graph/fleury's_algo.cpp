// implementation of euler path/circuit using fleury's algorithm

#include <bits/stdc++.h>
using namespace std;

class FleuryA
{

private:
    int n;
    vector<vector<int>> adj;
    vector<int> visited;

    int dfsCount(int p)
    {
        visited[p] = 1;
        int count = 1;

        for (auto i : adj[p])
        {
            if (i != -1 && !visited[i])
            {
                count += dfsCount(i);
            }
        }
        return count;
    }

    void removeEdge(int u, int v)
    {
        auto iu = find(adj[u].begin(), adj[u].end(), v);
        auto iv = find(adj[v].begin(), adj[v].end(), u);

        if (iu != adj[u].end())
            *iu = -1;

        if (iv != adj[v].end())
            *iv = -1;
    }

    bool isNotBridge(int u, int v)
    {
        int count = 0;

        for (auto i : adj[u])
        {
            if (i != -1)
                count++;
        }

        if (count == 1)
        {
            return true;
        }

        visited.assign(n,false);

        int count1 = dfsCount(u);

        if (count1 == 1)
        {
            return false;
        }

        removeEdge(u, v);

        visited.assign(n,false);

        int count2 = dfsCount(u);

        addEdge(u, v);

        if (count1 > count2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void printEulerUntil(int u)
    {

        for (auto v : adj[u])
        {
            if (v != -1 && isNotBridge(u, v))
            {
                cout << u << "-" << v << " ";
                removeEdge(u, v);
                printEulerUntil(v);
            }
        }
    }

public:
    FleuryA(int n)
    {
        this->n = n;
        adj.resize(n);
        visited.resize(n, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printEulerPath()
    {
        int u = -1;
        int count = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[i].size() & 1)
            {
                if (u == -1)
                {
                    u = i;
                }
                count++;
            }
        }

        if (u == -1)
        {
            u = 0;
        }

        if (count == 0 || count == 2)
        {
            printEulerUntil(u);
            cout << endl;
        }
        else
        {
            cout << "Euler Path doesn't exist" << endl;
        }
    }
};

int main()
{
    FleuryA fa1(4);
    fa1.addEdge(0, 1);
    fa1.addEdge(0, 2);
    fa1.addEdge(1, 2);
    fa1.addEdge(2, 3);
    fa1.printEulerPath();

    FleuryA fa2(3);
    fa2.addEdge(0, 1);
    fa2.addEdge(1, 2);
    fa2.addEdge(2, 0);
    fa2.printEulerPath();

    FleuryA fa3(5);
    fa3.addEdge(1, 0);
    fa3.addEdge(0, 2);
    fa3.addEdge(2, 1);
    fa3.addEdge(0, 3);
    fa3.addEdge(3, 4);
    fa3.addEdge(3, 2);
    fa3.addEdge(3, 1);
    fa3.addEdge(2, 4);
    fa3.printEulerPath();

    //output
    // 2-0  0-1  1-2  2-3  
    // 0-1  1-2  2-0  
    // 0-1  1-2  2-0  0-3  3-4  4-2  2-3  3-1 

    return 0;
}