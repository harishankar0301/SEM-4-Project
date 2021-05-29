
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include "graph.h"
using namespace std;

void addbus()
{
    graph g;
    fstream graphin("graph.txt", ios::in | ios::out);
    graphin.seekg(0);
    graphin.read((char *)&g, sizeof(g));
    graphin.close();

    int num_buses;
    cout << "Enter number of buses to add  : ";
    cin >> num_buses;

    int bn, d;
    string s, e;

    fstream fin("bus.txt", ios::in | ios::out | ios::app);
    for (int i = 0; i < num_buses; i++)
    {

        cout << "\n\nEnter Bus Number   : ";
        cin >> bn;
        cout << "Enter starting point   : ";
        cin >> s;
        cout << "Enter ending point     : ";
        cin >> e;
        cout << "Enter distance         : ";
        cin >> d;

        int start, end;
        start = bus::map_citynames1[s];
        end = bus::map_citynames1[e];

        bus b(bn, start, end);
        g.addEdge(start, end, d);
        fin.write((char *)&b, sizeof(b));
    }

    fstream graphOut("graph.txt", ios::out | ios::trunc);
    graphOut.write((char *)&g, sizeof(g));
    graphOut.close();
}

void show()
{
    cout << "************* List of available buses *************" << endl;
    bus b;
    fstream fin("bus.txt", ios::in | ios::out);

    int i = 0;
    fin.seekg(0);
    fin.read((char *)&b, sizeof(b));
    while (!fin.eof())
    {

        cout << "------------------------------" << endl;
        b.show();
        cout << "------------------------------" << endl;
        i++;
        fin.read((char *)&b, sizeof(b));
    }
    cout << "Total  Number of buses is " << i << endl
         << endl;
    fin.close();
}

void initGraph()
{
    std::ifstream cityfile("cities.txt");

    int i = 0;
    int cityno;
    string cityname;
    while (cityfile >> cityno >> cityname)
    {
        i++;
    }
    graph g;
    fstream fin("graph.txt", ios::in | ios::out | ios::trunc);
    fin.seekg(0);
    fin.write((char *)&g, sizeof(g));
    fin.close();
}
