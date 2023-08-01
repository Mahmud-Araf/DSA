// implementation of tarjan's algorithm to find articulation point

#include <bits/stdc++.h>
using namespace std;

class AP
{
private:
     int time;
     int par;
     int apCount;
     bool *visited;
     int *d;
     int *low;
     bool *isAP;

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
                    dfs(adj, v, time, u);

                    low[u] = min(low[u], low[v]);

                    if (parent != -1 && low[v] >= d[u])
                    {
                         isAP[u] = true;
                    }
               }
               else if (v != parent)
               {
                    low[u] = min(low[u], d[v]);
               }
          }

          if (parent == -1 && children > 1)
          {
               isAP[u] = true;
          }
     }

public:
     int n;
     AP(int n)
     {
          this->n = n;
          time = 0;
          par = -1;
          apCount = 0;
          visited = new bool[n];
          d = new int[n];
          low = new int[n];
          isAP = new bool[n];
     }

     void findAP(vector<vector<int>> &adj)
     {
          for (int i = 0; i < n; i++)
          {
               visited[i] = false;
               d[i] = 0;
               low[i] = 0;
               isAP[i] = false;
          }

          for (int i = 0; i < n; i++)
          {
               if (!visited[i])
               {
                    dfs(adj, i, time, par);
               }
          }
     }

     int getAPcount()
     {
          for(int i=0;i<n;i++)
          {
            if(isAP[i])
            {
                apCount++;
            }
          }

          return apCount;
     }

     void printAP()
     {
          for (int i = 0; i < n; i++)
          {
               if (isAP[i])
               {
                    cout << i << " ";
               }
          }
          cout << endl;
     }
};

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    cout << "Articulation points in first graph \n";
    int n = 5;
    AP ap1 = AP(n);
    vector<vector<int>> adj1(n);
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    ap1.findAP(adj1);
    ap1.printAP();
    cout<<"Total articulation point: "<<ap1.getAPcount()<<endl;

    cout << "\nArticulation points in second graph \n";
    n = 4;
    AP ap2 = AP(n);
    vector<vector<int>> adj2(n);
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    ap2.findAP(adj2);
    ap2.printAP();
    cout<<"Total articulation point: "<<ap2.getAPcount()<<endl;


    cout << "\nArticulation points in third graph \n";
    n = 7;
    AP ap3 = AP(n);
    vector<vector<int>> adj3(n);
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    ap3.findAP(adj3);
    ap3.printAP();
    cout<<"Total articulation point: "<<ap3.getAPcount()<<endl;


    cout << "\nArticulation points in fourth graph \n";
    n = 5;
    AP ap4 = AP(n);
    vector<vector<int>> adj4(n);
    addEdge(adj4, 0, 1);
    addEdge(adj4, 1, 2);
    addEdge(adj4, 2, 3);
    addEdge(adj4, 3, 4);
    addEdge(adj4, 0, 4);
    ap4.findAP(adj4);
    ap4.printAP();
    cout<<"Total articulation point: "<<ap4.getAPcount()<<endl;


    return 0;
}