// implementation of tarjan's algorithm to find scc in linear time complexity

#include <bits/stdc++.h>
using namespace std;

#define UNVISITED -1

class SCC
{
private:
    int id;
    int sccCount;

    int *ids;
    int *lows;
    bool *onStack;
    stack<int> st;
    vector<vector<int>> adj;
    vector<vector<int>> sccs;

    void dfs(int at)
    {
        st.push(at);
        onStack[at] = true;
        ids[at] = lows[at] = ++id;

        for (auto to : adj[at])
        {
            if (ids[to] == UNVISITED)
            {
                dfs(to);
            }
            if (onStack[to])
            {
                lows[at] = min(lows[at], lows[to]);
            }
        }

        if (ids[at] == lows[at])
        {
            int node = -1;
            while (node != at)
            {
                node = st.top();
                st.pop();
                onStack[node] = false;
                lows[node] = ids[at];
                sccs[sccCount].push_back(node);
            }
            sccCount++;
        }
    }

public:
    int nodeN;

    SCC(int n)
    {
        nodeN = n;
        int id = -1;
        sccCount = 0;
        ids = new int[nodeN];
        lows = new int[nodeN];
        onStack = new bool[nodeN];
        sccs.resize(nodeN);
        adj.resize(nodeN);
    }

    int getSccCount()
    {
        return sccCount;
    }

    void findSCC(vector<vector<int>> tadj)
    {
        adj = tadj;

        for (int i = 0; i < nodeN; i++)
        {
            ids[i] = UNVISITED;
            lows[i] = 0;
            onStack[i] = false;
        }

        for (int i = 0; i < nodeN; i++)
        {
            if (ids[i] == UNVISITED)
            {
                dfs(i);
            }
        }
    }

    void printSCC()
    {
        for (int i = 0; i < sccCount; i++)
        {
            for (auto j : sccs[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> adj(5);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    SCC tg = SCC(5);

    tg.findSCC(adj);

    cout << tg.getSccCount() << endl;

    tg.printSCC();
}
