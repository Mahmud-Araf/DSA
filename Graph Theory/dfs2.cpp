// implementation of dfs using coloring

#include<bits/stdc++.h>
using namespace std;


enum Color {
    WHITE,  // Unvisited
    GRAY,   // Visited but not fully explored
    BLACK   // Fully explored
};

void dfs(int p, int adj[][1000], Color colors[])
{
    colors[p] = GRAY;  // Mark the current node as visited but not fully explored

    for (auto i : adj[p])
    {
        if (colors[i] == WHITE)  // Check if the neighbor is unvisited
        {
            dfs(i, adj, colors);
        }
    }

    colors[p] = BLACK;  // Mark the current node as fully explored
}