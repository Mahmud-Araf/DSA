// implementation of strongly connected components

#include <bits/stdc++.h>
using namespace std;

class scc
{
private:
    void dfs1(int p, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[p] = 1;
        for (auto i : adj[p])
        {
            if (!visited[i])
            {
                dfs1(i, adj, visited, st);
            }
        }

        st.push(p);
    }

    void dfs2(int p, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[p] = 1;

        cout << p << " ";

        for (auto i : adj[p])
        {
            if (!visited[i])
            {
                dfs2(i, adj, visited);
            }
        }
    }

    vector<vector<int>> getTranspose(vector<vector<int>> adj1)
    {
        vector<vector<int>> adj2(adj1.size());
        for (int i = 0; i < adj1.size(); i++)
        {
            for (auto j : adj1[i])
            {
                adj2[j].push_back(i);
            }
        }

        return adj2;
    }

public:
    void printSCC(vector<vector<int>>&adj)
    {
        vector<int>visited(adj.size(),0);

        stack<int>st;

        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                dfs1(i,adj,visited,st);
            }
        }

        vector<vector<int>>adjT=getTranspose(adj);

        visited.assign(adj.size(),0);

        while(!st.empty())
        {
            int f=st.top();
            st.pop();

            if(!visited[f])
            {
                dfs2(f,adjT,visited);
                cout<<endl;
            }
        }
    }


};

int main()
{
         vector<vector<int>>adj(5);
         adj[1].push_back(0);
         adj[0].push_back(2);
         adj[2].push_back(1);
         adj[0].push_back(3);
         adj[3].push_back(4);

         scc test = scc();

         test.printSCC(adj);
}