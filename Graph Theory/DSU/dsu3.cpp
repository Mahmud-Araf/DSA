// implementation of dsu using array and union by size

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int n;       // total node number
    int *parent; // for storing root
    int *size;   // for storing node number

public:
    DSU(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        size = new int[n + 1];

        makeset();
    }

    void makeset()
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) // find function with path compression
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    

    void _union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

int main()
{
    int n = 6;
    DSU dsu(n);

    dsu._union(1, 2);
    dsu._union(2, 3);
    dsu._union(4, 5);
    dsu._union(1, 5);

    cout << "Parent array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    return 0;
}