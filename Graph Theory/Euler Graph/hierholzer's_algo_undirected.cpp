// implementation of euler path/circuit using hierholzer's algorithm for undirected graphs

#include <bits/stdc++.h>
using namespace std;

class HierholzerA
{
private:
    int n;
    int m;
    vector<int> degree;
    vector<multiset<int>> adj;
    list<int> path;

    void countDegrees()
    {
        for (int i = 0; i < n; i++)
        {
            degree[i] = adj[i].size();
        }
    }

    bool isEulerian()
    {
        int count =0;

        for (int i = 0; i < n; i++)
        {
            if (degree[i] % 2 != 0)
            {
                count++;
            }
        }
        
        if(count==0 || count==2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void dfs(int at)
    {
        while (!adj[at].empty())
        {
            int next = *adj[at].begin();
            adj[at].erase(adj[at].begin());
            adj[next].erase(adj[next].find(at));

            dfs(next);
        }
        path.emplace_front(at);
    }

public:
    HierholzerA(int n, int m, vector<vector<int>> adjList)
    {
        this->n = n;
        this->m = m;
        degree.resize(n, 0);
        adj.resize(n);

        for (int i = 0; i < n; i++)
        {
            for (int v : adjList[i])
            {
                adj[i].insert(v);
            }
        }
    }
    void printEpath()
    {
        countDegrees();

        if (!isEulerian())
        {
            cout << "No Eulerian Path/Circuit exists" << '\n';
            return;
        }

        dfs(0);

        if (path.size() == m + 1)
        {
            while (!path.empty())
            {
                cout << path.front() << " ";
                path.pop_front();
            }
            cout << '\n';
        }
        else
        {
            cout << "No Eulerian Path/Circuit exists" << '\n';
        }
    }
};
