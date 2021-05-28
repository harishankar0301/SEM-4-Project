#include <iostream>
#include "vector"
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    int adj[5][5];

public:
    graph()
    {

        v = 5;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v, int d)
    {
        adj[u][v] = d;
        adj[v][u] = d;
    }
    /*
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
    */
    void printGraph()
    {
        cout << "\nAdjacency matrix \n";
        cout << "VVV: " << v << endl;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};