#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <limits>
#include "bus.h"
#define N 5
using namespace std;
class graph
{
    int v;
    int adj[N][N];

public:
    graph()
    {

        v = N;
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

    void printGraph()
    {
        cout << "\nAdjacency matrix \n";
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void shortestRoute()
    {
        //Initialize the city names
        system("clear");
        bus::init_citynames();
        bus::init_bus_no();

        string loc_str;
        cout << "Select your location: " << endl;
        cin >> loc_str;

        string dest_str;
        cout << "Select your destination: " << endl;
        cin >> dest_str;

        int loc = bus::map_citynames1[loc_str];
        int dest = bus::map_citynames1[dest_str];



        int max_int = numeric_limits<int>::max();
        int min_dist;  // Keeps track of minimum dist. in dv_table
        int ver;       // Keeps track of the unknown vertex with min. dist. in dv_table
        int addi_dist; // Additional distance from location to add along with weight of the new edge

        int path[N][N - 1];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++)
            {
                path[i][j] = -1;
            }

        // In every row: first entry - vertex, second entry - status
        int known_table[N][2] = {{0, 'F'}, {1, 'F'}, {2, 'F'}, {3, 'F'}, {4, 'F'}};
        int pv_table[N][2] = {{0, -1}, {1, -1}, {2, -1}, {3, -1}, {4, -1}};
        int dv_table[N][2] = {{0, max_int}, {1, max_int}, {2, max_int}, {3, max_int}, {4, max_int}};

        dv_table[loc][1] = min_dist = 0;
        ver = loc;

        while (known_table[dest][1] == 'F')
        {

            //Finding minimum unknown distance in dv_table
            for (int i = 0; i < N; i++)
            {
                if (known_table[i][1] == 'F' && min_dist > dv_table[i][1])
                {
                    min_dist = dv_table[i][1];
                    ver = i;
                }
            }

            //Making vertex with smallest unknown distance as known
            known_table[ver][1] = 'T';

            //Calculating distance for adjacent vertices of ver
            for (int j = 0; j < N; j++)
            {
                if (adj[ver][j] != 0)
                {

                    if (pv_table[ver][1] == -1)
                    {
                        addi_dist = 0;
                    }
                    else
                    {
                        addi_dist = dv_table[ver][1];
                    }

                    if (adj[ver][j] + addi_dist < dv_table[j][1] && known_table[j][1] == 'F')
                    {

                        dv_table[j][1] = adj[ver][j] + addi_dist;
                        pv_table[j][1] = ver;

                        path[j][0] = ver;

                        for (int k = 1; path[j][k - 1] != -1; k++)
                        {
                            path[j][k] = path[ver][k - 1];
                        }
                    }
                }
            }

            min_dist = numeric_limits<int>::max();
        }

        string city;
        cout << "To get to " << dest_str << " from " << loc_str << " in shortest distance possible, you would have to take buses between: " << endl;

        int j = 0;
        while (path[dest][j] != -1 && j < N - 1)
        {
            j++;
        }

        string tmp;
        while (j >= 0)
        {
            city = bus::map_citynames2[path[dest][j]];
            if (tmp.length() > 2 && city.length() > 2)
            {
                pair<string, string> p(tmp, city);
                cout << tmp << " to " << city << " Bus No: " << bus::map_bus_no[p] << endl;
            }
            tmp = city;
            j--;
        }

        pair<string, string> p(tmp, dest_str);
        cout << tmp << " to " << dest_str << " Bus No: " << bus::map_bus_no[p] << endl;

        cout << "\nTotal Distance  is " << dv_table[dest][1] << "km" << endl << endl;
    }
};