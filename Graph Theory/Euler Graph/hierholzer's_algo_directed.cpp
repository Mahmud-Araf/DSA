// implementation of euler path/circuit using hierholzer's algorithm for directed graphs

#include <bits/stdc++.h>
using namespace std;

class HierholzerA
{
private:
    int n;
    int m;
    vector<int> in;
    vector<int> out;
    vector<vector<int>> adj;
    list<int> path;

    void countInOutDegrees()
    {
        for (int i = 0; i < n; i++)
        {
            for (auto j : adj[i])
            {
                out[i]++;
                in[j]++;
            }
        }
    }

    bool isEulerian()
    {
        int start_nodes = 0;
        int end_nodes = 0;

        for (int i = 0; i < n; i++)
        {
            if (abs(in[i] - out[i]) > 1)
            {
                return false;
            }
            else if ((out[i] - in[i]) == 1)
            {
                start_nodes++;
            }
            else if ((in[i] - out[i]) == 1)
            {
                end_nodes++;
            }
        }

        if ((start_nodes == 0 and end_nodes == 0) || (start_nodes == 1 and end_nodes == 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int findStartNode()
    {
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (out[i] - in[i] == 1)
            {
                return i;
            }
            if (out[i] > 0)
            {
                start = i;
            }
        }

        return start;
    }

    void dfs(int at)
    {
        while (out[at] != 0)
        {
            int next = adj[at][--out[at]];

            dfs(next);
        }
        path.emplace_front(at);
    }

public:
    HierholzerA(int n, int m,vector<vector<int>>adj)
    {
        this->n = n;
        this->m = m;
        in.resize(n, 0);
        out.resize(n, 0);
        this->adj = adj;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void printEpath()
    {
        countInOutDegrees();

        if (!isEulerian())
        {
            cout << "No Eulerian Path/Circuit exists" << endl;
            return;
        }

        dfs(findStartNode());

        if (path.size() == m + 1)
        {
            while (path.size()>1)
            {
                cout << path.front() << "->";
                path.pop_front();
            }
            cout<<path.front()<< endl;
        }
        else
        {
            cout << "No Eulerian Path/Circuit exists" << endl;
        }
    }
};

int main()
{
    vector< vector<int> > adj1, adj2;
 
    // Input Graph 1
    adj1.resize(3);
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    HierholzerA h1 = HierholzerA(3,3,adj1);
    h1.printEpath();
    
    //Input Graph 2
    adj2.resize(7);
    adj2[0].push_back(1);
    adj2[0].push_back(6);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[6].push_back(4);
    HierholzerA h2 = HierholzerA(7,10,adj2);
    h2.printEpath();
    
}