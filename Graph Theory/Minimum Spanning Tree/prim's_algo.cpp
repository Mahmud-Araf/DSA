// implementation of prim's algorithm to find mst

#include <bits/stdc++.h>
using namespace std;

class MST
{
private:
    int n;
    int cost;
    int *parent;
    bool *mstSet;
    int *key;

    int minKey()
    {
        int min = INT_MAX, min_index;
        for (int i = 0; i < n; i++)
        {
            if (mstSet[i] == false && key[i] < min)
            {
                min = key[i], min_index = i;
            }
        }

        return min_index;
    }

    void printMST(vector<vector<int>> &weight)
    {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < n; i++)
        {
            cout << parent[i] << "-" << i << " \t"
                 << weight[i][parent[i]] << endl;
            cost+=weight[i][parent[i]];
        }

        cout << "Minimum Cost Spanning Tree: " << cost << endl;
    }

public:
    MST(int n)
    {
        this->n = n;
        cost=0;
        parent = new int[n],
        mstSet = new bool[n],
        key = new int[n];
    }

    void primMST(vector<vector<int>> &weight)
    {
        for (int i = 0; i < n; i++)
        {
            key[i] = INT_MAX,
            mstSet[i] = false,
            parent[i] = -1;
        }

        key[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int u = minKey();
            mstSet[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (weight[u][v] && !mstSet[v] && weight[u][v] < key[v])
                {
                    parent[v] = u,
                    key[v] = weight[u][v];
                }
            }
        }

        printMST(weight);
    }
};

int main()
{
    vector<vector<int>> weight = {{0, 2, 0, 6, 0},
                                  {2, 0, 3, 8, 5},
                                  {0, 3, 0, 0, 7},
                                  {6, 8, 0, 0, 9},
                                  {0, 5, 7, 9, 0}};
    
    MST mst = MST(5);

    mst.primMST(weight);

    return 0;
}