#include <iostream>
#include "vector"
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int v, e;
    vector<vector<int>> adj;

public:
    graph(int nv, int e) : adj(nv, vector<int>(nv, 0))
    {
        v = nv;
        this->e = e;
    }
    void get_graph()
    {
        for (int i = 0; i < e; i++)
        {
            int u, v,d;
            cin >> u >> v>>d;
            adj[u][v] = d;
            adj[v][u] = d;
        }
    }
    void printGraph()
    {
        cout << "\nAdjacency matrix \n";
        for (int i = 0; i < v; ++i)
        {

            for (auto x : adj[i])
                cout << x << " ";
            printf("\n");
        }
    }
};